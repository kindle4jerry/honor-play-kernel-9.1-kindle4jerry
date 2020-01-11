/*
 * problem.h --- f2fs fsck problem error codes
 * This file may be redistributed under the terms of the GNU Public
 */

#ifndef _PROBLEM_H_
#define _PROBLEM_H_

#include <f2fs_log.h>

/*
 * DMD_F2FSCK_ERR is referenced to f2fsck_config defined in
 * vendor/huawei/chipset_common/chipsets/hisi/default/dmd/device_state_monitor.conf
 */
#define DMD_F2FSCK_ERR	0x37504b28

/* super block is invalid */
#define PR_INVALID_SUPER_BLOCK				0x01

/* checkpoint is invalid */
#define PR_INVALID_CHECKPOINT				0x02

/* checkpoint is polluted */
#define PR_POLLUTE_CHECKPOINT				0x03

/* build_segment_manager error */
#define PR_BUILD_SEGMENT_MANAGER_ERROR			0x04

/* build_node_manager error */
#define PR_BUILD_NODE_MANAGER_ERROR			0x05

/* sit vblocks big than sbi->blocks_per_seg */
#define PR_INVALID_SIT_VBLOCKS				0x06

/* invalid sit vblocks */
#define PR_INVALID_SEGNO				0x07

/* sit vblocks count is error */
#define PR_SIT_VBLOCKS_IS_ERROR				0x08

/* invalid sit type */
#define PR_INVALID_SIT_TYPE				0x09

/* invalid nat entry[0] */
#define PR_INVALID_NAT_ENTRY0				0x0A

/* invalid nat entry[1/2] */
#define PR_INVALID_NAT_ENTRY1_ENTRY2			0x0B

/* invalid ino or blkaddr */
#define PR_INVALID_INO_OR_BLKADDR			0x0C

/* check meta does not match */
#define PR_FSCK_META_MISMATCH				0x0D

/* sit segment count mismatch with total segment */
#define PR_SIT_SEGMENT_COUNT_MISMATCH_WITH_TOTAL	0x0E

/* nat valid node count mismatch with sit */
#define PR_NAT_NODE_COUNT_MISMATCH_WITH_SIT		0x0F

/* sit free segment count mismatch with cp */
#define PR_SIT_FREESEG_COUNT_MISMATCH_WITH_CP		0x10

/* nat valid node count mismatch with cp */
#define PR_NAT_NODE_COUNT_MISMATCH_WITH_CP		0x11

/* nat valid inode count mismatch with cp */
#define PR_NAT_INODE_COUNT_MISMATCH_WITH_CP		0x12

/* nat entry blkaddr is invalid */
#define PR_NODE_INVALID_BLKADDR				0x13

/* nat entry blkaddr not in sit area bitmap */
#define PR_NAT_BLKADDR_OUT_SIT_BITMAP			0x14

/* nat entry ino is invalid */
#define PR_INVALID_NID					0x15

/* nat entry ino not in nat area bitmap */
#define PR_NAT_INO_OUT_NAT_BITMAP			0x16

/* wrong orphan inode */
#define PR_ORPAHN_INODE_ERROR				0x17

/* ino is zero */
#define PR_INO_IS_ZERO					0x18

/* blkaddr is NEW_ADDR */
#define PR_BLKADDR_IS_NEW_ADDR				0x19

/* invalid sum node block */
#define PR_INVALID_SUM_NODE_BLOCK			0x1A

/* inode footer ino is not equal with nid */
#define PR_INODE_FOOTER_INO_NOT_EQUAL_NID		0x1B

/* node ino is not equal with node footer ino */
#define PR_NODE_INO_NOT_EQUAL_FOOTER_INO		0x1C

/*  non-inode footer ino is equal with nid */
#define PR_NON_INODE_FOOTER_INO_EQUAL_NID		0x1D

/* node nid is not equal with node footer nid */
#define PR_NODE_NID_NOT_EQUAL_FOOTER_NID		0x1E

/* xattr offset is invalid */
#define PR_INVALID_XATTR_OFFSET				0x1F

/* duplicate node blkaddr in main bitmap */
#define PR_DUPLICATE_NODE_BLKADDR_IN_MAIN_BITMAP	0x20

/* direct name mismatch with node block i_name */
#define PR_DIR_NAME_MISMATCH_I_NAME			0x21

/* inode mismatch mode */
#define PR_INODE_MISMATCH_MODE				0x22

/* duplicate orphan or xattr nid */
#define PR_DUPLICATE_ORPHAN_OR_XATTR_NID		0x23

/* i_link num is error */
#define PR_HARD_LINK_NUM_IS_ERROR			0x24

/* inline data addr[0] is not zero */
#define PR_INLINE_DATA_ADDR0_NOT_ZERO			0x25

/* inline data has not data exist */
#define PR_INLINE_DATA_INEXISTENCE			0x26

/* inline dentry is invalid */
#define PR_INVALID_INLINE_DENTRY			0x27

/* invalid extent values */
#define PR_INVALID_EXTENT_VALUE				0x28

/* invalid i_blocks */
#define PR_INVALID_I_BLOCKS				0x29

/* invalid i_link */
#define PR_INVALID_I_LINKS				0x2A

/* dot or dotdot is error */
#define PR_LOST_DOT_OR_DOTDOT				0x2B

/* orphan inode has i_links */
#define PR_ORPHAN_INODE_HAS_I_LINKS			0x2C

/* invalid sum data block */
#define PR_INVALID_SUM_DATA_BLOCK			0x2D

/* invalid data blkaddr is not in sit bitmap */
#define PR_DATA_BLKADDR_OUT_SIT_BITMAP			0x2E

/* duplicate data blkaddr in main bitmap */
#define PR_DUPLICATE_DATA_BLKADDR_IN_MAIN_BITMAP	0x2F

/* data block sit type is error */
#define PR_SIT_TYPE_IS_ERROR				0x30

/* invalid ftype in dentry */
#define PR_INVALID_FTYPE				0x31

/* file name len is zero */
#define PR_NAME_LEN_IS_ZERO				0x32

/* file name len is zero */
#define PR_INVALID_HASH_CODE				0x33

/* nid is unreachable */
#define PR_NID_IS_UNREACHABLE				0x34

/* nid has more unreachable links */
#define PR_NID_HAS_MORE_UNREACHABLE_LINKS		0x35

/* next block offset is not free */
#define PR_CUR_NEXT_BLK_IS_NOT_FREE			0x36

/* LFS must have free section */
#define PR_LFS_HAS_NO_FREE_SECTION			0x37

#endif
