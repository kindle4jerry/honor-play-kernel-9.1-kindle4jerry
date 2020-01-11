#ifndef _SMBPW_ICONV_H_
#define _SMBPW_ICONV_H_

extern NTSTATUS smb_register_charset_smbpw(struct charset_functions *funcs) ;
extern smb_iconv_t smb_iconv_open_smbpw(const char *tocode, const char *fromcode);
extern int smb_iconv_close_smbpw (smb_iconv_t cd);
extern size_t smb_iconv_smbpw(smb_iconv_t cd, 
		 const char **inbuf, size_t *inbytesleft,
		 char **outbuf, size_t *outbytesleft);

#endif



