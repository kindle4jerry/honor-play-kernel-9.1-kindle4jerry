
#include "fsck.h"
#include <libgen.h>
#include <dirent.h>

#include "oem_param.h"
#include "securec.h"

#ifdef HW_F2FS_IMG_OEM 
#define MAX_PATH        128
#define MAX_FILE        256
#define PARSED_INIT     0
#define PARSED_FOUND    1
#define PARSED_NONE     2
#define LINE_MAX_LENGTH 1024
#define DELIM_FLAG      "/\r\n"

//used for cmd -P param
static char *g_path_relative[MAX_PATH];
static int g_total_path_count;
//used for cmd -F param
static char *g_full_path_file[MAX_FILE][MAX_PATH];
static int g_total_file_path_count[MAX_FILE];
static char g_file_path_pass[LINE_MAX_LENGTH];
static int g_max_step_length;
static int g_total_file_count;
//used for both cmd -P && -F
static int g_path_index;

/*******************************************************
*FunctionNmae:  set_token_string
*Description :  set a string parsed by strtok to target
*Parameters: index: position in target
             value: string input to target
             target: dest to save string
*return value: 0 success
              1 error
********************************************************/
static int set_token_string(int index, char* value, char **target)
{
	char *newstring = NULL;
	int buflen = 0;

	if (NULL == value || (value && 0 == strlen(value)))
	{
		printf("input param error\n");
		return 1;
	}
	buflen = (int)strlen(value) + 1;
	newstring = malloc(buflen);
	if (NULL == newstring)
	{
		printf("malloc mem failed\n");
		return 1;
	}

	if(EOK != memset_s(newstring, buflen, 0, buflen))
	{
		printf("memset_s maybe error\n");
	}
	if (EOK != memcpy_s(newstring, buflen, value, buflen - 1))
	{
		printf("memcpy_s maybe error\n");
	}
	target[index] = newstring;

	return 0;
}

/*******************************************************
*FunctionNmae:  release_special_config_mem
*Description :  release mem used for sparse special config
*Parameters: none
*return value: none
********************************************************/
void release_special_config_mem(void)
{
	int i = 0;
	if (g_total_path_count > 0)
	{
		for (i = 0; i < g_total_path_count; i++)
		{
			if (g_path_relative[i])
			{
				free(g_path_relative[i]);
				g_path_relative[i] = NULL;
			}
		}
	}

	if (g_total_file_count > 0)
	{
		int nstr = 0;
		int j = 0;
		for (i=0; i < g_total_file_count; i++)
		{
			nstr = g_total_file_path_count[i];
			for (j = 0; j < nstr; j++)
			{
				if (g_full_path_file[i][j])
				{
					free(g_full_path_file[i][j]);
					g_full_path_file[i][j] = NULL;
				}
			}
		}
	}
	//free the mem for config file
	if (NULL != c.target_special_file)
	{
		free(c.target_special_file);
		c.target_special_file = NULL;
	}
}

/*******************************************************
*FunctionNmae:  parse_path_string
*Description :  parsed input string with delim and store result to output
*Parameters: inputstr: input string
             output_target: target to store the parse result
             delim: flag of input to parse
*return value: parsed output count of result
********************************************************/
static int parse_path_string(char *inputstr, char **output_target, const char* deli)
{
	int outputcount = 0;
	int countno = 0;

	if (inputstr)
	{
		char *token = NULL;
		char *nextoken = NULL;
		char *pathbuf = NULL;
		int  pathlen = 0;

		pathlen = (int)strlen(inputstr);
		pathbuf = malloc(pathlen + 1);
		if (pathbuf)
		{
			int idx = 0;
			if (EOK != memset_s(pathbuf, pathlen + 1, 0, pathlen + 1))
			{
				printf("memset_s maybe error\n");
			}
			if (EOK != memcpy_s(pathbuf, pathlen + 1, inputstr, pathlen + 1))
			{
				printf("memcpy_s maybe error\n");
			}
			token = strtok_s(pathbuf, deli, &nextoken);
			while (token)
			{
				if (set_token_string(idx++, token, output_target))
				{
					countno = idx;
					idx = 0;
					printf("ERROR: failed when set token to path relative!!!!!!!\n");
					break;
				}

				token = strtok_s(NULL, deli , &nextoken);
				if (idx == MAX_PATH && token)
				{
					countno = idx;
					idx = 0;
					printf("###########ERROR: path step is more than %d deep!!!!!!###############\n", MAX_PATH);
					break;
				}
			}
			free(pathbuf);
			outputcount = idx;
		}
		else
		{
			printf("ERROR: malloc mem failed when parse the relative path\n");
			outputcount = 0;
		}
	}
	
	if (0 != countno && 0 == outputcount)
	{
		int j = 0;
		for(j = 0; j < countno; j++)
		{
			free(output_target[j]);
			output_target[j] = NULL;
		}
	}

	return outputcount;
}

/*******************************************************
*FunctionNmae:  parse_input_relative_path
*Description :  parse the relative input path for create image
*Parameters: none
*return value: none
********************************************************/
static void parse_input_relative_path(void)
{
	g_total_path_count = parse_path_string(c.target_special_dir, g_path_relative, DELIM_FLAG);
}

/*******************************************************
*FunctionNmae:  parse_input_full_path_file
*Description :  parse the input file config for create image
*Parameters: none
*return value: none
********************************************************/
static void parse_input_full_path_file(void)
{
	FILE* spf = fopen(c.target_special_file, "r");
	if (spf)
	{
		char tmpbuf[LINE_MAX_LENGTH] = {0};
		int filecount = 0;
		int nret = 0;

		while(!feof(spf))
		{
			if (EOK != memset_s(tmpbuf, LINE_MAX_LENGTH, 0, LINE_MAX_LENGTH))
			{
				printf("memset_s maybe error");
			}
			if (fgets(tmpbuf, LINE_MAX_LENGTH, spf))
			{
				printf("get config line: %s\n", tmpbuf);
				nret = parse_path_string(tmpbuf, g_full_path_file[filecount], DELIM_FLAG);
				if (nret > 0)
				{
					g_total_file_path_count[filecount] = nret;
					if (g_max_step_length < nret)
					{
						g_max_step_length = nret;
					}
					filecount++;
				}
			}
			else
			{
				//null terminate line also return null
				if (errno)
				{
					printf("ERROR: read file line error[%s]", strerror(errno));
					filecount = 0;
					break;
				}
			}
		}
		g_total_file_count = filecount;
		fclose(spf);
	}
	else
	{
		printf("ERROR: open file failed[%s]\n", strerror(errno));
	}
}

/*******************************************************
*FunctionNmae:  parse_input_full_path_file
*Description :  parse the input file config for create image
*Parameters: none
*return value: none
********************************************************/
int parse_file_or_path_input()
{
	if (c.target_special_dir && c.target_special_dir[0] != '/')
	{
		parse_input_relative_path();
		return PARSED_FOUND;
	}
	else if (c.target_special_file)
	{
		parse_input_full_path_file();
		return PARSED_FOUND;
	}

	return PARSED_NONE;
}

/*******************************************************
*FunctionNmae:  checkfile_or_path_valid
*Description :  check file scaned whether is specified
*Parameters: cmpfile : input filename to be compare
             pathindex: step count the in file path
*return value: 1 can be copy to image
               0 can not be used
********************************************************/
int checkfile_or_path_valid(const char *cmpfile, int pathindex)
{
	int dirok = 0;
	if (NULL == cmpfile)
	{
		return 1;
	}

	//file config or path config only can set one at the same time
	if(c.target_special_file)
	{
		if (g_total_file_count > 0)
		{
			if (g_path_index < g_max_step_length)
			{
				int i = 0;
				int ncount = 0;

				for (i = 0; i < g_total_file_count; i++)
				{
					ncount = g_total_file_path_count[i];
					//little, then compare the path index value
					if (pathindex < ncount)
					{
						dirok = (!strcmp(cmpfile, g_full_path_file[i][pathindex]));
						if (dirok)
						{
							break;
						}
					}
					//else, compare the path before to confirm whether path is same or not, this used for config path not file
					else
					{
						char *tmpparse[MAX_PATH] = {0};
						int tmpparsecount = 0;

						if (EOK != memset_s(tmpparse, sizeof(char*) * MAX_PATH, 0, sizeof(char*) * MAX_PATH))
						{
							printf("memset_s maybe error\n");
						}
						tmpparsecount = parse_path_string(g_file_path_pass, tmpparse, DELIM_FLAG);
						if (tmpparsecount > ncount)
						{
							int nj = 0;
							for (nj = 0; nj < ncount; nj++)
							{
								dirok = !(strcmp(tmpparse[nj], g_full_path_file[i][nj]));
								if (dirok)
								{
									break;
								}
							}
							//free memory which malloc in function parse_path_string
							for (nj = 0; nj < tmpparsecount; nj++)
							{
								if (tmpparse[nj])
								{
									free(tmpparse[nj]);
									tmpparse[nj] = NULL;
								}
							}
						}
					}
				}
			}
			else
			{
				dirok = 1;
			}
		}
	}
	else
	{
		if (g_total_path_count > 0)
		{
			if (pathindex < g_total_path_count)
			{
				printf("enter compare strings, [%s]\n", g_path_relative[pathindex]);
				dirok = (!strcmp(cmpfile, g_path_relative[pathindex]));
			}
			else
			{
				dirok = 1;
			}
		}
	}
	return dirok;
}

/*******************************************************
*FunctionNmae:  filter_dot
*Description :  . and .. need not to copy and also check our special config,
                check each file&dir whether can be copy to image or not
*Parameters: d : each item of file&dir
*return value: 1 can be copy to image
               0 can not be used
********************************************************/
int filter_dot(const struct dirent *d)
{
	static int parsed;
	int dirok = 0;

	dirok = (strcmp(d->d_name, "..") && strcmp(d->d_name, "."));
	/* if . or .. , just return 
	* if no special config, return result also
	*/
	if (!dirok || (NULL == c.target_special_file && NULL == c.target_special_dir))
	{
		return dirok;
	}

	if (!parsed)
	{
		parsed = parse_file_or_path_input();
	}
	
	if (PARSED_FOUND == parsed)
	{
		dirok = (dirok & checkfile_or_path_valid(d->d_name, g_path_index));
	}

	return dirok;
}

/*******************************************************
*FunctionNmae:  modify_path_index_value
*Description :  modify the path index value,
*Parameters: value : use the value to modify path index
             binit : if true use the value set to path index
                     else use path index add the value
*return value: none
********************************************************/
void modify_path_index_value(int value, int binit)
{
	if (binit)
	{
		g_path_index = value;
	}
	else
	{
		g_path_index += value;
	}
}

/*******************************************************
*FunctionNmae:  modify_path_index_value
*Description :  modify the path index value,
*Parameters: value : use the value to modify path index
             binit : if true use the value set to path index
                     else use path index add the value
*return value: none
********************************************************/
void set_path_passed_for_file(const char* path)
{
	if (EOK != memset_s(g_file_path_pass, LINE_MAX_LENGTH, 0, LINE_MAX_LENGTH))
	{
		printf("WARING: memset_s function maybe error\n");
	}
	if (EOK != strcpy_s(g_file_path_pass, LINE_MAX_LENGTH, path))
	{
		printf("WARING: strcpy_s function maybe error\n");
	}
}
/*
* when set pointer to null, check first to release memory
*/
void set_target_file_path_null(void)
{
	if (NULL != c.target_special_file)
	{
		free(c.target_special_file);
		c.target_special_file = NULL;
	}
}
#endif
