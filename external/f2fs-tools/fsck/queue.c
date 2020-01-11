#include "fsck.h"

#ifdef POSIX_FADV_WILLNEED
/*lint -save -e429 -e529 -e564 -e456*/
struct work_reada_arg {
	struct f2fs_sb_info *sbi;
	int type;
};
static struct work_reada_arg *args[MAX_TYPE] = {NULL, NULL};

void *work_reada_block(void *arg)
{
	struct f2fs_sb_info *sbi = ((struct work_reada_arg *)arg)->sbi;
	int type = ((struct work_reada_arg *)arg)->type;
	struct f2fs_fsck *fsck = F2FS_FSCK(sbi);
	struct ra_work *w, *t;
	struct list_head tmp_queue;

	for (; ;) {
		if (fsck->quit_thread[type])
			pthread_exit(NULL);

		pthread_mutex_lock(&fsck->mutex[type]);
		while (list_empty(&fsck->ra_queue[type])) {
			pthread_cond_wait(&fsck->cond[type], &fsck->mutex[type]);
			if (fsck->quit_thread[type]) {
				pthread_mutex_unlock(&fsck->mutex[type]);
				pthread_exit(NULL);
			}
		}
		/* move all works to tmp_queue */
		tmp_queue = fsck->ra_queue[type];
		tmp_queue.next->prev = &tmp_queue;
		tmp_queue.prev->next = &tmp_queue;
		INIT_LIST_HEAD(&fsck->ra_queue[type]);
		pthread_mutex_unlock(&fsck->mutex[type]);

		list_for_each_entry_safe(w, t, &tmp_queue, entry) {
			list_del(&w->entry);
			if (!fsck->quit_thread[type])
				dev_reada_block(w->blkaddr);
			free(w);
		}
	}
}

void init_reada_queue(struct f2fs_sb_info *sbi)
{
	struct f2fs_fsck *fsck = F2FS_FSCK(sbi);
	int i, ret;

	for (i = 0; i < MAX_TYPE; i++) {
		INIT_LIST_HEAD(&fsck->ra_queue[i]);
		fsck->quit_thread[i] = 0;
		pthread_cond_init(&fsck->cond[i], NULL);
		pthread_mutex_init(&fsck->mutex[i], NULL);

		args[i] = malloc(sizeof(struct work_reada_arg));
		ASSERT(args[i]);
		args[i]->sbi = sbi;
		args[i]->type = i;
		ret = pthread_create(&fsck->thread[i], NULL, work_reada_block, args[i]);
		ASSERT(ret == 0);
	}

	MSG(0, "Info: readahead queue is enabled\n");
}

void exit_reada_queue(struct f2fs_sb_info *sbi)
{
	struct f2fs_fsck *fsck = F2FS_FSCK(sbi);
	struct ra_work *w, *t;
	int i;

	/* tell thread to exit */
	for (i = 0; i < MAX_TYPE; i++) {
		fsck->quit_thread[i] = 1;
		pthread_cond_signal(&fsck->cond[i]);
	}
	for (i = 0; i < MAX_TYPE; i++) {
		pthread_join(fsck->thread[i], NULL);
		pthread_mutex_destroy(&fsck->mutex[i]);
		pthread_cond_destroy(&fsck->cond[i]);
		free(args[i]);
		list_for_each_entry_safe(w, t, &fsck->ra_queue[i], entry) {
			list_del(&w->entry);
			free(w);
		}
	}
}

void queue_reada_block(struct f2fs_sb_info *sbi, block_t blkaddr, int type)
{
	struct f2fs_fsck *fsck = F2FS_FSCK(sbi);
	struct ra_work *work;

	ASSERT(!(type != NODE && type != DATA));

	work = malloc(sizeof(struct ra_work));
	ASSERT(work);

	INIT_LIST_HEAD(&work->entry);
	work->blkaddr = blkaddr;

	pthread_mutex_lock(&fsck->mutex[type]);
	list_add_tail(&work->entry, &fsck->ra_queue[type]);
	pthread_mutex_unlock(&fsck->mutex[type]);

	pthread_cond_signal(&fsck->cond[type]);
}
/*lint -restore*/
#endif
