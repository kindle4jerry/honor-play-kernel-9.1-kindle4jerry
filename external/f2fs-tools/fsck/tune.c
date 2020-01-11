/**
 * tune.c
 *
 * Copyright (C) 2018 Huawei Ltd.
 * Witten by:
 *   Junling Zheng <zhengjunling@huawei.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <ctype.h>
#include "fsck.h"

struct feature_token {
	const char *name;
	u32 val;
};

struct feature_token feature_table[] = {
	{"encrypt", F2FS_FEATURE_ENCRYPT},
	{NULL, 0},
};

static inline u32 match_feature(char *feature)
{
	struct feature_token *p;
	for (p = feature_table; p->name && strcmp(p->name, feature); p++)
		;
	return p->val;
}

static inline void clear_feature_bits(struct f2fs_sb_info *sbi, u32 feature_mask)
{
	sbi->raw_super->feature &= cpu_to_le32(~feature_mask);
}

static inline void set_feature_bits(struct f2fs_sb_info *sbi, u32 feature_mask)
{
	sbi->raw_super->feature |= cpu_to_le32(feature_mask);
}

static int do_tune_feature(struct f2fs_sb_info *sbi, char *features)
{
	char op, *buf, *sub, *next;
	u32 feature_bit = 0;
	int ret = 0;

	buf = calloc(strlen(features) + 1, sizeof(char));
	ASSERT(buf);
	strncpy(buf, features, strlen(features) + 1);

	for (sub = buf; sub && *sub; sub = next ? next + 1 : NULL) {
		/* Skip the beginning blanks */
		while (*sub && *sub == ' ')
			sub++;
		next = sub;
		/* Skip a feature word */
		while (*next && *next != ' ' && *next != ',')
			next++;

		if (*next == 0)
			next = NULL;
		else
			*next = 0;

		if (!isalnum(*sub)) {
			op = *sub;
			sub++;
		} else {
			op = '+';
		}

		feature_bit = match_feature(sub);
		if (!feature_bit) {
			ERR_MSG("\tError: Not support tuning feature %s\n", sub);
			ret = -1;
			goto out;
		}

		switch (op) {
		case '-':
		case '^':
			clear_feature_bits(sbi, feature_bit);
			break;
		case '+':
			set_feature_bits(sbi, feature_bit);
			break;
		default:
			ERR_MSG("\tError: Wrong operation %c\n", op);
			ret = -1;
			goto out;
		}
	}

out:
	free(buf);
	return ret;
}

int f2fs_tune(struct f2fs_sb_info *sbi)
{
	int ret;
	u32 crc = 0;
	u32 old_crc = 0;
	__le32 old_feature;

	/* Get and validate sbi->raw_super */
	ret = validate_super_block(sbi, 0);
	if (ret) {
		ret = validate_super_block(sbi, 1);
		if (ret)
			return -1;
	}
	old_feature = sbi->raw_super->feature;

	/* Tune features in sb */
	if (do_tune_feature(sbi, c.tune_feature)) {
		ERR_MSG("\tError: Tune feature failed!\n");
		return -1;
	}

	if (sbi->raw_super->feature == old_feature) {
		MSG(0, "Info: No features have been tuned!\n");
		return 0;
	}

	/* Print features in sb */
	print_sb_state(sbi->raw_super);
	MSG(0, "Info: Tune feature successfully!\n");

	/* Recalculate CRC */
	old_crc = le32_to_cpu(sbi->raw_super->crc);
	if (old_crc) {
		crc = f2fs_cal_crc32(F2FS_SUPER_MAGIC, sbi->raw_super, CHECKSUM_OFFSET_SB);
		sbi->raw_super->crc = cpu_to_le32(crc);
		MSG(0, "Info: update CRC successfully (0x%x --> 0x%x)\n", old_crc, crc);
	}

	/* Write raw_super back to both 1st and 2nd sb on disk */
	ret = dev_write(sbi->raw_super, F2FS_SUPER_OFFSET,
				sizeof(struct f2fs_super_block));
	ASSERT(ret >= 0);
	ret = dev_write(sbi->raw_super, F2FS_SUPER_OFFSET + F2FS_BLKSIZE,
						sizeof(struct f2fs_super_block));
	ASSERT(ret >= 0);
	MSG(0, "Info: Writeback successfully!\n");

	return ret;
}
