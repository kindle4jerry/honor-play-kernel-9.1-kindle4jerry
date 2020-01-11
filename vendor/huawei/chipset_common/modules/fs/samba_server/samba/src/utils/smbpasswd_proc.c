/*this file added by qichenghong 20091020 for only processing the add of samba password */

#include "includes.h"

#ifdef CUT_SMBPASSWD

#include "smbpasswd_proc.h"
#include "smbpw_charcnv.h"

#define SMBPASSWD_FILE		"/data/samba_server/private/smbpasswd"
#define SMBPASSWD_FILE_OLD	"/data/samba_server/private/smbpasswd.old"
enum pwf_access_type { PWF_READ, PWF_UPDATE, PWF_CREATE };


struct smb_passwd
{
        uint32 smb_userid;        /* this is actually the unix uid_t */
        const char *smb_name;     /* username string */

        const unsigned char *smb_passwd;    /* Null if no password */
        const unsigned char *smb_nt_passwd; /* Null if no password */

        uint16 acct_ctrl;             /* account info (ACB_xxxx bit-mask) */
        time_t pass_last_set_time;    /* password last set time */
};

char * smb_strcpy(char *dst ,const char *src)
{
	char *pd=dst;
	if(!src || !dst)
		SMBPW_ERR("The pointer parameter is NULL!\n");
	while(*src)
	{
		*pd = *src;
		pd++;
		src++;
	}
	*pd='\0';
	return dst;
}

void *smb_memcpy(void *dst , const void *src , size_t len)
{
	char *pd = (char *)dst;
	char *ps = (char *)src;
	if( !dst || !src)
		SMBPW_ERR("The string pointer is NULL");
	SMB_ASSERT(len);
	while(len--)
		*pd++ = *ps++;

	return dst;
}

size_t smb_strlen(const char *s)
{
	size_t len = 0;
	if( !s )
		SMBPW_ERR("The string pointer is NULL");
	while( s[len ++] )
		;

	return len;
}

/**
 strdup that aborts on malloc fail.
**/

char *smb_strdup(const char *s)
{
	int len;
	char *s1;
	if(!s)
	{
		SMBPW_ERR("The string pointer is NULL");
	}
	len=strlen(s);
	if(len != 0)
	{
		s1 = (char *)malloc(len+1);
		if (!s1) 
		{
			SMBPW_ERR("smb_xstrdup: malloc failed");
		}
	}
	else
		return NULL;
	
	if(!smb_strcpy(s1 , s))
		return NULL;
	
	return s1;

}


/*******************************************************************
 An open() wrapper that will deal with 64 bit filesizes.
********************************************************************/

int sys_open_smbpw(const char *path, int oflag, mode_t mode)
{
#if defined(HAVE_EXPLICIT_LARGEFILE_SUPPORT) && defined(HAVE_OPEN64)
	return open64(path, oflag, mode);
#else
	return open(path, oflag, mode);
#endif
}

/*******************************************************************
 A wrapper for usleep in case we don't have one.
********************************************************************/

int sys_usleep_smbpw(long usecs)
{
#ifndef HAVE_USLEEP
	struct timeval tval;
#endif

	/*
	 * We need this braindamage as the glibc usleep
	 * is not SPEC1170 complient... grumble... JRA.
	 */

	if(usecs < 0 || usecs > 1000000) {
		errno = EINVAL;
		return -1;
	}

#if HAVE_USLEEP
	usleep(usecs);
	return 0;
#else /* HAVE_USLEEP */
	/*
	 * Fake it with select...
	 */
	tval.tv_sec = 0;
	tval.tv_usec = usecs/1000;
	select(0,NULL,NULL,NULL,&tval);
	return 0;
#endif /* HAVE_USLEEP */
}

/*******************************************************************
 An fopen() wrapper that will deal with 64 bit filesizes.
********************************************************************/

FILE *sys_fopen_smbpw(const char *path, const char *type)
{
#if defined(HAVE_EXPLICIT_LARGEFILE_SUPPORT) && defined(HAVE_FOPEN64)
	return fopen64(path, type);
#else
	return fopen(path, type);
#endif
}

/*******************************************************************
 An lseek() wrapper that will deal with 64 bit filesizes.
********************************************************************/

SMB_OFF_T sys_lseek_smbpw(int fd, SMB_OFF_T offset, int whence)
{
#if defined(HAVE_EXPLICIT_LARGEFILE_SUPPORT) && defined(HAVE_OFF64_T) && defined(HAVE_LSEEK64)
	return lseek64(fd, offset, whence);
#else
	return lseek(fd, offset, whence);
#endif
}

/*******************************************************************
 An ftruncate() wrapper that will deal with 64 bit filesizes.
********************************************************************/

int sys_ftruncate_smbpw(int fd, SMB_OFF_T offset)
{
#if defined(HAVE_EXPLICIT_LARGEFILE_SUPPORT) && defined(HAVE_OFF64_T) && defined(HAVE_FTRUNCATE64)
	return ftruncate64(fd, offset);
#else
	return ftruncate(fd, offset);
#endif
}

/***************************************************************
 Internal fn to enumerate the smbpasswd list. Returns a void pointer
 to ensure no modification outside this module. Checks for atomic
 rename of smbpasswd file on update or create once the lock has
 been granted to prevent race conditions. JRA.
****************************************************************/

static FILE *startsmbfilepwent(const char *pfile, enum pwf_access_type type)
{
	FILE *fp = NULL;
	const char *open_mode = NULL;
	int race_loop = 0;
	int lock_type = F_RDLCK;

	if (!*pfile) {
		DEBUG(0, ("startsmbfilepwent: No SMB password file set\n"));
		return (NULL);
	}

	switch(type) {
		case PWF_READ:
			open_mode = "rb";
			break;
		case PWF_UPDATE:
			open_mode = "r+b";
			break;
		case PWF_CREATE:
			/*
			 * Ensure atomic file creation.
			 */
			{
				int i, fd = -1;

				for(i = 0; i < 5; i++) {
					if((fd = sys_open_smbpw(pfile, O_CREAT|O_TRUNC|O_EXCL|O_RDWR, 0600))!=-1) {
						break;
					}
					sys_usleep_smbpw(200); /* Spin, spin... */
				}
				if(fd == -1) {
					DEBUG(0,("startsmbfilepwent_internal: too many race conditions \
creating file %s\n", pfile));
					return NULL;
				}
				close(fd);
				open_mode = "r+b";
				break;
			}
	}
		       
	for(race_loop = 0; race_loop < 5; race_loop++) {

            //DEBUG(10, ("startsmbfilepwent_internal: opening file %s\n", pfile));

		if((fp = sys_fopen_smbpw(pfile, open_mode)) == NULL) {

			/*
			 * If smbpasswd file doesn't exist, then create new one. This helps to avoid
			 * confusing error msg when adding user account first time.
			 */
			if (errno == ENOENT) {
				if ((fp = sys_fopen_smbpw(pfile, "a+")) != NULL) {
					DEBUG(0, ("startsmbfilepwent_internal: file %s did not \
                                                exist. File successfully created.\n", pfile));
				} else {
					DEBUG(0, ("startsmbfilepwent_internal: file %s did not \
                                                    exist. Couldn't create new one. Error was: %s",
					pfile, strerror(errno)));
					return NULL;
				}
			} else {
				DEBUG(0, ("startsmbfilepwent_internal: unable to open file %s. \
                                Error was: %s\n", pfile, strerror(errno)));
				return NULL;
			}
		}
		else
			break;

	}

	if(race_loop == 5) {
		DEBUG(0, ("startsmbfilepwent_internal: too many race conditions opening file %s\n", pfile));
		return NULL;
	}

	/* Set a buffer to do more efficient reads */
	setvbuf(fp, (char *)NULL, _IOFBF, 1024);


	/* We have a lock on the file. */
	return fp;
}

/***************************************************************
 End enumeration of the smbpasswd list.
****************************************************************/

static void endsmbfilepwent(FILE *fp)
{
	if (!fp) {
		return;
	}

	fclose(fp);
	//DEBUG(7, ("endsmbfilepwent_internal: closed password file.\n"));
}

/**********************************************************
 Encode the account control bits into a string.
 length = length of string to encode into (including terminating
 null). length *MUST BE MORE THAN 2* !
 **********************************************************/

char *encode_acct_ctrl(uint32 acct_ctrl, size_t length)
{
	static fstring acct_str;

	size_t i = 0;

	SMB_ASSERT(length <= sizeof(acct_str));

	acct_str[i++] = '[';

	if (acct_ctrl & ACB_PWNOTREQ ) acct_str[i++] = 'N';
	if (acct_ctrl & ACB_DISABLED ) acct_str[i++] = 'D';
	if (acct_ctrl & ACB_HOMDIRREQ) acct_str[i++] = 'H';
	if (acct_ctrl & ACB_TEMPDUP  ) acct_str[i++] = 'T'; 
	if (acct_ctrl & ACB_NORMAL   ) acct_str[i++] = 'U';
	if (acct_ctrl & ACB_MNS      ) acct_str[i++] = 'M';
	if (acct_ctrl & ACB_WSTRUST  ) acct_str[i++] = 'W';
	if (acct_ctrl & ACB_SVRTRUST ) acct_str[i++] = 'S';
	if (acct_ctrl & ACB_AUTOLOCK ) acct_str[i++] = 'L';
	if (acct_ctrl & ACB_PWNOEXP  ) acct_str[i++] = 'X';
	if (acct_ctrl & ACB_DOMTRUST ) acct_str[i++] = 'I';

	for ( ; i < length - 2 ; i++ )
		acct_str[i] = ' ';

	i = length - 2;
	acct_str[i++] = ']';
	acct_str[i++] = '\0';

	return acct_str;
}     


/*************************************************************
 Routine to set 32 hex password characters from a 16 byte array.
**************************************************************/

void sethexpwd(char p[33], const unsigned char *pwd, uint32 acct_ctrl)
{
	if (pwd != NULL) {
		int i;
		for (i = 0; i < 16; i++)
			slprintf(&p[i*2], 3, "%02X", pwd[i]);
	} else {
		if (acct_ctrl & ACB_PWNOTREQ)
		{
			/*safe_strcpy(p, "NO PASSWORDXXXXXXXXXXXXXXXXXXXXX", 32);*/
			memmove((void *)p, "NO PASSWORDXXXXXXXXXXXXXXXXXXXXX", 32);
		}
		else
		{
			/*safe_strcpy(p, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 32);*/
			memmove((void *)p, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 32);
		}
		p[32] = 0;
	}
}

/************************************************************************
 Create a new smbpasswd entry - malloced space returned.
*************************************************************************/

static char *format_new_smbpasswd_entry(const struct smb_passwd *newpwd)
{
	int new_entry_length;
	char *new_entry;
	char *p;

	new_entry_length = strlen(newpwd->smb_name) + 1 + 15 + 1 + 32 + 1 + 32 + 1 + 
				NEW_PW_FORMAT_SPACE_PADDED_LEN + 1 + 13 + 2;

	if((new_entry = (char *)SMB_MALLOC( new_entry_length )) == NULL) {
		DEBUG(0, ("format_new_smbpasswd_entry: Malloc failed adding entry for user %s.\n",
			newpwd->smb_name ));
		return NULL;
	}

	slprintf(new_entry, new_entry_length - 1, "%s:%u:", newpwd->smb_name, (unsigned)newpwd->smb_userid);

	p = new_entry+strlen(new_entry);
	sethexpwd(p, newpwd->smb_passwd, newpwd->acct_ctrl);
	p+=strlen(p);
	*p = ':';
	p++;

	sethexpwd(p, newpwd->smb_nt_passwd, newpwd->acct_ctrl);
	p+=strlen(p);
	*p = ':';
	p++;

	/* Add the account encoding and the last change time. */
	slprintf((char *)p, new_entry_length - 1 - (p - new_entry),  "%s:LCT-%08X:\n",
		encode_acct_ctrl(newpwd->acct_ctrl, NEW_PW_FORMAT_SPACE_PADDED_LEN),
		(uint32)newpwd->pass_last_set_time);

	return new_entry;
}

#if 0
/***************************************************************
 Lock or unlock a fd for a known lock type. Abandon after waitsecs 
 seconds.
****************************************************************/

static bool do_file_lock(int fd, int waitsecs, int type)
{
	SMB_STRUCT_FLOCK lock;
	int             ret;
	void (*oldsig_handler)(int);

	gotalarm = 0;
	oldsig_handler = CatchSignal(SIGALRM, SIGNAL_CAST gotalarm_sig);

	lock.l_type = type;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 1;
	lock.l_pid = 0;

	alarm(waitsecs);
	/* Note we must *NOT* use sys_fcntl here ! JRA */
	ret = fcntl(fd, SMB_F_SETLKW, &lock);
	alarm(0);
	CatchSignal(SIGALRM, SIGNAL_CAST oldsig_handler);

	if (gotalarm && ret == -1) {
		DEBUG(0, ("do_file_lock: failed to %s file.\n",
			type == F_UNLCK ? "unlock" : "lock"));
		return False;
	}

	return (ret == 0);
}

/***************************************************************
 Lock an fd. Abandon after waitsecs seconds.
****************************************************************/

static bool pw_file_lock(int fd, int type, int secs, int *plock_depth)
{
	if (fd < 0) {
		return False;
	}

	if(*plock_depth == 0) {
		if (!do_file_lock(fd, secs, type)) {
			DEBUG(10,("pw_file_lock: locking file failed, error = %s.\n",
				strerror(errno)));
			return False;
		}
	}

	(*plock_depth)++;

	return True;
}

/***************************************************************
 Unlock an fd. Abandon after waitsecs seconds.
****************************************************************/

static bool pw_file_unlock(int fd, int *plock_depth)
{
	bool ret=True;

	if (fd == 0 || *plock_depth == 0) {
		return True;
	}

	if(*plock_depth == 1) {
		ret = do_file_lock(fd, 5, F_UNLCK);
	}

	if (*plock_depth > 0) {
		(*plock_depth)--;
	}

	if(!ret) {
		DEBUG(10,("pw_file_unlock: unlocking file failed, error = %s.\n",
			strerror(errno)));
	}
	return ret;
}
#endif

/************************************************************************
 Routine to add an entry to the smbpasswd file.
*************************************************************************/

static NTSTATUS add_smbpwd_entry( struct smb_passwd *newpwd, int local_flags)
{
	const char *pfile = NULL;
	FILE *fp = NULL;
	int wr_len;
	int fd;
	size_t new_entry_length;
	char *new_entry;
	SMB_OFF_T offpos;
 
	if(local_flags & LOCAL_AM_OLD) {
		pfile = SMBPASSWD_FILE_OLD;
	} else {
		pfile = SMBPASSWD_FILE;
	}
	/* Open the smbpassword file - for update. */
	fp = startsmbfilepwent(pfile, PWF_UPDATE);
	
	if (fp != NULL) {
		fclose(fp);
		unlink(pfile);
		fp = startsmbfilepwent(pfile, PWF_CREATE);
	}

	if (fp == NULL && errno == ENOENT) {
		/* Try again - create. */
		fp = startsmbfilepwent(pfile, PWF_CREATE);
	}

	if (fp == NULL) {
		DEBUG(0, ("add_smbfilepwd_entry: unable to open file.\n"));
		return map_nt_error_from_unix(errno);
	}

	/*
	 * Scan the file, a line at a time and check if the name matches.
	 */
/*
	while ((pwd = getsmbfilepwent(smbpasswd_state, fp)) != NULL) {
		if (strequal(newpwd->smb_name, pwd->smb_name)) {
			DEBUG(0, ("add_smbfilepwd_entry: entry with name %s already exists\n", pwd->smb_name));
			endsmbfilepwent(fp, &smbpasswd_state->pw_file_lock_depth);
			return NT_STATUS_USER_EXISTS;
		}
	}
*/
	/* Ok - entry doesn't exist. We can add it */

	/* Create a new smb passwd entry and set it to the given password. */
	/* 
	 * The add user write needs to be atomic - so get the fd from 
	 * the fp and do a raw write() call.
	 */
	fd = fileno(fp);

	if((offpos = sys_lseek_smbpw(fd, 0, SEEK_END)) == -1) {
		NTSTATUS result = map_nt_error_from_unix(errno);
		DEBUG(0, ("add_smbfilepwd_entry(sys_lseek_smbpw): Failed to add entry for user %s to file %s. \
Error was %s\n", newpwd->smb_name, pfile, strerror(errno)));
		endsmbfilepwent(fp);
		return result;
	}

	if((new_entry = format_new_smbpasswd_entry(newpwd)) == NULL) {
		DEBUG(0, ("add_smbfilepwd_entry(malloc): Failed to add entry for user %s to file %s. \
Error was %s\n", newpwd->smb_name, pfile, strerror(errno)));
		endsmbfilepwent(fp);
		return NT_STATUS_NO_MEMORY;
	}

	new_entry_length = strlen(new_entry);

#ifdef DEBUG_PASSWORD
	DEBUG(100, ("add_smbfilepwd_entry(%d): new_entry_len %d made line |%s|", 
			fd, (int)new_entry_length, new_entry));
#endif

	if ((wr_len = write(fd, new_entry, new_entry_length)) != new_entry_length) {
		NTSTATUS result = map_nt_error_from_unix(errno);
		DEBUG(0, ("add_smbfilepwd_entry(write): %d Failed to add entry for user %s to file %s. \
Error was %s\n", wr_len, newpwd->smb_name, pfile, strerror(errno)));

		/* Remove the entry we just wrote. */
		if(sys_ftruncate_smbpw(fd, offpos) == -1) {
			DEBUG(0, ("add_smbfilepwd_entry: ERROR failed to ftruncate file %s. \
Error was %s. Password file may be corrupt ! Please examine by hand !\n", 
				newpwd->smb_name, strerror(errno)));
		}

		endsmbfilepwent(fp);
		free(new_entry);
		return result;
	}

	free(new_entry);
	endsmbfilepwent(fp);
	return NT_STATUS_OK;
}
	

static NTSTATUS smbpasswd_add_account(struct smb_passwd *smb_pw, int local_flags)
{
/*	struct smbpasswd_privates *smbpasswd_state = (struct smbpasswd_privates*)my_methods->private_data;
	struct smb_passwd smb_pw;*/
	
	
	/* add the entry */
	return add_smbpwd_entry(smb_pw, local_flags);
}

bool set_pass_last_set_time(struct smb_passwd *sampass, time_t mytime, enum pdb_value_state flag)
{
	sampass->pass_last_set_time = mytime;
	return True;
}

/*********************************************************************
 Set the user's LM hash.
 ********************************************************************/

bool set_lanman_passwd(struct smb_passwd *sampass, const uint8 pwd[LM_HASH_LEN], enum pdb_value_state flag)
{
/*	DATA_BLOB temp;*/
	/* on keep the password if we are allowing LANMAN authentication */

	if (pwd && False)/*lp_lanman_auth() is replaced by False , because the result of lp_lanman_auth() is always false in the system*/
	{
		sampass->smb_passwd = (unsigned char *)malloc(LM_HASH_LEN);/*data_blob_talloc(sampass, pwd, LM_HASH_LEN);*/
		if(sampass->smb_passwd != NULL)
			smb_memcpy((void*)sampass->smb_passwd , pwd , LM_HASH_LEN);
		else
			return False;
	} else {
		sampass->smb_passwd = NULL;/*data_blob_null;*/
	}
	
	return True;
}


/*********************************************************************
 Set the user's NT hash.
 ********************************************************************/

bool set_nt_passwd(struct smb_passwd *sampass, const uint8 pwd[NT_HASH_LEN], enum pdb_value_state flag)
{
/*	DATA_BLOB temp;*/
	
       if (pwd) {
              sampass->smb_nt_passwd  = (unsigned char *)malloc(NT_HASH_LEN);/*data_blob_talloc(sampass, pwd, NT_HASH_LEN);*/
              if(sampass->smb_nt_passwd != NULL)
			smb_memcpy((void*)sampass->smb_nt_passwd , pwd , NT_HASH_LEN);
              else 
              	return False;
       } else {
              sampass->smb_nt_passwd  = NULL;/*data_blob_null;*/
       }
		
	return True;
}


/**
 * Creates the MD4 Hash of the users password in NT UNICODE.
 * @param passwd password in 'unix' charset.
 * @param p16 return password hashed with md4, caller allocated 16 byte buffer
 */
 
static void E_md4hash1(const char *passwd, uchar p16[16])
{
	int len;
	smb_ucs2_t wpwd[129];
	
	/* Password must be converted to NT unicode - null terminated. */
	push_ucs2_smbpw(NULL, wpwd, (const char *)passwd, 256, STR_UNICODE|STR_NOALIGN|STR_TERMINATE);
	/* Calculate length in bytes */
	len = strlen_w_smbpw(wpwd) * sizeof(int16);

	mdfour(p16, (unsigned char *)wpwd, len);
	ZERO_STRUCT(wpwd);	
}

/**
 * Creates the DES forward-only Hash of the users password in DOS ASCII charset
 * @param passwd password in 'unix' charset.
 * @param p16 return password hashed with DES, caller allocated 16 byte buffer
 * @return False if password was > 14 characters, and therefore may be incorrect, otherwise True
 * @note p16 is filled in regardless
 */
 
static bool E_deshash1(const char *passwd, uchar p16[16])
{
	bool ret = True;
	fstring dospwd; 
	ZERO_STRUCT(dospwd);
	
	/* Password must be converted to DOS charset - null terminated, uppercase. */
	push_ascii_smbpw(dospwd, passwd, sizeof(dospwd), STR_UPPER|STR_TERMINATE);
       
	/* Only the fisrt 14 chars are considered, password need not be null terminated. */
	E_P16((const unsigned char *)dospwd, p16);

	if (strlen(dospwd) > 14) {
		ret = False;
	}

	ZERO_STRUCT(dospwd);	

	return ret;
}


/*********************************************************************
 Set the user's PLAINTEXT password.  Used as an interface to the above.
 Also sets the last change time to NOW.
 ********************************************************************/

bool set_plaintext_passwd(struct smb_passwd *sampass, const char *plaintext)
{
	uchar new_lanman_p16[LM_HASH_LEN];
	uchar new_nt_p16[NT_HASH_LEN];

	if (!plaintext)
		return False;
	/* Calculate the MD4 hash (NT compatible) of the password */
	E_md4hash1(plaintext, new_nt_p16);
	if (!set_nt_passwd (sampass, new_nt_p16, PDB_CHANGED)) 
		return False;
	if (!E_deshash1(plaintext, new_lanman_p16)) {
		/* E_deshash returns false for 'long' passwords (> 14
		   DOS chars).  This allows us to match Win2k, which
		   does not store a LM hash for these passwords (which
		   would reduce the effective password length to 14 */
		if (!set_lanman_passwd (sampass, NULL, PDB_CHANGED)) 
			return False;
	} else {
		if (!set_lanman_passwd (sampass, new_lanman_p16, PDB_CHANGED)) 
			return False;
	}

/*	if (!pdb_set_plaintext_pw_only (sampass, plaintext, PDB_CHANGED)) 
		return False;
*/
	if (!set_pass_last_set_time (sampass, time(NULL), PDB_CHANGED))
		return False;


	return True;
}

/*************************************************************
 Add a password entry in the local smbpasswd file.
 *************************************************************/

NTSTATUS local_password_add(const char *user_name,
				int local_flags,
				const char *new_passwd, 
				char * p_err_str,
				int   ulErrStrSize,
				char * p_msg_str,
				int   ulMsgStrSize)
{
/*	struct samu *sam_pass=NULL;
	uint32 other_acb;
	NTSTATUS result;*/
	struct smb_passwd smbpwd;

	
	int tmp_debug = 1;
/*	struct passwd *pwd = NULL;*/

	memset(p_err_str, 0x00, ulErrStrSize);
    memset(p_msg_str, 0x00, ulMsgStrSize);


	ZERO_STRUCT(smbpwd);		
	/* Get the smb passwd entry for this user */
/*
	if ( !(sam_pass = samu_new( NULL )) ) {
		return NT_STATUS_NO_MEMORY;
	}
*/




	/* Might not exist in /etc/passwd. */

	if (tmp_debug < 1) {
		//DEBUGLEVEL = 1;
	}
	
	/*get the system passwd from the file /etc/passwd*/
/*	deleted by qichenghong 20091021
	if ( !(pwd = getpwnam_alloc( NULL, user_name)) ) {	
DebugPrintLine(2);
		return NT_STATUS_NO_SUCH_USER;
	}
*/
	smbpwd.smb_userid = geteuid();
//printf("\n smbpwd.smb_userid = %d \n",smbpwd.smb_userid);
	smbpwd.smb_name = smb_strdup(user_name);

	smbpwd.acct_ctrl = ACB_NORMAL;
/*	TALLOC_FREE( pwd );*/
	//DEBUGLEVEL = tmp_debug;
		/* create the struct samu and initialize the basic Unix properties */
	#if 0
		if ( !(sam_pass = samu_new( NULL )) ) {
			return NT_STATUS_NO_MEMORY;
		}

		result = samu_alloc_rid_unix( sam_pass, pwd );

		

		

		if (NT_STATUS_EQUAL(result, NT_STATUS_INVALID_PRIMARY_GROUP)) {
			return result;
		}

		if (!NT_STATUS_IS_OK(result)) {
			asprintf(pp_err_str, "Failed to " "initialize account for user: %s\n",
				nt_errstr(result));
			return result;
		}
	#endif
	

	/*
	 * We are root - just write the new password
	 * and the valid last change time.
	 */

	if (local_flags & LOCAL_SET_PASSWORD) {
		/*
		 * If we're dealing with setting a completely empty user account
		 * ie. One with a password of 'XXXX', but not set disabled (like
		 * an account created from scratch) then if the old password was
		 * 'XX's then getsmbpwent will have set the ACB_DISABLED flag.
		 * We remove that as we're giving this user their first password
		 * and the decision hasn't really been made to disable them (ie.
		 * don't create them disabled). JRA.
		 */
		if (!set_plaintext_passwd (&smbpwd, new_passwd)) 
        {
			snprintf(p_err_str, ulErrStrSize - 1, "Failed to set password for user.\n"); 
			return NT_STATUS_UNSUCCESSFUL;
		}
	}	

	if (NT_STATUS_IS_OK(smbpasswd_add_account(&smbpwd, local_flags))) 
    {
		snprintf(p_msg_str, ulMsgStrSize - 1, "Added user.\n");
		return NT_STATUS_OK;
	} 
    else 
    {
		snprintf(p_err_str, ulErrStrSize - 1, "Failed to add entry for user.\n");
		return NT_STATUS_UNSUCCESSFUL;
	}
	 
	
	

	return NT_STATUS_OK;
}
#endif

