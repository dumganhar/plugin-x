#ifndef __pluginx_chinamobile_h__
#define __pluginx_chinamobile_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *js_IAPChinaMobile_class;
extern JSObject *js_IAPChinaMobile_prototype;

JSBool js_IAPChinaMobile_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_IAPChinaMobile_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_chinamobile_IAPChinaMobile(JSContext *cx, JSObject *global);
void register_all_pluginx_chinamobile(JSContext* cx, JSObject* obj);
JSBool js_IAPChinaMobile_getPluginName(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_IAPChinaMobile_getPluginVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_IAPChinaMobile_init(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_IAPChinaMobile_initDeveloperInfo(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_IAPChinaMobile_payForProduct(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_IAPChinaMobile_getSDKVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_IAPChinaMobile_setDebugMode(JSContext *cx, uint32_t argc, jsval *vp);
#endif

