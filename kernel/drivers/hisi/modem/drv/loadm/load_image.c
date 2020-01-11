/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "product_config.h"
#include <linux/version.h>
#include <linux/io.h>
#include <linux/jiffies.h>
#include <linux/slab.h>
#include <linux/file.h>
#include <linux/fs.h>
#include <linux/zlib.h>
#include <linux/dma-mapping.h>
#include <asm/dma-mapping.h>
#include <asm/cacheflush.h>
#include <soc_onchiprom.h>
#include <bsp_shared_ddr.h>
#include <bsp_reset.h>
#include <bsp_sec.h>
#include <bsp_rfile.h>
#include <bsp_version.h>
#include <bsp_ddr.h>
#include <bsp_efuse.h>
#include "load_image.h"
#include "modem_dtb.h"

#include "securec.h"

/* Dalls֮���ֻ���MBB�ںϴ��� */

#define SECBOOT_BUFLEN  (0x100000)      /*1MB*/

#define MODEM_IMAGE_PATH    "/modem_fw/"
#define MODEM_IMAGE_PATH_VENDOR    "/vendor/modem/modem_fw/"
#define VRL_SIZE                    (0x1000)  /*VRL 4K*/

char* modem_fw_dir = MODEM_IMAGE_PATH;

/* ����ȫOS��Ҫ��ȫ���أ�Ԥ�������ڴ棬������ϵͳ��ʱ�����к󣬵�����λʱ�������벻�������ڴ� */
static  u8 SECBOOT_BUFFER[SECBOOT_BUFLEN];

struct image_type_name
{
    enum SVC_SECBOOT_IMG_TYPE etype;
    u32 run_addr;
    u32 ddr_size;
    const char* name;
};

struct image_type_name modem_images[] =
{
    {MODEM, DDR_MCORE_ADDR,         DDR_MCORE_SIZE,         "balong_modem.bin"},
    {HIFI,  DDR_HIFI_ADDR,          DDR_HIFI_SIZE,          "hifi.img"},/* Ԥ�� */
    {DSP,   DDR_TLPHY_IMAGE_ADDR,   DDR_TLPHY_IMAGE_SIZE,   "lphy.bin"},
    {XDSP,  DDR_CBBE_IMAGE_ADDR,    DDR_CBBE_IMAGE_SIZE,    "xphy_mcore.bin"},
    {TAS,   0,                      0,                      "tas.bin"},
    {WAS,   0,                      0,                      "was.bin"},
    {CAS,   0,                      0,                      "cas.bin"}, /* Ԥ�� */
    {MODEM_DTB, DDR_MCORE_DTS_ADDR, DDR_MCORE_DTS_SIZE,     "modem_dt.img"},
    {SOC_MAX,       0,              0,                      ""},
};

/*lint -save -e651 -e708 -e570 -e64 -e785*/
static DEFINE_MUTEX(load_proc_lock);
/*lint -restore */


 int modem_dir_init(void)
{

    if(!bsp_access((s8*) MODEM_IMAGE_PATH_VENDOR,0))
    {
         modem_fw_dir = MODEM_IMAGE_PATH_VENDOR;
     }
     else  if(!bsp_access((s8*) MODEM_IMAGE_PATH,0))
     {
          modem_fw_dir = MODEM_IMAGE_PATH;
     }
     else
     {
         sec_print_err("error: path /vendor/modem/modem_fw/  and path /modem_fw/ can't access, return\n" );
         return -EACCES;
     }

    sec_print_info("info: path %s   can access\n",modem_fw_dir );
    return 0;
}

static int get_image(struct image_type_name** image, enum SVC_SECBOOT_IMG_TYPE etype,u32 run_addr, u32 ddr_size)
{
    unsigned int i;
    struct image_type_name* img;

    img = modem_images;
    for(i=0; i<(sizeof(modem_images)/sizeof(struct image_type_name)); i++)
    {
        if(img->etype == etype)
        {
            break;
        }
        img++;
    }
    if(i == (sizeof(modem_images)/sizeof(struct image_type_name)))
    {
        /* cov_verified_start */
        sec_print_err("can not find image of type id %d\n", etype);
        return -ENOENT;
        /* cov_verified_stop */
    }
    /*�����tas was����Ļ�Ҫ*/
    if(!img->run_addr)
    {
        img->run_addr = run_addr ;
        img->ddr_size = ddr_size ;
    }
    *image = (struct image_type_name*)img;

    return 0;
}

static int get_file_size(const char *filename)
{
    struct rfile_stat_stru st;
    s32 ret;
    memset_s(&st, sizeof(st), 0x00, sizeof (st));
    ret = bsp_stat((s8*)filename, (void *)&st);
    if(ret)
    {
        /* cov_verified_start */
        sec_print_err("file bsp_stat error .\n");
        return ret;
        /* cov_verified_stop */
    }

    return (int)st.size;
}

static int get_file_name(char *file_name, const struct image_type_name *image, bool *is_sec)
{
    /* ������sec_��ͷ�İ�ȫ���� */
    *is_sec = true;
    file_name[0] = '\0';
    strncat(file_name, modem_fw_dir, strlen(modem_fw_dir));
    strncat(file_name, "sec_", strlen("sec_"));
    strncat(file_name, image->name, strlen(image->name));
    sec_print_info("loading %s  image\n", file_name);
    if(bsp_access((s8*) file_name, RFILE_RDONLY))
    {
        sec_print_info("file %s can't access, try unsec image\n", file_name);

        /* �����Էǰ�ȫ���� */
        *is_sec = false;
        file_name[0] = '\0';
        strncat(file_name, modem_fw_dir, strlen(modem_fw_dir));
        strncat(file_name, image->name, strlen(image->name));

        if(bsp_access((s8*) file_name, RFILE_RDONLY))
        {
            sec_print_err("error: file %s can't access, return\n", file_name);
            return -EACCES;
        }
    }

    return 0;
}

static int read_file(const char *file_name, unsigned int offset,
        unsigned int length, char *buffer)
{
    struct file * fp;
    int retval;
    loff_t file_pos = offset;
    fp = filp_open(file_name, O_RDONLY, 0600);
    if ((!fp) || (IS_ERR(fp))) {
        /* cov_verified_start */
        retval = (int)PTR_ERR(fp);
        sec_print_err("filp_open(%s) failed, ret:%d", file_name, retval);
        return retval;
        /* cov_verified_stop */
    }


#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 0))
    retval = kernel_read(fp, buffer, (size_t)length, &file_pos);
#else
    retval = kernel_read(fp, file_pos, buffer, (unsigned long)length);
#endif
    if (retval != (int)length) {
        /* cov_verified_start */
        sec_print_err("kernel_read(%s) failed, retval %d, require len %u\n",
            file_name, retval, length);
        if (retval >= 0)
            retval = -EIO;
        /* cov_verified_stop */
    }
#if (LINUX_VERSION_CODE < KERNEL_VERSION(4, 14, 0))
    if(fp->f_inode)
    {
        invalidate_mapping_pages(fp->f_inode->i_mapping, 0, -1);/*lint !e747 !e570*/
    }
#endif
    filp_close(fp, NULL);
    return retval;
}
int gzip_header_check(unsigned char* zbuf)
{
    if (zbuf[0] != 0x1f || zbuf[1] != 0x8b || zbuf[2] != 0x08) {
        return 0;
    } else {
        return 1;
    }
}



static TEEC_Session load_session;
static TEEC_Context load_context;

/*
 * Function name:TEEK_init.
 * Discription:Init the TEEC and get the context
 * Parameters:
 *    @ session: the bridge from unsec world to sec world.
 *    @ context: context.
 * return value:
 *    @ TEEC_SUCCESS-->success, others-->failed.
 */
static int TEEK_init(void)
{
    TEEC_Result result;
    TEEC_UUID svc_uuid = TEE_SERVICE_SECBOOT;
    TEEC_Operation operation = {0};
    const char* package_name = "sec_boot";
    u32 root_id = 0;

    result = TEEK_InitializeContext(
            NULL,
            &load_context);

    if(result != TEEC_SUCCESS) {
        /* cov_verified_start */
        sec_print_err("TEEK_InitializeContext failed, result %#x\n", result);
        goto error;
        /* cov_verified_stop */
    }

    operation.started = 1;
    operation.cancel_flag = 0;
    operation.paramTypes =
        (u32)TEEC_PARAM_TYPES(TEEC_NONE, TEEC_NONE, TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT);/*lint !e845*/

    operation.params[2].tmpref.buffer = (void *)(&root_id);
    operation.params[2].tmpref.size = sizeof(root_id);
    operation.params[3].tmpref.buffer = (void *)(package_name);
    operation.params[3].tmpref.size = strlen(package_name) + 1;
    result = TEEK_OpenSession(
            &load_context,
            &load_session,
            &svc_uuid,
            TEEC_LOGIN_IDENTIFY,
            NULL,
            &operation,
            NULL);

    if (result != TEEC_SUCCESS)
    {
        /* cov_verified_start */
        sec_print_err("TEEK_OpenSession failed, result %#x\n", result);
        TEEK_FinalizeContext(&load_context);
        /* cov_verified_stop */
    }

error:

    return (int)result;
}

static void TEEK_uninit(void)
{
    TEEK_CloseSession(&load_session);
    TEEK_FinalizeContext(&load_context);
}


/*
 * Function name:trans_vrl_to_os.
 * Discription:transfer vrl data to sec_OS
 * Parameters:
 *    @ session: the bridge from unsec world to sec world.
 *    @ image: the data of the image to transfer.
 *    @ buf: the buf in  kernel to transfer
 *    @ size: the size to transfer.
 * return value:
 *    @ TEEC_SUCCESS-->success, others--> failed.
 */
static int trans_vrl_to_os(enum SVC_SECBOOT_IMG_TYPE  image,
          void * buf,
          const unsigned int size)
{
    TEEC_Session *session = &load_session;
    TEEC_Result result;
    TEEC_Operation operation;
    u32 origin;

    operation.started = 1;
    operation.cancel_flag = 0;
    operation.paramTypes =
        (u32)TEEC_PARAM_TYPES(TEEC_VALUE_INPUT, TEEC_MEMREF_TEMP_INPUT, TEEC_NONE, TEEC_NONE);/*lint !e845*/

    operation.params[0].value.a = image;
    operation.params[1].tmpref.buffer = (void *)buf;
    operation.params[1].tmpref.size = size;

    result = TEEK_InvokeCommand(
                session,
                SECBOOT_CMD_ID_COPY_VRL_TYPE,
                &operation,
                &origin);
    if (result != TEEC_SUCCESS) {
        /* cov_verified_start */
        sec_print_err("invoke failed, result %#x\n", result);
        /* cov_verified_stop */
    }

    return (int)result;
}

/*
 * Function name:trans_data_to_os.
 * Discription:transfer image data to sec_OS
 * Parameters:
 *    @ session: the bridge from unsec world to sec world.
 *    @ image: the data of the image to transfer.
 *    @ run_addr: the image entry address.
 *    @ buf: the buf in  kernel to transfer
 *    @ offset: the offset to run_addr.
 *    @ size: the size to transfer.
 * return value:
 *    @ TEEC_SUCCESS-->success, others--> failed.
 */
static int trans_data_to_os(enum SVC_SECBOOT_IMG_TYPE  image,
                        u32 run_addr,
                        void * buf,
                        const unsigned int offset,
                        const unsigned int size)
{
    TEEC_Session *session = &load_session;
    TEEC_Result result;
    TEEC_Operation operation;
    u32 origin;
    unsigned long paddr;
    paddr = MDDR_FAMA(run_addr);

    operation.started = 1;
    operation.cancel_flag = 0;
    operation.paramTypes =
        (u32)TEEC_PARAM_TYPES(TEEC_VALUE_INPUT, TEEC_VALUE_INPUT, TEEC_VALUE_INPUT, TEEC_VALUE_INPUT);/*lint !e845*/

    operation.params[0].value.a = image;
    operation.params[0].value.b = (u32)(paddr & 0xFFFFFFFF);;
    operation.params[1].value.a = (u32)((u64)paddr >> 32);/* �ֻ���MBB ���� */
    operation.params[1].value.b = offset;
    operation.params[2].value.a = (u32)virt_to_phys(buf);/* �ֻ���MBB ���� */
    operation.params[2].value.b = (u64)virt_to_phys(buf) >> 32;/* �ֻ���MBB ���� */
    operation.params[3].value.a = size;
    result = TEEK_InvokeCommand(
                session,
                SECBOOT_CMD_ID_COPY_DATA_TYPE,
                &operation,
                &origin);
    if (result != TEEC_SUCCESS) {
        /* cov_verified_start */
        sec_print_err("invoke failed, result %#x\n", result);
        /* cov_verified_stop */
    }

    return (int)result;
}

/*
 * Function name:start_soc_image.
 * Discription:start the image verification, if success, unreset the soc
 * Parameters:
 *    @ session: the bridge from unsec world to sec world.
 *    @ image: the image to verification and unreset
 *    @ run_addr: the image entry address
 * return value:
 *    @ TEEC_SUCCESS-->success, others-->failed.
 */
static int verify_soc_image(enum SVC_SECBOOT_IMG_TYPE  image,
                        u32 run_addr)
{
    TEEC_Session *session = &load_session;
    TEEC_Result result;
    TEEC_Operation operation;
    u32 origin;
    unsigned long paddr;
    int ret;
    paddr = MDDR_FAMA(run_addr);

    ret = bsp_efuse_write_prepare();
    if(ret)
    {
        return ret;
    }
    operation.started = 1;
    operation.cancel_flag = 0;
    operation.paramTypes =
        (u32)TEEC_PARAM_TYPES(TEEC_VALUE_INPUT, TEEC_VALUE_INPUT, TEEC_NONE, TEEC_NONE);/*lint !e845*/

     operation.params[0].value.a = image;
     operation.params[0].value.b = 0;/*SECBOOT_LOCKSTATE , not used currently*/
     operation.params[1].value.a = (u32)(paddr & 0xFFFFFFFF);
     operation.params[1].value.b = (u32)((u64)paddr >> 32);/* �ֻ���MBB ���� */
     result = TEEK_InvokeCommand(session,
                                   SECBOOT_CMD_ID_VERIFY_DATA_TYPE,
                                    &operation,
                                    &origin);
     if (result != TEEC_SUCCESS){
        /* cov_verified_start */
        sec_print_err("start  failed, result is 0x%x!\n", result);
        /* cov_verified_stop */
    }
    bsp_efuse_write_complete();
    return (int)result;
}

/******************************************************************************
Function:       load_data_to_secos
Description:    ��ָ��ƫ�ƿ�ʼ����ָ����С�ľ���
Input:
            part_name   - Ҫ���;��������
            offset    - ƫ�Ƶ�ַ
            sizeToRead  - ���������Ҫд��ľ����bytes��С

Output:         none
Return:         SEC_OK: OK  SEC_ERROR: ERROR��
******************************************************************************/
static int load_data_to_secos(const char* file_name, u32 offset, u32 size,
            const struct image_type_name* image, bool is_sec)
{
    int ret;
    int read_bytes;
    int readed_bytes;
    int remain_bytes;
    u32 file_offset = 0;
    u32 skip_offset = 0;
    u32 load_position_offset = 0;

    /* ��ȡָ��ƫ�Ƶ�ָ����С */
    if(0 != offset)
    {
        skip_offset = offset;
        remain_bytes = (int)size;
    }
    else    /* ��ȡ�����ļ� */
    {
        remain_bytes = get_file_size(file_name);
        if (remain_bytes <=0)
        {
            sec_print_err("error file_size 0x%x\n", remain_bytes);
            return remain_bytes;
        }

        if(is_sec)
        {
            if(remain_bytes <= VRL_SIZE)
            {
                sec_print_err("error file_size (0x%x) less than VRL_SIZE\n", remain_bytes);
                return -EIO;
            }
            remain_bytes -= VRL_SIZE;
            skip_offset = VRL_SIZE;
        }
    }

    /* ����ȡ�Ĵ�С�Ƿ񳬹�ddr������С */
    if((u32)remain_bytes > image->ddr_size)
    {
        /* cov_verified_start */
        sec_print_err("remain_bytes larger than ddr size:  remain_bytes 0x%x > ddr_size 0x%x!\n", remain_bytes, image->ddr_size);
        return -ENOMEM;
        /* cov_verified_stop */
    }

    /*split the size to be read to each SECBOOT_BUFLEN bytes.*/
    while (remain_bytes)
    {
        if (remain_bytes > SECBOOT_BUFLEN)
            read_bytes = SECBOOT_BUFLEN;
        else
            read_bytes = remain_bytes;

        readed_bytes = read_file(file_name, skip_offset + file_offset, (u32)read_bytes, (s8 *)SECBOOT_BUFFER);
        if (readed_bytes < 0 || readed_bytes != read_bytes) {
            sec_print_err("read_file %s err: readed_bytes 0x%x\n", file_name, readed_bytes);
            return readed_bytes;
        }

        if ((!load_position_offset) && (image->etype == MODEM)) {
            /* ������gzip��ʽ��ѹ���������DDR�ռ����λ�� */
            load_position_offset = (u32)(image->ddr_size - (u32)remain_bytes);
        }
        if ((!load_position_offset) && (image->etype == MODEM_DTB)) {
            /* ������gzip��ʽ��ѹ���������DDR�ռ����λ�� */
            load_position_offset = (u32)(image->ddr_size - (u32)remain_bytes);
        }

        ret = trans_data_to_os(image->etype, image->run_addr,  (void *)(SECBOOT_BUFFER), load_position_offset+file_offset, (u32)read_bytes);
        sec_print_info("trans data ot os: etype 0x%x ,load_offset 0x%x, to secos file_offset 0x%x, bytes 0x%x success\n",
            image->etype, load_position_offset+file_offset, file_offset, read_bytes);

        if (ret)
        {
            /* cov_verified_start */
            sec_print_err("modem image trans to os is failed, error code 0x%x\n", ret);
            return ret;
            /* cov_verified_stop */
        }

        remain_bytes -= read_bytes;
        file_offset += (u32)read_bytes;
    }

    return SEC_OK;
}

static int ccpu_reset(enum SVC_SECBOOT_IMG_TYPE  image)
{
    TEEC_Session *session = &load_session;
    TEEC_Result result;
    TEEC_Operation operation;
    u32 origin;

    operation.started = 1;
    operation.cancel_flag = 0;

    operation.paramTypes =
        (u32)TEEC_PARAM_TYPES(TEEC_VALUE_INPUT, TEEC_NONE, TEEC_NONE, TEEC_NONE);/*lint !e845*/

    operation.params[0].value.a = image;
    result = TEEK_InvokeCommand(
                session,
                SECBOOT_CMD_ID_RESET_IMAGE,
                &operation,
                &origin);
    if (result != TEEC_SUCCESS) {
        /* cov_verified_start */
        sec_print_err("invoke failed, result %#x\n", result);
        /* cov_verified_stop */
    }

    return (int)result;
}

s32 load_image(enum SVC_SECBOOT_IMG_TYPE ecoretype, u32 run_addr, u32 ddr_size)
{
    s32 ret;
    bool is_sec;
    char file_name[256] = {0};
    int readed_bytes;
    struct image_type_name *image;

    ret = get_image(&image, ecoretype, run_addr, ddr_size);
    if(ret)
    {
        /* cov_verified_start */
        sec_print_err("can't find image\n");
        return ret;
        /* cov_verified_stop */
    }

    if(!run_addr)
    {
        run_addr = image->run_addr;
    }

    ret = get_file_name(file_name, image, &is_sec);
    if(ret)
    {
        /* cov_verified_start */
        sec_print_err("can't find image\n");
        return ret;
        /* cov_verified_stop */
    }
    sec_print_info("find file %s, is_sec: %d\n", file_name, is_sec);

    /*load vrl data to sec os*/
    if(is_sec)
    {
        readed_bytes = read_file(file_name, 0, VRL_SIZE, (char*)SECBOOT_BUFFER);
        if(readed_bytes < 0 || readed_bytes != VRL_SIZE)
        {
            sec_print_err("read_file %s error, readed_bytes 0x%x!\n", file_name, readed_bytes);
            ret = readed_bytes;
            goto error;
        }

        ret = trans_vrl_to_os(image->etype, (void *)(SECBOOT_BUFFER), VRL_SIZE);
        if(ret)
        {
            /* cov_verified_start */
            sec_print_err("trans_vrl_to_os error, ret 0x%x!\n", ret);
            goto error;
            /* cov_verified_stop */
        }
        sec_print_err("trans vrl to secos success\n");
    }

    /* load image data to sec os */
    ret = load_data_to_secos(file_name, 0, 0, image, is_sec);
    if(ret)
    {
        /* cov_verified_start */
        sec_print_err("load image %s to secos failed, ret = 0x%x\n", file_name, ret);
        goto error;
        /* cov_verified_stop */
    }
    sec_print_err("load image %s to secos success\n", file_name);

    /*end of trans all data, start verify*/
    ret = verify_soc_image(ecoretype, run_addr);
    if(ret)
    {
        /* cov_verified_start */
        sec_print_err("verify image %s fail, ret = 0x%x\n", file_name, ret);
        goto error;
        /* cov_verified_stop */
    }
    sec_print_err("verify image %s success\n", file_name);

error:

    return ret;
}


static int get_dtb_entry(unsigned int modemid, unsigned int num, struct modem_dt_entry_t *dt_entry_ptr, struct modem_dt_entry_t *dt_entry_ccore)
{
    uint32_t i;
    uint8_t sec_id[4]={0};

    sec_id[0] = MODEMID_K_BITS(modemid);
    sec_id[1] = MODEMID_H_BITS(modemid);
    sec_id[2] = MODEMID_M_BITS(modemid);
    sec_id[3] = MODEMID_L_BITS(modemid);

    /* ��ȡ��modemidƥ���acore/ccore dt_entry ָ��,����dtctool��modem config.dts�н�boardid����Ϊ��Ӧmodem_idֵ */
    for (i = 0; i < num; i++)
    {
        if ((dt_entry_ptr->boardid[0] == sec_id[0]) &&
        (dt_entry_ptr->boardid[1] == sec_id[1]) &&
        (dt_entry_ptr->boardid[2] == sec_id[2]) &&
        (dt_entry_ptr->boardid[3] == sec_id[3]))
        {
            sec_print_info("[%d],modemid(0x%x, 0x%x, 0x%x, 0x%x)\n",
                i, dt_entry_ptr->boardid[0], dt_entry_ptr->boardid[1], dt_entry_ptr->boardid[2], dt_entry_ptr->boardid[3]);

            memcpy_s((void *)dt_entry_ccore, sizeof(*dt_entry_ccore), (void *)dt_entry_ptr, sizeof(*dt_entry_ptr));
            break;
        }
        dt_entry_ptr++;
    }

    if(i == num) {
        return -ENOENT;
    }

    return SEC_OK;
}

static s32 load_and_verify_dtb_data(void)
{
    s32 ret, condition;
    u32 modem_id = 0;
    struct modem_dt_table_t *header;
    struct modem_dt_table_t dt_table;
    struct modem_dt_entry_t *dt_entry;
    struct modem_dt_entry_t dt_entry_ptr = {{0}};



    char file_name[256] = {0};
    struct image_type_name *image;
    bool is_sec;
    u32 offset = 0;
    int readed_bytes;

    header = &dt_table;
    ret = get_image(&image, MODEM_DTB,0,0);
    if(ret)
    {
        sec_print_err("can't find image\n");
        return ret;
    }

    ret = get_file_name(file_name, image, &is_sec);
    if(ret)
    {
        sec_print_err("can't find image\n");
        return ret;
    }
    sec_print_info("find file %s, is_sec: %d\n", file_name, is_sec);

    /* ��ȫ�汾����sec VRLͷ */
    if(is_sec)
    {
        offset = VRL_SIZE;
    }

    /*get the head*/
    readed_bytes = read_file(file_name, offset, (unsigned int)sizeof(struct modem_dt_table_t), (char*)(header));
    condition = readed_bytes < 0 || readed_bytes != (int)sizeof(struct modem_dt_table_t);
    if (condition)
    {
       sec_print_err("fail to read the head of modem dtb image, readed_bytes(0x%x) != size(0x%lx).\n", readed_bytes, sizeof(struct modem_dt_table_t));
       ret = readed_bytes;
       return ret;
    }

    /*get the entry*/
    dt_entry  = (struct modem_dt_entry_t *)kzalloc((size_t)((sizeof(struct modem_dt_entry_t)*(header->num_entries))), GFP_KERNEL);
    if(NULL == dt_entry)
    {
       sec_print_err("dtb header malloc fail\n");
       return -ENOMEM;
    }

    offset += sizeof(struct modem_dt_table_t);

    readed_bytes = read_file(file_name, offset, (unsigned int)(sizeof(struct modem_dt_entry_t)*(header->num_entries)), (char*)dt_entry);
    condition = readed_bytes < 0 || readed_bytes != (int)(sizeof(struct modem_dt_entry_t)*(header->num_entries));
    if (condition)
    {
       sec_print_err("fail to read the head of modem dtb entry, readed_bytes(0x%x) != size(0x%lx).\n", readed_bytes, (sizeof(struct modem_dt_entry_t)*(header->num_entries)));
       ret = readed_bytes;
       goto err_out;
    }
      offset -= sizeof(struct modem_dt_table_t);
    /* ��Ҫmask����Ƶ�۰�ID�Ż�modemid��bit[9:0] */
    if (bsp_get_version_info() != NULL)
        modem_id = bsp_get_version_info()->board_id_udp_masked;
    else
        goto err_out;
    sec_print_err("modem_id 0x%x \n", modem_id);

    memset_s((void *)&dt_entry_ptr, sizeof(dt_entry_ptr), 0, sizeof(dt_entry_ptr));
    ret = get_dtb_entry(modem_id, header->num_entries, dt_entry,  &dt_entry_ptr);
    if (ret)
    {
        sec_print_err("fail to get_dtb_entry\n");
        goto err_out;
    }

    /* ��ȫ�汾��ʹ����ǩ�� */
    if(is_sec && 0 != dt_entry_ptr.vrl_size)
    {
        /*load vrl data to sec os*/
        if(dt_entry_ptr.vrl_size > SECBOOT_BUFLEN)
        {
            sec_print_err("modem dtb vrl_size too large %d\n", dt_entry_ptr.vrl_size);
            ret = -ENOMEM;
            goto err_out;
        }
        sec_print_info("modem dtb vrl_offset %d, vrl_size %d\n", dt_entry_ptr.vrl_offset,dt_entry_ptr.vrl_size);

        readed_bytes = read_file(file_name, offset + dt_entry_ptr.vrl_offset,dt_entry_ptr.vrl_size, (char*)SECBOOT_BUFFER);
        condition = readed_bytes < 0 || (u32)readed_bytes != dt_entry_ptr.vrl_size;
        if (condition)
        {
            sec_print_err("fail to read the dtb vrl\n");
            ret = readed_bytes;
            goto err_out;
        }

        ret = trans_vrl_to_os(image->etype, (void *)(SECBOOT_BUFFER), VRL_SIZE);
        if(ret)
        {
            sec_print_err("trans_vrl_to_os error, ret 0x%x!\n", ret);
            goto err_out;
        }
        sec_print_err("trans vrl to secos success\n");

    }

    /* load image data to sec os */
    ret = load_data_to_secos(file_name, offset + dt_entry_ptr.dtb_offset, dt_entry_ptr.dtb_size, image, is_sec);
    if(ret)
    {
        sec_print_err("load image %s to secos failed, ret = 0x%x\n", file_name, ret);
        goto err_out;
    }
    sec_print_err("load image %s to secos success\n", file_name);

    if(is_sec)
    {
        ret = verify_soc_image(image->etype, image->run_addr);
        if (ret)
        {
            sec_print_err("fail to verify modem dtb image\n");
            goto err_out;
        }
    }
      sec_print_err("verify modem dtb success\n");
err_out:
    kfree(dt_entry);
    return ret;
}

/*****************************************************************************
 �� �� ��  : Modem��ؾ�����ؽӿ�
 ��������  : Modem��ؾ�����ؽӿ�
 �������  : ��
 �������  : ��
 �� �� ֵ  : �ɹ�����OK,ʧ�ܷ���ERROR
*****************************************************************************/
int bsp_load_modem_images(void)
{
    int ret;

    mutex_lock(&load_proc_lock);

    ret = modem_dir_init();
    if(ret)
    {
        mutex_unlock(&load_proc_lock);
        sec_print_err("modem_dir_init failed, ret %#x\n", ret);
        return ret;
    }

    ret = TEEK_init();
    if(ret)
    {
        mutex_unlock(&load_proc_lock);
        sec_print_err("TEEK_init failed! ret %#x\n" ,ret);
        return ret;
    }

    ret = ccpu_reset(MODEM);
    if(ret)
    {
        mutex_unlock(&load_proc_lock);
        sec_print_err("ccpu_reset failed, ret %#x\n", ret);
        return ret;
    }



    ret = load_image(DSP, 0, 0);
    if(ret)
    {
        goto error;
    }

    ret = load_image(XDSP, 0, 0);
    if(ret)
    {
        goto error;
    }



    ret = load_and_verify_dtb_data();
    if(ret)
    {
        goto error;
    }
    ret = load_image(MODEM, 0, 0);
    if(ret)
    {
        goto error;
    }

error:
    TEEK_uninit();

    mutex_unlock(&load_proc_lock);

    return ret;
}

/*****************************************************************************
 �� �� ��  : was.img��tas.img�ȶ�̬���ؾ���ӿ�
 ��������  : Modem��ؾ�����ؽӿ�
 �������  : ��
 �������  : ��
 �� �� ֵ  : �ɹ�����OK,ʧ�ܷ���ERROR
*****************************************************************************/
int bsp_load_modem_single_image(enum SVC_SECBOOT_IMG_TYPE ecoretype, u32 run_addr, u32 ddr_size)
{
    int ret;

    mutex_lock(&load_proc_lock);

    ret = TEEK_init();
    if(ret)
    {
        mutex_unlock(&load_proc_lock);
        sec_print_err("TEEK_InitializeContext failed!\n");
        return ret;
    }

    ret = load_image(ecoretype, run_addr, ddr_size);
    if(ret)
    {
        goto error;
    }

error:
    TEEK_uninit();

    mutex_unlock(&load_proc_lock);

    return ret;
}


