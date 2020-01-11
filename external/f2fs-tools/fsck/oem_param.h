/**
 * oem_param.h
 */
#ifndef _HW_OEM_PARAM_H_
#define _HW_OEM_PARAM_H_

#ifdef HW_F2FS_IMG_OEM
int parse_file_or_path_input(void);
int checkfile_or_path_valid(const char *cmpfile, int pathindex);
int filter_dot(const struct dirent *d);
void modify_path_index_value(int value, int binit);
void release_special_config_mem();
int get_path_index(void);
void set_path_passed_for_file(const char* path);
void set_target_file_path_null(void);
#endif
#endif /* _HW_OEM_PARAM_H_ */
