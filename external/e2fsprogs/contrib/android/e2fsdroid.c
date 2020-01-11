#define _GNU_SOURCE

#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <ext2fs/ext2fs.h>

#include "perms.h"
#include "base_fs.h"
#include "block_list.h"
#include "basefs_allocator.h"
#include "create_inode.h"

#ifdef ROFS_OVERLAY
#define SYSTEM_MNT "/system"
#define PRODUCT_MNT "/product"
#define VERSION_MNT "/version"
#define CUST_MNT "/cust"
#define PRELOAD_MNT "/preload"
#define VENDOR_MNT "/vendor"
#define ODM_MNT "/odm"
#define MNT_PREAS  "/preas"
#define VENDOR_SECLABLE "u:object_r:vendor_file:s0"
#define SYSTEM_SECLABLE "u:object_r:system_file:s0"
#ifndef XATTR_SELINUX_SUFFIX
# define XATTR_SELINUX_SUFFIX  "selinux"
#endif
#endif

static char *prog_name = "e2fsdroid";
static char *in_file;
static char *block_list;
static char *basefs_out;
static char *basefs_in;
static char *mountpoint = "";
static time_t fixed_time = -1;
static char *fs_config_file;
static struct selinux_opt seopt_file[8];
static int max_nr_opt = (int)sizeof(seopt_file) / sizeof(seopt_file[0]);
static char *product_out;
static char *src_dir;
static int android_configure;
static int android_sparse_file = 1;
#ifdef HW_FILE_SAVE_NO_SPARSE
#include <securec.h>
#define ADD_THIS_EXT_FILE 1
#define NOT_ADD_EXT_FILE  0
const char *CMD_SPLIT_STRING="/";
const char *no_sparse_file_type[]={"zip", "apk", "jar"};
#define FIXED_EXT_COUNT   ((int)(sizeof(no_sparse_file_type) / sizeof(no_sparse_file_type[0])))
static char *x_cmd_exclude_filetype;
static int no_sparse_file_count=0;
char **no_sparse_file_list=NULL;

/*******************************************************
*FunctionNmae:  find_extfile_infixarray
*Description :  check file whether is inf fix ext array
*Parameters: param: ext file name ready to added to list
*return vale: ADD_THIS_EXT_FILE: can be added
*             NOT_ADD_EXT_FILE:  can not be added
********************************************************/
static int find_extfile_infixarray(const char* filename)
{
	int ext_file_flag = ADD_THIS_EXT_FILE;
	int idex = 0;
	size_t extfnlen = 0;

	if (NULL == filename)
	{
		return NOT_ADD_EXT_FILE;
	}

	extfnlen = strlen(filename);
	if (extfnlen == 0)
	{
		return NOT_ADD_EXT_FILE;
	}
	for(idex=0; idex < FIXED_EXT_COUNT; idex++)
	{
		if (extfnlen != strlen(no_sparse_file_type[idex]))
		{
			continue;
		}
		if (0 == strncmp(filename, no_sparse_file_type[idex], extfnlen))
		{
			ext_file_flag = NOT_ADD_EXT_FILE;
			break;
		}
	}

    return ext_file_flag;
}

/*******************************************************
*FunctionNmae:  get_extfile_count
*Description :  get ext filename count from param string
*Parameters  :  param: cmd ready to be parsed
*return vale :  count of ext filename
********************************************************/
static int get_extfile_count(const char* param)
{
	char *paramstring = NULL;
	char *token = NULL;
	char *nextoken = NULL;
	int countofextname = FIXED_EXT_COUNT;
	int inputlen = 0;

	if (NULL == param)
	{
		return 0;
	}

	inputlen = strlen(param);
	paramstring = (char *)malloc(sizeof(char) * (inputlen + 1));
	if (NULL == paramstring)
	{
		return 0;
	}
	if (EOK != memset_s(paramstring, sizeof(char) * (inputlen + 1),
					   0, sizeof(char) * (inputlen + 1)))
	{
		printf("WARING memset_s function maybe error\n");
	}
	if (EOK != strcpy_s(paramstring, inputlen + 1, param))
	{
		printf("WARING: memset_s function maybe error\n");
	}

	token = strtok_s(paramstring, CMD_SPLIT_STRING, &nextoken);
	while (token)
	{
		if (ADD_THIS_EXT_FILE == find_extfile_infixarray(token))
		{
			countofextname++;
		}
		token = strtok_s(NULL, CMD_SPLIT_STRING, &nextoken);
	}
	free(paramstring);

	return countofextname;
}

/*******************************************************
*FunctionNmae:  copy_str_tonew_addr
*Description :  copy the string to a new addr
*Parameters  :  src_str: string ready to be copy
*return vale :  char* : pointer of new address
********************************************************/
char *copy_str_tonew_addr(char* src_str)
{
	int toklen = 0;
	char *cpytoken = NULL;

	if (NULL == src_str)
	{
		return NULL;
	}

	toklen = strlen(src_str);
	cpytoken = (char *)malloc(sizeof(char) * (toklen + 1));
	if (NULL == cpytoken)
	{
		return NULL;
	}
	if (EOK != memset_s(cpytoken, sizeof(char) * (toklen + 1),
					0, sizeof(char) * (toklen + 1)))
	{
		printf("WARING: memset_s function maybe error\n");
	}
	if (EOK != strcpy_s(cpytoken, toklen + 1, src_str))
	{
		printf("WARING: strcpy_s function maybe error\n");
	}
	return cpytoken;
}

/*******************************************************
*FunctionNmae:  process_extfile_param
*Description :  parse the param string and add to a listm
*               then set the list to misc library
*Parameters  :  param: cmd ready to be parsed
*return vale :  none
********************************************************/
static void process_extfile_param(char* param)
{
	char *token = NULL;
	char *nextoken = NULL;
	int idex = 0;

	no_sparse_file_count = get_extfile_count(param);
	if (no_sparse_file_count < FIXED_EXT_COUNT)
	{
		no_sparse_file_count = FIXED_EXT_COUNT;
	}
	no_sparse_file_list = (char **)malloc(sizeof(char *) * no_sparse_file_count);
	if (NULL == no_sparse_file_list)
	{
		no_sparse_file_count = 0;
		return;
	}
	if (EOK != memset_s(no_sparse_file_list, sizeof(char *) * no_sparse_file_count,
							   0, sizeof(char *) * no_sparse_file_count))
	{
		printf("WARING memset_s function maybe error\n");
	}
	for (idex = 0; idex < FIXED_EXT_COUNT; idex++)
	{
		no_sparse_file_list[idex] = (char *)no_sparse_file_type[idex];
	}

	if (no_sparse_file_count > FIXED_EXT_COUNT)
	{
		token = strtok_s(param, CMD_SPLIT_STRING, &nextoken);
		while (token)
		{
			if (ADD_THIS_EXT_FILE == find_extfile_infixarray(token))
			{
				char *cpy_new_addr = copy_str_tonew_addr(token);

				if (NULL == cpy_new_addr)
				{
					no_sparse_file_count = idex;
					break;
				}
				no_sparse_file_list[idex] = cpy_new_addr;
				idex++;
				if (idex >= no_sparse_file_count)
				{
					break;
				}
			}
			token = strtok_s(NULL, CMD_SPLIT_STRING, &nextoken);
		}
	}

	set_no_sparse_file_list((const char**)no_sparse_file_list, no_sparse_file_count);
}

/*******************************************************
*FunctionNmae:  free_mem_of_extfile_list
*Description :  free the memory for no_sparse_file_list
*Parameters  :  none
*return vale :  none
********************************************************/
static void free_mem_of_extfile_list()
{
	int idex = 0;

	if (0 == no_sparse_file_count || NULL == no_sparse_file_list)
	{
		return;
	}

	for(idex = FIXED_EXT_COUNT; idex < no_sparse_file_count; idex++)
	{
		if (NULL != no_sparse_file_list[idex])
		{
			free(no_sparse_file_list[idex]);
			no_sparse_file_list[idex] = NULL;
		}
	}
	free(no_sparse_file_list);
	no_sparse_file_list = NULL;
}
#endif
static void usage(int ret)
{
	fprintf(stderr, "%s [-B block_list] [-D basefs_out] [-T timestamp]\n"
			"\t[-C fs_config] [-S file_contexts] [-p product_out]\n"
			"\t[-a mountpoint] [-d basefs_in] [-f src_dir] [-e] [-s] image\n",
                prog_name);
	exit(ret);
}

static char *absolute_path(const char *file)
{
	char *ret;
	char cwd[PATH_MAX];

	if (file[0] != '/') {
		if (getcwd(cwd, PATH_MAX) == NULL) {
			fprintf(stderr, "Failed to getcwd\n");
			exit(EXIT_FAILURE);
		}
		ret = malloc(strlen(cwd) + 1 + strlen(file) + 1);
		if (ret)
			sprintf(ret, "%s/%s", cwd, file);
	} else
		ret = strdup(file);
	return ret;
}

int main(int argc, char *argv[])
{
	int c;
	char *p;
	int flags = EXT2_FLAG_RW;
	errcode_t retval;
	io_manager io_mgr;
	ext2_filsys fs = NULL;
	struct fs_ops_callbacks fs_callbacks = { NULL, NULL };
	char *token;
	int nr_opt = 0;
	ext2_ino_t inodes_count;
	ext2_ino_t free_inodes_count;
	blk64_t blocks_count;
	blk64_t free_blocks_count;

	add_error_table(&et_ext2_error_table);

#ifdef HW_FILE_SAVE_NO_SPARSE
	while ((c = getopt (argc, argv, "X:T:C:S:p:a:D:d:B:f:es")) != EOF) {
#else
	while ((c = getopt (argc, argv, "T:C:S:p:a:D:d:B:f:es")) != EOF) {
#endif
		switch (c) {
		case 'T':
			fixed_time = strtoul(optarg, &p, 0);
			android_configure = 1;
			break;
		case 'C':
			fs_config_file = absolute_path(optarg);
			android_configure = 1;
			break;
		case 'S':
			token = strtok(optarg, ",");
			while (token) {
				if (nr_opt == max_nr_opt) {
					fprintf(stderr, "Expected at most %d selinux opts\n",
						max_nr_opt);
					exit(EXIT_FAILURE);
				}
				seopt_file[nr_opt].type = SELABEL_OPT_PATH;
				seopt_file[nr_opt].value = absolute_path(token);
				nr_opt++;
				token = strtok(NULL, ",");
			}
			android_configure = 1;
			break;
		case 'p':
			product_out = absolute_path(optarg);
			break;
		case 'a':
			mountpoint = strdup(optarg);
			break;
		case 'D':
			basefs_out = absolute_path(optarg);
			break;
		case 'd':
			basefs_in = absolute_path(optarg);
			break;
		case 'B':
			block_list = absolute_path(optarg);
			break;
		case 'f':
			src_dir = absolute_path(optarg);
			break;
		case 'e':
			android_sparse_file = 0;
			break;
		case 's':
			flags |= EXT2_FLAG_SHARE_DUP;
			break;
#ifdef HW_FILE_SAVE_NO_SPARSE
		case 'X':
			x_cmd_exclude_filetype = optarg;
			break;
#endif
		default:
			usage(EXIT_FAILURE);
		}
	}
	if (optind >= argc) {
		fprintf(stderr, "Expected filename after options\n");
		exit(EXIT_FAILURE);
	}

	if (android_sparse_file) {
		io_mgr = sparse_io_manager;
		if (asprintf(&in_file, "(%s)", argv[optind]) == -1) {
			fprintf(stderr, "Failed to allocate file name\n");
			exit(EXIT_FAILURE);
		}
	} else {
		io_mgr = unix_io_manager;
		in_file = strdup(argv[optind]);
	}
	retval = ext2fs_open(in_file, flags, 0, 0, io_mgr, &fs);
	if (retval) {
		com_err(prog_name, retval, "while opening file %s\n", in_file);
		return retval;
	}
#ifdef HW_FILE_SAVE_NO_SPARSE
	process_extfile_param(x_cmd_exclude_filetype);
#endif
	if (src_dir) {
		ext2fs_read_bitmaps(fs);
		if (basefs_in) {
			retval = base_fs_alloc_load(fs, basefs_in, mountpoint);
			if (retval) {
				com_err(prog_name, retval, "%s",
				"while reading base_fs file");
			    goto fail_exit;
			}
			fs_callbacks.create_new_inode =
				base_fs_alloc_set_target;
			fs_callbacks.end_create_new_inode =
				base_fs_alloc_unset_target;
		}
		retval = populate_fs2(fs, EXT2_ROOT_INO, src_dir,
				      EXT2_ROOT_INO, &fs_callbacks);
		if (retval) {
			com_err(prog_name, retval, "%s",
			"while populating file system");
		    goto fail_exit;
		}
		if (basefs_in)
			base_fs_alloc_cleanup(fs);
	}

	if (android_configure) {
		retval = android_configure_fs(fs, src_dir, product_out, mountpoint,
			seopt_file, nr_opt, fs_config_file, fixed_time);
		if (retval) {
			com_err(prog_name, retval, "%s",
				"while configuring the file system");
			goto fail_exit;
		}
	}
#ifdef ROFS_OVERLAY
	else {
		if(!strcmp(mountpoint, VENDOR_MNT) || !strcmp(mountpoint, ODM_MNT)) {
			printf("Labeling %s as %s\n", mountpoint, VENDOR_SECLABLE);
			ino_add_xattr(fs, EXT2_ROOT_INO,  "security." XATTR_SELINUX_SUFFIX,
				      VENDOR_SECLABLE, strlen(VENDOR_SECLABLE) + 1);
		} else if (!strcmp(mountpoint, SYSTEM_MNT)  || !strcmp(mountpoint, PRODUCT_MNT) ||
			   !strcmp(mountpoint, VERSION_MNT) || !strcmp(mountpoint, CUST_MNT)    ||
			   !strcmp(mountpoint, PRELOAD_MNT) || !strcmp(mountpoint, MNT_PREAS)){
			printf("Labeling %s as %s\n", mountpoint, SYSTEM_SECLABLE);
			ino_add_xattr(fs, EXT2_ROOT_INO,  "security." XATTR_SELINUX_SUFFIX,
				      SYSTEM_SECLABLE, strlen(SYSTEM_SECLABLE) + 1);
		}
	}
#endif

	if (block_list) {
		retval = fsmap_iter_filsys(fs, &block_list_format, block_list,
					   mountpoint);
		if (retval) {
			com_err(prog_name, retval, "%s",
				"while creating the block_list");
			goto fail_exit;
		}
	}

	if (basefs_out) {
		retval = fsmap_iter_filsys(fs, &base_fs_format,
					   basefs_out, mountpoint);
		if (retval) {
			com_err(prog_name, retval, "%s",
				"while creating the basefs file");
			goto fail_exit;
		}
	}

	inodes_count = fs->super->s_inodes_count;
	free_inodes_count = fs->super->s_free_inodes_count;
	blocks_count = ext2fs_blocks_count(fs->super);
	free_blocks_count = ext2fs_free_blocks_count(fs->super);

#ifdef HW_FILE_SAVE_NO_SPARSE
	free_mem_of_extfile_list();
#endif
	retval = ext2fs_close_free(&fs);
	if (retval) {
		com_err(prog_name, retval, "%s",
				"while writing superblocks");
		exit(1);
	}

	printf("Created filesystem with %u/%u inodes and %llu/%llu blocks\n",
			inodes_count - free_inodes_count, inodes_count,
			blocks_count - free_blocks_count, blocks_count);

	remove_error_table(&et_ext2_error_table);
	return 0;

fail_exit:
#ifdef HW_FILE_SAVE_NO_SPARSE
	free_mem_of_extfile_list();
#endif
	exit(1);
}
