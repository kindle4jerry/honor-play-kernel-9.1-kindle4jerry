#ifndef _SMBPW_CHARCNV_H_
#define _SMBPW_CHARCNV_H_

extern void load_case_tables_smbpw(void);
extern size_t strlen_w_smbpw(const smb_ucs2_t *src);
extern void init_valid_table_smbpw(void);
extern void init_iconv_smbpw(void);
extern void lazy_initialize_conv_smbpw(void);
extern char lp_failed_convert_char_smbpw(void);
extern size_t ucs2_align_smbpw(const void *base_ptr, const void *p, int flags);
extern size_t convert_string_smbpw(charset_t from, charset_t to,
		      void const *src, size_t srclen, 
		      void *dest, size_t destlen, bool allow_bad_conv);
extern smb_ucs2_t toupper_w_smbpw(smb_ucs2_t val);
extern smb_ucs2_t tolower_w_smbpw( smb_ucs2_t val );
extern int tolower_ascii_smbpw(int c);
extern void strlower_m_smbpw(char *s);
extern void strupper_m_smbpw(char *s);
extern size_t push_ucs2_smbpw(const void *base_ptr, void *dest, const char *src, size_t dest_len, int flags);
extern size_t push_ascii_smbpw(void *dest, const char *src, size_t dest_len, int flags);
#endif


