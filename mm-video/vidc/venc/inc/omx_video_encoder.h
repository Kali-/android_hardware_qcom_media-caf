/*--------------------------------------------------------------------------
Copyright (c) 2010-2013, The Linux Foundation. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
--------------------------------------------------------------------------*/
#ifndef __OMX_VENC__H
#define __OMX_VENC__H

#include <unistd.h>
#include "omx_video_base.h"
#ifdef _MSM8974_
#include "video_encoder_device_v4l2.h"
#else
#include "video_encoder_device.h"
#endif

extern "C" {
  OMX_API void * get_omx_component_factory_fn(void);
}

class omx_venc: public omx_video
{
public:
  omx_venc(); //constructor
  ~omx_venc(); //des
  static int async_message_process (void *context, void* message);
  OMX_ERRORTYPE component_init(OMX_STRING role);
  OMX_ERRORTYPE set_parameter(OMX_HANDLETYPE hComp,
                              OMX_INDEXTYPE  paramIndex,
                              OMX_PTR        paramData);
  OMX_ERRORTYPE set_config(OMX_HANDLETYPE hComp,
                           OMX_INDEXTYPE  configIndex,
                           OMX_PTR        configData);
  OMX_ERRORTYPE component_deinit(OMX_HANDLETYPE hComp);
  //OMX strucutres
  OMX_U32 m_nVenc_format;
  class venc_dev *handle;
#ifdef _MSM8974_
  int dev_handle_extradata(void *, int);
  int dev_set_format(int);
#endif
private:
  OMX_U32 dev_stop(void);
  OMX_U32 dev_pause(void);
  OMX_U32 dev_start(void);
  OMX_U32 dev_flush(unsigned);
  OMX_U32 dev_resume(void);
  OMX_U32 dev_start_done(void);
  OMX_U32 dev_set_message_thread_id(pthread_t);
  bool dev_use_buf( void *,unsigned,unsigned);
  bool dev_free_buf( void *,unsigned);
  bool dev_empty_buf(void *, void *,unsigned,unsigned);
  bool dev_fill_buf(void *, void *,unsigned,unsigned);
  bool dev_get_buf_req(OMX_U32 *,OMX_U32 *,OMX_U32 *,OMX_U32);
  bool dev_set_buf_req(OMX_U32 *,OMX_U32 *,OMX_U32 *,OMX_U32);
  bool update_profile_level();
  bool dev_get_seq_hdr(void *, unsigned, unsigned *);
  bool dev_loaded_start(void);
  bool dev_loaded_stop(void);
  bool dev_loaded_start_done(void);
  bool dev_loaded_stop_done(void);
  bool dev_get_capability_ltrcount(OMX_U32 *, OMX_U32 *, OMX_U32 *);
  bool dev_is_video_session_supported(OMX_U32 width, OMX_U32 height);
};

#endif //__OMX_VENC__H
