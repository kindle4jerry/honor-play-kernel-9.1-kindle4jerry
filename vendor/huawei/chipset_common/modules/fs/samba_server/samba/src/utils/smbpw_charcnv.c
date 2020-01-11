/*this file added by qichenghong 20091021 for converting charset by smbpasswd */

#include "includes.h"

#ifdef CUT_SMBPASSWD

#include "smbpasswd_proc.h"
//#include "smbpw_iconv.h"
#include "smbpw_charcnv.h"

/**
 * Convert string from one encoding to another, making error checking etc
 * Slow path version - uses (slow) iconv.
 *
 * @param src pointer to source string (multibyte or singlebyte)
 * @param srclen length of the source string in bytes
 * @param dest pointer to destination string (multibyte or singlebyte)
 * @param destlen maximal length allowed for string
 * @param allow_bad_conv determines if a "best effort" conversion is acceptable (never returns errors)
 * @returns the number of bytes occupied in the destination
 *
 * Ensure the srclen contains the terminating zero.
 *
 **/


char toupper_ascii_fast_table[128] = {
	0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf,
	0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
	0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
	0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
	0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f,
	0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f,
	0x60, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f,
	0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f
};

#ifdef toupper_ascii_fast
#undef toupper_ascii_fast
#endif

#define toupper_ascii_fast(c) toupper_ascii_fast_table[(unsigned int)(c)];

static smb_ucs2_t *upcase_table = NULL;
static smb_ucs2_t *lowcase_table = NULL;

static smb_iconv_t conv_handles[NUM_CHARSETS][NUM_CHARSETS];
static bool conv_silent; /* Should we do a debug if the conversion fails ? */
static bool initialized = false;
/**
 * Load or generate the case handling tables.
 *
 * The case tables are defined in UCS2 and don't depend on any
 * configured parameters, so they never need to be reloaded.
 **/

void load_case_tables_smbpw(void)
{
	char *old_locale = NULL, *saved_locale = NULL;
	int i;
#if 0
	upcase_table = (smb_ucs2_t *)map_file(data_path("upcase.dat"),
					      0x20000);
	upcase_table_use_unmap = ( upcase_table != NULL );

	lowcase_table = (smb_ucs2_t *)map_file(data_path("lowcase.dat"),
					       0x20000);

	lowcase_table_use_unmap = ( lowcase_table != NULL );
#endif

#ifdef HAVE_SETLOCALE
	/* Get the name of the current locale.  */
	old_locale = setlocale(LC_ALL, NULL);

	if (old_locale) {
		/* Save it as it is in static storage. */
		saved_locale = smb_strdup(old_locale);
	}

	/* We set back the locale to C to get ASCII-compatible toupper/lower functions. */
	setlocale(LC_ALL, "C");
#endif

	/* we would like Samba to limp along even if these tables are
	   not available */
	if (!upcase_table) {
		//DEBUG(1,("creating lame upcase table\n"));
		upcase_table = (smb_ucs2_t *)malloc(0x20000);
		for (i=0;i<0x10000;i++) {
			smb_ucs2_t v;
			SSVAL(&v, 0, i);
			upcase_table[v] = i;
		}
		for (i=0;i<256;i++) {
			smb_ucs2_t v;
			SSVAL(&v, 0, UCS2_CHAR(i));
			upcase_table[v] = UCS2_CHAR(islower(i)?toupper(i):i);
		}
	}

	if (!lowcase_table) {
		//DEBUG(1,("creating lame lowcase table\n"));
		lowcase_table = (smb_ucs2_t *)malloc(0x20000);
		for (i=0;i<0x10000;i++) {
			smb_ucs2_t v;
			SSVAL(&v, 0, i);
			lowcase_table[v] = i;
		}
		for (i=0;i<256;i++) {
			smb_ucs2_t v;
			SSVAL(&v, 0, UCS2_CHAR(i));
			lowcase_table[v] = UCS2_CHAR(isupper(i)?tolower(i):i);
		}
	}

#ifdef HAVE_SETLOCALE
	/* Restore the old locale. */
	if (saved_locale) {
		setlocale (LC_ALL, saved_locale);
		SAFE_FREE(saved_locale);
	}
#endif
}

/*******************************************************************
 Count the number of characters in a smb_ucs2_t string.
********************************************************************/

size_t strlen_w_smbpw(const smb_ucs2_t *src)
{
	size_t len;
	smb_ucs2_t c;

	for(len = 0; *(COPY_UCS2_CHAR(&c,src)); src++, len++) {
		;
	}

	return len;
}

/**
 * Return the name of a charset to give to iconv().
 **/
static const char *charset_name(charset_t ch)
{
	const char *ret = NULL;

	if (ch == CH_UTF16LE) ret = "UTF-16LE";
	else if (ch == CH_UTF16BE) ret = "UTF-16BE";
	else if (ch == CH_UNIX) ret = DEFAULT_UNIX_CHARSET;
	else if (ch == CH_DOS) ret = DEFAULT_DOS_CHARSET;
	else if (ch == CH_DISPLAY) ret = DEFAULT_DISPLAY_CHARSET;
	else if (ch == CH_UTF8) ret = "UTF8";

#if defined(HAVE_NL_LANGINFO) && defined(CODESET)
	if (ret && !strcmp(ret, "LOCALE")) {
		const char *ln = NULL;

#ifdef HAVE_SETLOCALE
		setlocale(LC_ALL, "");
#endif
		ln = nl_langinfo(CODESET);
		if (ln) {
			/* Check whether the charset name is supported
			   by iconv */
			smb_iconv_t handle = smb_iconv_open_smbpw(ln,"UCS-2LE");
			if (handle == (smb_iconv_t) -1) {
				DEBUG(5,("Locale charset '%s' unsupported, using ASCII instead\n", ln));
				ln = NULL;
			} else {
				DEBUG(5,("Substituting charset '%s' for LOCALE\n", ln));
				smb_iconv_close_smbpw(handle);
			}
		}
		ret = ln;
	}
#endif

	if (!ret || !*ret) ret = "ASCII";
	return ret;
}

static int check_dos_char_slowly_smbpw(smb_ucs2_t c)
{
	char buf[10];
	smb_ucs2_t c2 = 0;
	int len1, len2;

	len1 = convert_string_smbpw(CH_UTF16LE, CH_DOS, &c, 2, buf, sizeof(buf),False);
	if (len1 == 0) {
		return 0;
	}
	len2 = convert_string_smbpw(CH_DOS, CH_UTF16LE, buf, len1, &c2, 2,False);
	if (len2 != 2) {
		return 0;
	}
	return (c == c2);
}



/**
 * Initialize iconv conversion descriptors.
 *
 * This is called the first time it is needed, and also called again
 * every time the configuration is reloaded, because the charset or
 * codepage might have changed.
 **/
void init_iconv_smbpw(void)
{
	int c1, c2;
	bool did_reload = False;

	/* so that charset_name() works we need to get the UNIX<->UCS2 going
	   first */
	if (!conv_handles[CH_UNIX][CH_UTF16LE])
		conv_handles[CH_UNIX][CH_UTF16LE] = smb_iconv_open_smbpw(charset_name(CH_UTF16LE), "ASCII");

	if (!conv_handles[CH_UTF16LE][CH_UNIX])
		conv_handles[CH_UTF16LE][CH_UNIX] = smb_iconv_open_smbpw("ASCII", charset_name(CH_UTF16LE));

	for (c1=0;c1<NUM_CHARSETS;c1++) {
		for (c2=0;c2<NUM_CHARSETS;c2++) {
			const char *n1 = charset_name((charset_t)c1);
			const char *n2 = charset_name((charset_t)c2);
			if (conv_handles[c1][c2] &&
			    strcmp(n1, conv_handles[c1][c2]->from_name) == 0 &&
			    strcmp(n2, conv_handles[c1][c2]->to_name) == 0)
				continue;

			did_reload = True;

			if (conv_handles[c1][c2])
				smb_iconv_close_smbpw(conv_handles[c1][c2]);

			conv_handles[c1][c2] = smb_iconv_open_smbpw(n2,n1);
			if (conv_handles[c1][c2] == (smb_iconv_t)-1) {
				DEBUG(0,("init_iconv: Conversion from %s to %s not supported\n",
					 charset_name((charset_t)c1), charset_name((charset_t)c2)));
				if (c1 != CH_UTF16LE && c1 != CH_UTF16BE) {
					n1 = "ASCII";
				}
				if (c2 != CH_UTF16LE && c2 != CH_UTF16BE) {
					n2 = "ASCII";
				}
				DEBUG(0,("init_iconv: Attempting to replace with conversion from %s to %s\n",
					n1, n2 ));
				conv_handles[c1][c2] = smb_iconv_open_smbpw(n2,n1);
				if (!conv_handles[c1][c2]) {
					DEBUG(0,("init_iconv: Conversion from %s to %s failed", n1, n2));
					SMBPW_ERR("init_iconv: conv_handle initialization failed");
				}
			}
		}
	}

	if (did_reload) {
		/* XXX: Does this really get called every time the dos
		 * codepage changes? */
		/* XXX: Is the did_reload test too strict? */
	/*	conv_silent = True;
		init_valid_table_smbpw();*/
		conv_silent = False;
	}
}

void lazy_initialize_conv_smbpw(void)
{
	if (!initialized) {
		load_case_tables_smbpw();
		init_iconv_smbpw();
		initialized = true;
	}
}

/* We can parameterize this if someone complains.... JRA. */

char lp_failed_convert_char_smbpw(void)
{
	return '_';
}
static size_t convert_string_internal_smbpw(charset_t from, charset_t to,
		      void const *src, size_t srclen, 
		      void *dest, size_t destlen, bool allow_bad_conv)
{
	size_t i_len, o_len;
	size_t retval;
	const char* inbuf = (const char*)src;
	char* outbuf = (char*)dest;
	smb_iconv_t descriptor;

	lazy_initialize_conv_smbpw();

	descriptor = conv_handles[from][to];

	if (srclen == (size_t)-1) {
		if (from == CH_UTF16LE || from == CH_UTF16BE) {
			srclen = (strlen_w_smbpw((const smb_ucs2_t *)src)+1) * 2;
		} else {
			srclen = strlen((const char *)src)+1;
		}
	}


	if (descriptor == (smb_iconv_t)-1 || descriptor == (smb_iconv_t)0) {
		if (!conv_silent)
			DEBUG(0,("convert_string_internal: Conversion not supported.\n"));
		return (size_t)-1;
	}

	i_len=srclen;
	o_len=destlen;

 again:

	retval = smb_iconv_smbpw(descriptor, &inbuf, &i_len, &outbuf, &o_len);
	if(retval==(size_t)-1) {
	    	const char *reason="unknown error";
		switch(errno) {
			case EINVAL:
				reason="Incomplete multibyte sequence";
				if (!conv_silent)
					DEBUG(3,("convert_string_internal: Conversion error: %s(%s)\n",reason,inbuf));
				if (allow_bad_conv)
					goto use_as_is;
				return (size_t)-1;
			case E2BIG:
				reason="No more room"; 
				if (!conv_silent) 
               	{
                    DEBUG(3,("E2BIG: convert_string error: %s\n", reason));
				}
				break;
			case EILSEQ:
				reason="Illegal multibyte sequence";
				if (!conv_silent)
					DEBUG(3,("convert_string_internal: Conversion error: %s(%s)\n",reason,inbuf));
				if (allow_bad_conv)
					goto use_as_is;
				
				return (size_t)-1;
			default:
				if (!conv_silent)
					DEBUG(0,("convert_string_internal: Conversion error: %s(%s)\n",reason,inbuf));
				return (size_t)-1;
		}
		/* smb_panic(reason); */
	}
	return destlen-o_len;

 use_as_is:

	/* 
	 * Conversion not supported. This is actually an error, but there are so
	 * many misconfigured iconv systems and smb.conf's out there we can't just
	 * fail. Do a very bad conversion instead.... JRA.
	 */

	{
		if (o_len == 0 || i_len == 0)
			return destlen - o_len;

		if (((from == CH_UTF16LE)||(from == CH_UTF16BE)) &&
				((to != CH_UTF16LE)||(to != CH_UTF16BE))) {
			/* Can't convert from utf16 any endian to multibyte.
			   Replace with the default fail char.
			*/
			if (i_len < 2)
				return destlen - o_len;
			if (i_len >= 2) {
				*outbuf = lp_failed_convert_char_smbpw();

				outbuf++;
				o_len--;

				inbuf += 2;
				i_len -= 2;
			}

			if (o_len == 0 || i_len == 0)
				return destlen - o_len;

			/* Keep trying with the next char... */
			goto again;

		} else if (from != CH_UTF16LE && from != CH_UTF16BE && to == CH_UTF16LE) {
			/* Can't convert to UTF16LE - just widen by adding the
			   default fail char then zero.
			*/
			if (o_len < 2)
				return destlen - o_len;

			outbuf[0] = lp_failed_convert_char_smbpw();
			outbuf[1] = '\0';

			inbuf++;
			i_len--;

			outbuf += 2;
			o_len -= 2;

			if (o_len == 0 || i_len == 0)
				return destlen - o_len;

			/* Keep trying with the next char... */
			goto again;

		} else if (from != CH_UTF16LE && from != CH_UTF16BE &&
				to != CH_UTF16LE && to != CH_UTF16BE) {
			/* Failed multibyte to multibyte. Just copy the default fail char and
				try again. */
			outbuf[0] = lp_failed_convert_char_smbpw();

			inbuf++;
			i_len--;

			outbuf++;
			o_len--;

			if (o_len == 0 || i_len == 0)
				return destlen - o_len;

			/* Keep trying with the next char... */
			goto again;

		} else {
			/* Keep compiler happy.... */
			return destlen - o_len;
		}
	}
}


size_t ucs2_align_smbpw(const void *base_ptr, const void *p, int flags)
{
	if (flags & (STR_NOALIGN|STR_ASCII))
		return 0;
	return PTR_DIFF(p, base_ptr) & 1;
}

/**
 * Convert string from one encoding to another, making error checking etc
 * Fast path version - handles ASCII first.
 *
 * @param src pointer to source string (multibyte or singlebyte)
 * @param srclen length of the source string in bytes, or -1 for nul terminated.
 * @param dest pointer to destination string (multibyte or singlebyte)
 * @param destlen maximal length allowed for string - *NEVER* -1.
 * @param allow_bad_conv determines if a "best effort" conversion is acceptable (never returns errors)
 * @returns the number of bytes occupied in the destination
 *
 * Ensure the srclen contains the terminating zero.
 *
 * This function has been hand-tuned to provide a fast path.
 * Don't change unless you really know what you are doing. JRA.
 **/

size_t convert_string_smbpw(charset_t from, charset_t to,
		      void const *src, size_t srclen, 
		      void *dest, size_t destlen, bool allow_bad_conv)
{
	/*
	 * NB. We deliberately don't do a strlen here if srclen == -1.
	 * This is very expensive over millions of calls and is taken
	 * care of in the slow path in convert_string_internal. JRA.
	 */

#ifdef DEVELOPER
	SMB_ASSERT(destlen != (size_t)-1);
#endif

	if (srclen == 0)
		return 0;

	if (from != CH_UTF16LE && from != CH_UTF16BE && to != CH_UTF16LE && to != CH_UTF16BE) {
		const unsigned char *p = (const unsigned char *)src;
		unsigned char *q = (unsigned char *)dest;
		size_t slen = srclen;
		size_t dlen = destlen;
		unsigned char lastp = '\0';
		size_t retval = 0;

		/* If all characters are ascii, fast path here. */
		while (slen && dlen) {
			if ((lastp = *p) <= 0x7f) {
				*q++ = *p++;
				if (slen != (size_t)-1) {
					slen--;
				}
				dlen--;
				retval++;
				if (!lastp)
					break;
			} else {
#ifdef BROKEN_UNICODE_COMPOSE_CHARACTERS
				goto general_case;
#else
				size_t ret = convert_string_internal_smbpw(from, to, p, slen, q, dlen, allow_bad_conv);
				if (ret == (size_t)-1) {
					return ret;
				}
				return retval + ret;
#endif
			}
		}
		if (!dlen) {
			/* Even if we fast path we should note if we ran out of room. */
			if (((slen != (size_t)-1) && slen) ||
					((slen == (size_t)-1) && lastp)) {
				errno = E2BIG;
			}
		}
		return retval;
	} else if (from == CH_UTF16LE && to != CH_UTF16LE) {
		const unsigned char *p = (const unsigned char *)src;
		unsigned char *q = (unsigned char *)dest;
		size_t retval = 0;
		size_t slen = srclen;
		size_t dlen = destlen;
		unsigned char lastp = '\0';

		/* If all characters are ascii, fast path here. */
		while (((slen == (size_t)-1) || (slen >= 2)) && dlen) {
			if (((lastp = *p) <= 0x7f) && (p[1] == 0)) {
				*q++ = *p;
				if (slen != (size_t)-1) {
					slen -= 2;
				}
				p += 2;
				dlen--;
				retval++;
				if (!lastp)
					break;
			} else {
#ifdef BROKEN_UNICODE_COMPOSE_CHARACTERS
				goto general_case;
#else
				size_t ret = convert_string_internal_smbpw(from, to, p, slen, q, dlen, allow_bad_conv);
				if (ret == (size_t)-1) {
					return ret;
				}
				return retval + ret;
#endif
			}
		}
		if (!dlen) {
			/* Even if we fast path we should note if we ran out of room. */
			if (((slen != (size_t)-1) && slen) ||
					((slen == (size_t)-1) && lastp)) {
				errno = E2BIG;
			}
		}
		return retval;
	} else if (from != CH_UTF16LE && from != CH_UTF16BE && to == CH_UTF16LE) {
		const unsigned char *p = (const unsigned char *)src;
		unsigned char *q = (unsigned char *)dest;
		size_t retval = 0;
		size_t slen = srclen;
		size_t dlen = destlen;
		unsigned char lastp = '\0';

		/* If all characters are ascii, fast path here. */
		while (slen && (dlen >= 2)) {
			if ((lastp = *p) <= 0x7F) {
				*q++ = *p++;
				*q++ = '\0';
				if (slen != (size_t)-1) {
					slen--;
				}
				dlen -= 2;
				retval += 2;
				if (!lastp)
					break;
			} else {
#ifdef BROKEN_UNICODE_COMPOSE_CHARACTERS
				goto general_case;
#else
				size_t ret = convert_string_internal_smbpw(from, to, p, slen, q, dlen, allow_bad_conv);
				if (ret == (size_t)-1) {
					return ret;
				}
				return retval + ret;
#endif
			}
		}
		if (!dlen) {
			/* Even if we fast path we should note if we ran out of room. */
			if (((slen != (size_t)-1) && slen) ||
					((slen == (size_t)-1) && lastp)) {
				errno = E2BIG;
			}
		}
		return retval;
	}

#ifdef BROKEN_UNICODE_COMPOSE_CHARACTERS
  general_case:
#endif
	return convert_string_internal_smbpw(from, to, src, srclen, dest, destlen, allow_bad_conv);
}

/*******************************************************************
 Convert a wchar to upper case.
********************************************************************/

smb_ucs2_t toupper_w_smbpw(smb_ucs2_t val)
{
	return upcase_table[SVAL(&val,0)];
}

/*
size_t unix_strupper(const char *src, size_t srclen, char *dest, size_t destlen)
{
	size_t size;
	smb_ucs2_t *buffer;

	size = push_ucs2_allocate(&buffer, src);
	if (size == (size_t)-1) {
		return (size_t)-1;
	}
	if (!strupper_w(buffer) && (dest == src)) {
		free(buffer);
		return srclen;
	}

	size = convert_string(CH_UTF16LE, CH_UNIX, buffer, size, dest, destlen, True);
	free(buffer);
	return size;
}*/

/*******************************************************************
 Convert a wchar to lower case.
********************************************************************/

smb_ucs2_t tolower_w_smbpw( smb_ucs2_t val )
{
	return lowcase_table[SVAL(&val,0)];
}

/*************************************************************
 ascii only tolower - saves the need for smbd to be in C locale.
*************************************************************/

int tolower_ascii_smbpw(int c)
{
	smb_ucs2_t uc = tolower_w_smbpw(UCS2_CHAR(c));
	return UCS2_TO_CHAR(uc);
}

/**
 Convert a string to lower case.
**/

void strlower_m_smbpw(char *s)
{
	size_t len;
	int errno_save;

	/* this is quite a common operation, so we want it to be
	   fast. We optimise for the ascii case, knowing that all our
	   supported multi-byte character sets are ascii-compatible
	   (ie. they match for the first 128 chars) */
	if(!s)
		SMBPW_ERR("The string pointer is NULL");
	while (*s && !(((unsigned char)s[0]) & 0x80)) {
		*s = tolower_ascii_smbpw((unsigned char)*s);
		s++;
	}

	if (!*s)
		return;
#if 0
	/* I assume that lowercased string takes the same number of bytes
	 * as source string even in UTF-8 encoding. (VIV) */
	len = strlen(s) + 1;
	errno_save = errno;
	errno = 0;
	unix_strlower(s,len,s,len);
	/* Catch mb conversion errors that may not terminate. */
	if (errno)
		s[len-1] = '\0';
	errno = errno_save;
#endif
}


/**
 Convert a string to upper case.
**/

void strupper_m_smbpw(char *s)
{
	size_t len;
	int errno_save;

	/* this is quite a common operation, so we want it to be
	   fast. We optimise for the ascii case, knowing that all our
	   supported multi-byte character sets are ascii-compatible
	   (ie. they match for the first 128 chars) */

	while (*s && !(((unsigned char)s[0]) & 0x80)) {
		*s = toupper_ascii_fast((unsigned char)*s);
		s++;
	}

	if (!*s)
		return;
#if 0
	/* I assume that lowercased string takes the same number of bytes
	 * as source string even in multibyte encoding. (VIV) */
	len = strlen(s) + 1;
	errno_save = errno;
	errno = 0;
	unix_strupper(s,len,s,len);
	/* Catch mb conversion errors that may not terminate. */
	if (errno)
		s[len-1] = '\0';
	errno = errno_save;
#endif
}

/**
 * Copy a string from a char* src to a unicode destination.
 *
 * @returns the number of bytes occupied by the string in the destination.
 *
 * @param flags can have:
 *
 * <dl>
 * <dt>STR_TERMINATE <dd>means include the null termination.
 * <dt>STR_UPPER     <dd>means uppercase in the destination.
 * <dt>STR_NOALIGN   <dd>means don't do alignment.
 * </dl>
 *
 * @param dest_len is the maximum length allowed in the
 * destination.
 **/

size_t push_ucs2_smbpw(const void *base_ptr, void *dest, const char *src, size_t dest_len, int flags)
{
	size_t len=0;
	size_t src_len;
	size_t ret;

	if (dest_len == (size_t)-1) {
		/* No longer allow dest_len of -1. */
		SMB_ASSERT("push_ucs2 - invalid dest_len of -1");
	}

	if (flags & STR_TERMINATE)
		src_len = (size_t)-1;
	else
		src_len = strlen(src);

	if (ucs2_align_smbpw(base_ptr, dest, flags)) {
		*(char *)dest = 0;
		dest = (void *)((char *)dest + 1);
		if (dest_len)
			dest_len--;
		len++;
	}

	/* ucs2 is always a multiple of 2 bytes */
	dest_len &= ~1;

	ret =  convert_string_smbpw(CH_UNIX, CH_UTF16LE, src, src_len, dest, dest_len, True);
	if (ret == (size_t)-1) {
		if ((flags & STR_TERMINATE) &&
				dest &&
				dest_len) {
			*(char *)dest = 0;
		}
		return len;
	}

	len += ret;

	if (flags & STR_UPPER) {
		smb_ucs2_t *dest_ucs2 = (smb_ucs2_t *)dest;
		size_t i;

		/* We check for i < (ret / 2) below as the dest string isn't null
		   terminated if STR_TERMINATE isn't set. */

		for (i = 0; i < (ret / 2) && i < (dest_len / 2) && dest_ucs2[i]; i++) {
			smb_ucs2_t v = toupper_w_smbpw(dest_ucs2[i]);
			if (v != dest_ucs2[i]) {
				dest_ucs2[i] = v;
			}
		}
	}

	return len;
}


/**
 * Copy a string from a char* unix src to a dos codepage string destination.
 *
 * @return the number of bytes occupied by the string in the destination.
 *
 * @param flags can include
 * <dl>
 * <dt>STR_TERMINATE</dt> <dd>means include the null termination</dd>
 * <dt>STR_UPPER</dt> <dd>means uppercase in the destination</dd>
 * </dl>
 *
 * @param dest_len the maximum length in bytes allowed in the
 * destination.
 **/
size_t push_ascii_smbpw(void *dest, const char *src, size_t dest_len, int flags)
{
	size_t src_len = strlen(src);
	char *tmpbuf = NULL;
	size_t ret;

	/* No longer allow a length of -1. */
	if (dest_len == (size_t)-1) {
		SMBPW_ERR("push_ascii - dest_len == -1");
	}

	if (flags & STR_UPPER) {
		tmpbuf = smb_strdup(src);
		if (!tmpbuf) {
			SMBPW_ERR("malloc fail");
		}
		strupper_m_smbpw(tmpbuf);
		src = tmpbuf;
	}

	if (flags & (STR_TERMINATE | STR_TERMINATE_ASCII)) {
		src_len++;
	}

	ret = convert_string_smbpw(CH_UNIX, CH_DOS, src, src_len, dest, dest_len, True);
	if (ret == (size_t)-1 &&
			(flags & (STR_TERMINATE | STR_TERMINATE_ASCII))
			&& dest_len > 0) {
		((char *)dest)[0] = '\0';
	}
	SAFE_FREE(tmpbuf);
	return ret;
}


#endif

