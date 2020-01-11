LOCAL_PATH:= $(call my-dir)

#copy upcase.dat to /system/etc/samba
include $(CLEAR_VARS)
LOCAL_MODULE := upcase.dat
LOCAL_SRC_FILES := bin/upcase.dat
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_RELATIVE_PATH := samba
include $(BUILD_PREBUILT)

#copy lowcase.dat to /system/etc/samba
include $(CLEAR_VARS)
LOCAL_MODULE := lowcase.dat
LOCAL_SRC_FILES := bin/lowcase.dat
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_RELATIVE_PATH := samba
include $(BUILD_PREBUILT)
