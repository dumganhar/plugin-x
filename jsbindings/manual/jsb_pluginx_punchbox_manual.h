#ifndef __JSB_PLUGINX_PUNCHBOX_MANUAL_H__
#define __JSB_PLUGINX_PUNCHBOX_MANUAL_H__

#include "jsapi.h"
#include "jsfriendapi.h"

JSBool js_pluginx_Punchbox_setRedeemListener(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_Punchbox_setFeedbackListener(JSContext *cx, uint32_t argc, jsval *vp);

void register_pluginx_punchbox_manual(JSContext* cx, JSObject* global);

#endif /* __JSB_PLUGINX_PUNCHBOX_MANUAL_H__ */
