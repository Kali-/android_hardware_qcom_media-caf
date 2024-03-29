LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

# ---------------------------------------------------------------------------------
#            Common definitons
# ---------------------------------------------------------------------------------
LOCAL_SRC_FILES:=                       \
        DashPlayer.cpp                  \
        DashPlayerDriver.cpp            \
        DashPlayerRenderer.cpp          \
        DashPlayerStats.cpp             \
        DashPlayerDecoder.cpp           \
        DashPacketSource.cpp            \
        DashFactory.cpp                 \
        DashCodec.cpp

LOCAL_SHARED_LIBRARIES :=       \
    libbinder                   \
    libcamera_client            \
    libcutils                   \
    libdl                       \
    libgui                      \
    libmedia                    \
    libstagefright              \
    libstagefright_foundation   \
    libstagefright_omx          \
    libutils                    \
    libui                       \

LOCAL_STATIC_LIBRARIES :=       \
    libstagefright_nuplayer     \
    libstagefright_rtsp         \

LOCAL_C_INCLUDES := \
        $(TOP)/frameworks/av/media/libstagefright/timedtext           \
	$(TOP)/frameworks/native/include/media/hardware               \
	$(TOP)/frameworks/native/include/media/openmax                \
	$(TOP)/frameworks/av/media/libstagefright/httplive            \
	$(TOP)/frameworks/av/media/libmediaplayerservice/nuplayer     \
	$(TOP)/frameworks/av/media/libmediaplayerservice              \
	$(TOP)/frameworks/av/media/libstagefright/include             \
	$(TOP)/frameworks/av/media/libstagefright/mpeg2ts             \
	$(TOP)/frameworks/av/media/libstagefright/rtsp                \
	$(TOP)/hardware/qcom/media-caf/mm-core/inc                        \

LOCAL_MODULE:= libdashplayer

LOCAL_MODULE_TAGS := eng

ifneq ($(PLATFORM_SDK_VERSION), 18)
 include $(BUILD_SHARED_LIBRARY)
endif

