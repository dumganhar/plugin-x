#ifndef __pluginx_punchbox_h__
#define __pluginx_punchbox_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *js_IAPPunchbox_class;
extern JSObject *js_IAPPunchbox_prototype;

JSBool js_IAPPunchbox_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_IAPPunchbox_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_punchbox_IAPPunchbox(JSContext *cx, JSObject *global);
void register_all_pluginx_punchbox(JSContext* cx, JSObject* obj);
JSBool js_IAPPunchbox_getPluginName(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_IAPPunchbox_getPluginVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_IAPPunchbox_init(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_IAPPunchbox_initDeveloperInfo(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_IAPPunchbox_payForProduct(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_IAPPunchbox_getSDKVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_IAPPunchbox_setDebugMode(JSContext *cx, uint32_t argc, jsval *vp);
#endif

