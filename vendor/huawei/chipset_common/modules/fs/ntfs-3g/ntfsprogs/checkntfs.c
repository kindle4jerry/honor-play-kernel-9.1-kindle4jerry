/**
 * checkntfs
 *
 * Copyright (c) 2000-2006 Anton Altaparmakov
 * Copyright (c) 2002-2006 Szabolcs Szakacsits
 * Copyright (c) 2007      Yura Pakhuchiy
 * Copyright (c) 2011      Jean-Pierre Andre
 *
 * This utility fixes some common NTFS problems, resets the NTFS journal file
 * and schedules an NTFS consistency check for the first boot into Windows.
 *
 *	Anton Altaparmakov <aia21@cantab.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program (in the main directory of the Linux-NTFS source
 * in the file COPYING); if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/*
 * WARNING: This program might not work on architectures which do not allow
 * unaligned access. For those, the program would need to start using
 * get/put_unaligned macros (#include <asm/unaligned.h>), but not doing it yet,
 * since NTFS really mostly applies to ia32 only, which does allow unaligned
 * accesses. We might not actually have a problem though, since the structs are
 * defined as being packed so that might be enough for gcc to insert the
 * correct code.
 *
 * If anyone using a non-little endian and/or an aligned access only CPU tries
 * this program please let me know whether it works or not!
 *
 *	Anton Altaparmakov <aia21@cantab.net>
 */

#include "config.h"

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif
#ifdef HAVE_STDIO_H
#include <stdio.h>
#endif
#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif
#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif
#ifdef HAVE_STRING_H
#include <string.h>
#endif
#ifdef HAVE_GETOPT_H
#include <getopt.h>
#endif

#include "types.h"
#include "attrib.h"
#include "volume.h"
#include "bootsect.h"
#include "mft.h"
#include "device.h"
#include "logfile.h"
#include "utils.h"
/* #include "version.h" */
#include "logging.h"
#include "misc.h"

#ifdef NO_NTFS_DEVICE_DEFAULT_IO_OPS
#	error "No default device io operations!  Cannot build ntfsfix.  \
You need to run ./configure without the --disable-default-device-io-ops \
switch if you want to be able to build the NTFS utilities."
#endif

static const char *EXEC_NAME = "checkntfs";
//static const char OK[]       = "OK\n";
static const char FAILED[]   = "FAILED\n";

#define DEFAULT_SECTOR_SIZE 512

static struct {
	char *volume;
	BOOL no_action;
} opt;

/**
 * usage
 */
__attribute__((noreturn))
static void usage(void)
{
	ntfs_log_info("%s v%s \n"
		   "\n"
		   "Usage: %s device\n"
		   "    Attempt to check an NTFS partition.\n"
		   "\n"
		   "\n"
		   "For example: %s /dev/hda6\n\n",
		   EXEC_NAME, VERSION, EXEC_NAME,
		   EXEC_NAME);
	ntfs_log_info("%s%s", ntfs_bugs, ntfs_home);
	exit(1);
}

/**
 * version
 */
__attribute__((noreturn))
static void version(void)
{
	ntfs_log_info("%s v%s\n\n"
		   "Attempt to check an NTFS partition.\n\n"
		   "Copyright (c) 2000-2006 Anton Altaparmakov\n"
		   "Copyright (c) 2002-2006 Szabolcs Szakacsits\n"
		   "Copyright (c) 2007      x00186870 \n\n",
		   EXEC_NAME, VERSION);
	ntfs_log_info("%s\n%s%s", ntfs_gpl, ntfs_bugs, ntfs_home);
	exit(1);
}

/**
 * parse_options
 */
static void parse_options(int argc, char **argv)
{
	int c;
	static const char *sopt = "-hnV";
	static const struct option lopt[] = {
		{ "help",	no_argument,	NULL, 'h' },
		{ "no-action",	no_argument,	NULL, 'n' },
		{ "version",	no_argument,	NULL, 'V' },
		{ NULL, 0, NULL, 0 }
	};

	memset(&opt, 0, sizeof(opt));

	while ((c = getopt_long(argc, argv, sopt, lopt, NULL)) != -1) {
		switch (c) {
		case 1:	/* A non-option argument */
			if (!opt.volume)
				opt.volume = argv[optind - 1];
			else {
				ntfs_log_info("ERROR: Too many arguments.\n");
				usage();
			}
			break;
		case 'n':
			opt.no_action = TRUE;
			break;
		case 'h':
		case '?':
			usage();
			/* fall through */
		case 'V':
			version();
		default:
			ntfs_log_info("ERROR: Unknown option '%s'.\n", argv[optind - 1]);
			usage();
		}
	}

	if (opt.volume == NULL) {
		ntfs_log_info("ERROR: You must specify a device.\n");
		usage();
	}
}


static int check_ntfs_volume
(
	struct ntfs_device *dev
)
{
	s64 br;
    BOOL bIsNtfs = FALSE;
	NTFS_BOOT_SECTOR *bs;

	bs = ntfs_malloc(sizeof(NTFS_BOOT_SECTOR));
	if (!bs)
    {
		ntfs_log_error("Check Ntfs Volume: malloc ntfs boot sector failed.\n");
		return -1;
    }

	/* ...->open needs bracketing to compile with glibc 2.7 */
	if ((dev->d_ops->open)(dev, (opt.no_action) ? O_RDONLY: O_RDWR)) {
		ntfs_log_perror("Error opening '%s'", dev->d_name);
		goto error_exit;
	}

	/* Now read the bootsector. */
	br = ntfs_pread(dev, 0, sizeof(NTFS_BOOT_SECTOR), bs);

    ntfs_log_error("ntfs_pread br = %lld\n", (long long)br);

	if (br != sizeof(NTFS_BOOT_SECTOR)) 
    {
		ntfs_log_error("Check Ntfs Volume: Failed to read bootsector.\n");
		goto error_exit;

	}

    bIsNtfs = ntfs_boot_sector_is_ntfs(bs);
    if (FALSE == bIsNtfs)
    {
		ntfs_log_error("Check Ntfs Volume: Failed to read bootsector.\n");
		goto error_exit;
    }

	free(bs);
    return 0;

error_exit:
    free(bs);
    return -1;
}


static int check_ntfs(void)
{
	int ret = 0;                /* default success */
	struct ntfs_device *dev;

	ntfs_log_info("Check Ntfs: Attempting to check ntfs....\n");

	dev = ntfs_device_alloc(opt.volume, 0, &ntfs_device_default_io_ops,
						    NULL);

    ntfs_log_trace("Check Ntfs: opt.volume = %s\n", opt.volume);

	if (!dev) 
    {
		ntfs_log_info(FAILED);
		ntfs_log_perror("Check Ntfs: Failed to allocate device\n");
		return -1;
	}
    
	ret = check_ntfs_volume(dev);    
	if (ret)
    {
		ntfs_log_info(FAILED);
		ntfs_log_perror("Check Ntfs: Failed to startup volume\n");
        ntfs_device_free(dev);

        return -1;        
    }

	ntfs_device_free(dev);	
	return 0;
}

/**
 * main
 */
int main(int argc, char **argv)
{
	unsigned long mnt_flags;
	int ret = 1; /* failure */
	BOOL force = FALSE;

	ntfs_log_set_handler(ntfs_log_handler_outerr);

	parse_options(argc, argv);

	if (!ntfs_check_if_mounted(opt.volume, &mnt_flags)) 
    {
		if ((mnt_flags & NTFS_MF_MOUNTED) &&
				!(mnt_flags & NTFS_MF_READONLY) && !force) 
		{
			ntfs_log_error("Refusing to operate on read-write "
					"mounted device %s.\n", opt.volume);
			exit(1);
		}
	}
    else
    {
		ntfs_log_perror("Failed to determine whether %s is mounted",
				opt.volume);
    }

	ret = check_ntfs();
    if (ret)
    {
        ntfs_log_perror("device is not ntfs system.\n");
        exit(1);
    }

	ntfs_log_info("NTFS partition check processed successfully.\n");

	return 0;
}

