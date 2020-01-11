#ifndef _SMBPASSWD_PROC_H_
#define _SMBPASSWD_PROC_H_

#ifdef SMB_ASSERT
#undef SMB_ASSERT
#endif
#define SMB_ASSERT(a) do{if((a)==0) {printf("PANIC: assert failed at %s(%d): %s\n",    __FILE__, __LINE__, #a); exit(0);}}while(0)

#ifdef DEBUG
#undef DEBUG
#endif
#define DEBUG(x,y) do{printf("\nFile:%s(Line:%d):" ,__FILE__, __LINE__);printf(y);}while(0) 


#define SMBPW_ERR(s) do{printf("\nFile:%s(Line:%d):%s\n", __FILE__, __LINE__,s); exit(0);}while(0)

extern NTSTATUS local_password_add(const char *user_name,
				int local_flags,
				const char *new_passwd, 
				char * p_err_str,
				int   ulErrStrSize,
				char * p_msg_str,
				int   ulMsgStrSize);

extern char *smb_strdup(const char *s);
extern char * smb_strcpy(char *dst ,const char *src);
extern void *smb_memcpy(void *dst , const void *src , size_t len);

#endif
