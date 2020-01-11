
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>
#include "test.h"

#define KB 1024

char *TCID = "mlock03";
int TST_TOTAL = 1;

static void setup(void);
static void cleanup(void);

int main(int argc, char *argv[])
{
	int lc;
	long from, to;
	long first = -1, last = -1;
	char b[KB];
	FILE *fp;

	tst_parse_opts(argc, argv, NULL, NULL);

	setup();

	for (lc = 0; TEST_LOOPING(lc); lc++) {
		fp = fopen("/proc/self/maps", "r");
		if (fp == NULL)
			tst_brkm(TBROK | TERRNO, cleanup, "fopen");
		while (!feof(fp)) {
			if (!fgets(b, KB - 1, fp))
				break;
			b[strlen(b) - 1] = '\0';
			sscanf(b, "%lx-%lx", &from, &to);

			/* Record the initial stack size. */
			if (lc == 0 && strstr(b, "[stack]") != NULL)
				first = (to - from) / KB;

			switch (lc & 1) {
			case 0:
				if (mlock((const void *)from, to - from) == -1)
					tst_resm(TINFO | TERRNO,
						 "mlock failed");
				break;
			case 1:
				if (munlock((void *)from, to - from) == -1)
					tst_resm(TINFO | TERRNO,
						 "munlock failed");
				break;
			default:
				break;
			}
			tst_resm(TINFO, "%s from %lx to %0lx",
				 (lc & 1) ? "munlock" : "mlock", from, to);

			/* Record the final stack size. */
			if (strstr(b, "[stack]") != NULL)
				last = (to - from) / KB;
		}
		fclose(fp);
	}
	tst_resm(TINFO, "starting stack size is %ld", first);
	tst_resm(TINFO, "final stack size is %ld", last);
	if (last < first)
		tst_resm(TFAIL, "stack size is decreased.");
	else
		tst_resm(TPASS, "stack size is not decreased.");

	cleanup();
	tst_exit();
}

void setup(void)
{
	tst_require_root();

	tst_sig(FORK, DEF_HANDLER, cleanup);
	TEST_PAUSE;
}

void cleanup(void)
{
}
