

#define _GNU_SOURCE
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include "mem.h"

#define MAP_COUNT_DEFAULT	1024
#define MAX_MAP_COUNT		65536L

static long old_max_map_count;
static long old_overcommit;
static struct utsname un;

static void setup(void)
{
	if (access(PATH_SYSVM "max_map_count", F_OK) != 0)
		tst_brk(TBROK | TERRNO,
			 "Can't support to test max_map_count");

	old_max_map_count = get_sys_tune("max_map_count");
	old_overcommit = get_sys_tune("overcommit_memory");
	set_sys_tune("overcommit_memory", 2, 1);

	if (uname(&un) != 0)
		tst_brk(TBROK | TERRNO, "uname error");
}

static void cleanup(void)
{
	set_sys_tune("overcommit_memory", old_overcommit, 0);
	set_sys_tune("max_map_count", old_max_map_count, 0);
}

/* This is a filter to exclude map entries which aren't accounted
 * for in the vm_area_struct's map_count.
 */
static bool filter_map(const char *line)
{
	char buf[BUFSIZ];
	int ret;

	ret = sscanf(line, "%*p-%*p %*4s %*p %*2d:%*2d %*d %s", buf);
	if (ret != 1)
		return false;

#if defined(__x86_64__) || defined(__x86__)
	/* On x86, there's an old compat vsyscall page */
	if (!strcmp(buf, "[vsyscall]"))
		return true;
#elif defined(__ia64__)
	/* On ia64, the vdso is not a proper mapping */
	if (!strcmp(buf, "[vdso]"))
		return true;
#elif defined(__arm__)
	/* Skip it when run it in aarch64 */
	if ((!strcmp(un.machine, "aarch64"))
	|| (!strcmp(un.machine, "aarch64_be")))
		return false;

	/* Older arm kernels didn't label their vdso maps */
	if (!strncmp(line, "ffff0000-ffff1000", 17))
		return true;
#endif

	return false;
}

static long count_maps(pid_t pid)
{
	FILE *fp;
	size_t len;
	char *line = NULL;
	char buf[BUFSIZ];
	long map_count = 0;

	snprintf(buf, BUFSIZ, "/proc/%d/maps", pid);
	fp = fopen(buf, "r");
	if (fp == NULL)
		tst_brk(TBROK | TERRNO, "fopen %s", buf);
	while (getline(&line, &len, fp) != -1) {
		/* exclude vdso and vsyscall */
		if (filter_map(line))
			continue;
		map_count++;
	}
	fclose(fp);

	return map_count;
}

static void max_map_count_test(void)
{
	int status;
	pid_t pid;
	long max_maps;
	long map_count;
	long max_iters;
	long memfree;

	/*
	 * XXX Due to a possible kernel bug, oom-killer can be easily
	 * triggered when doing small piece mmaps in huge amount even if
	 * enough free memory available. Also it has been observed that
	 * oom-killer often kill wrong victims in this situation, we
	 * decided to do following steps to make sure no oom happen:
	 * 1) use a safe maximum max_map_count value as upper-bound,
	 *    we set it 65536 in this case, i.e., we don't test too big
	 *    value;
	 * 2) make sure total mapping isn't larger tha
	 *        CommitLimit - Committed_AS
	 *    and set overcommit_memory to 2, this could help mapping
	 *    returns ENOMEM instead of triggering oom-killer when
	 *    memory is tight. (When there are enough free memory,
	 *    step 1) will be used first.
	 * Hope OOM-killer can be more stable oneday.
	 */
	memfree = SAFE_READ_MEMINFO("CommitLimit:") - SAFE_READ_MEMINFO("Committed_AS:");
	/* 64 used as a bias to make sure no overflow happen */
	max_iters = memfree / sysconf(_SC_PAGESIZE) * 1024 - 64;
	if (max_iters > MAX_MAP_COUNT)
		max_iters = MAX_MAP_COUNT;

	max_maps = MAP_COUNT_DEFAULT;
	while (max_maps <= max_iters) {
		set_sys_tune("max_map_count", max_maps, 1);

		switch (pid = SAFE_FORK()) {
		case 0:
			while (mmap(NULL, 1, PROT_READ,
				    MAP_SHARED | MAP_ANONYMOUS, -1, 0)
			       != MAP_FAILED) ;
			if (raise(SIGSTOP) != 0)
				tst_brk(TBROK | TERRNO, "raise");
			exit(0);
		default:
			break;
		}
		/* wait child done mmap and stop */
		SAFE_WAITPID(pid, &status, WUNTRACED);
		if (!WIFSTOPPED(status))
			tst_brk(TBROK, "child did not stopped");

		map_count = count_maps(pid);
		/* Note max_maps will be exceeded by one for
		 * the sysctl setting of max_map_count. This
		 * is the mm failure point at the time of
		 * writing this COMMENT!
		*/
		if (map_count == (max_maps + 1))
			tst_res(TPASS, "%ld map entries in total "
				 "as expected.", max_maps);
		else
			tst_res(TFAIL, "%ld map entries in total, but "
				 "expected %ld entries", map_count, max_maps);

		/* make child continue to exit */
		SAFE_KILL(pid, SIGCONT);
		SAFE_WAITPID(pid, &status, 0);

		max_maps = max_maps << 1;
	}
}

static struct tst_test test = {
	.needs_root = 1,
	.forks_child = 1,
	.setup = setup,
	.cleanup = cleanup,
	.test_all = max_map_count_test,
};
