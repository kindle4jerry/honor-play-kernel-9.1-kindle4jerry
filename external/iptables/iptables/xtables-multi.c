#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xshared.h"

#include "xtables-multi.h"

#ifdef ENABLE_IPV4
#include "iptables-multi.h"
#endif

#ifdef ENABLE_IPV6
#include "ip6tables-multi.h"
#endif

#ifdef ENABLE_NFTABLES
#include "xtables-multi.h"
#endif

#include <log/log.h>
#include <libgen.h>
#include <xcollie.h>

static const struct subcommand multi_subcommands[] = {
#ifdef ENABLE_IPV4
	{"iptables",            iptables_main},
	{"main4",               iptables_main},
	{"iptables-save",       iptables_save_main},
	{"save4",               iptables_save_main},
	{"iptables-restore",    iptables_restore_main},
	{"restore4",            iptables_restore_main},
#endif
	{"iptables-xml",        iptables_xml_main},
	{"xml",                 iptables_xml_main},
#ifdef ENABLE_IPV6
	{"ip6tables",           ip6tables_main},
	{"main6",               ip6tables_main},
	{"ip6tables-save",      ip6tables_save_main},
	{"save6",               ip6tables_save_main},
	{"ip6tables-restore",   ip6tables_restore_main},
	{"restore6",            ip6tables_restore_main},
#endif
#ifdef ENABLE_NFTABLES
	{"xtables",             xtables_main},
	{"xtables-save",        xtables_save_main},
	{"xtables-restore",     xtables_restore_main},
	{"xtables-config",      xtables_config_main},
	{"xtables-events",      xtables_events_main},
	{"xtables-arp",		xtables_arp_main},
	{"xtables-ebtables",	xtables_eb_main},
#endif
	{NULL},
};

int main(int argc, char **argv)
{
    int ret;
    xcollie_t id;

    const char *cmd = basename(argv[0]);

    ALOGE("iptables cmd:%s",cmd);

    if (!strcmp(cmd, "iptables") || !strcmp(cmd, "ip6tables"))
        xcollie_init();
    id = xcollie_start_ex(8,NULL,NULL,XCOLLIE_FLAG_LOG | XCOLLIE_FLAG_BACKTRACE);
    ret = subcmd_main(argc, argv, multi_subcommands);
    xcollie_end(id);

    ALOGE("iptable exit,ret = %d",ret);
    return ret;
}
