#ifndef _QUEUE_H_
#define _QUEUE_H_

#ifdef POSIX_FADV_WILLNEED
#include "list.h"

struct ra_work {
	struct list_head entry;
	block_t blkaddr;
};

/* queue.c */
extern void queue_reada_block(struct f2fs_sb_info *, block_t, int);
extern void init_reada_queue(struct f2fs_sb_info *);
extern void exit_reada_queue(struct f2fs_sb_info *);
#else
#define queue_reada_block(sbi, blkaddr, type) dev_reada_block(blkaddr)
#define init_reada_queue(sbi) MSG(0, "Info: readahead queue is not enabled\n")
#define exit_reada_queue(sbi)
#endif

#endif
