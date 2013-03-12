#ifndef __pluginx_chinamobile_h__
#define __pluginx_chinamobile_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *jsb_IAPChinaMobile_class;
extern JSObject *jsb_IAPChinaMobile_prototype;

JSBool js_pluginx_chinamobile_IAPChinaMobile_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_pluginx_chinamobile_IAPChinaMobile_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_chinamobile_IAPChinaMobile(JSContext *cx, JSObject *global);
void register_all_pluginx_chinamobile(JSContext* cx, JSObject* obj);
JSBool js_pluginx_chinamobile_IAPChinaMobile_getPluginName(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_chinamobile_IAPChinaMobile_getPluginVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_chinamobile_IAPChinaMobile_init(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_chinamobile_IAPChinaMobile_initDeveloperInfo(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_chinamobile_IAPChinaMobile_payForProduct(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_chinamobile_IAPChinaMobile_getSDKVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_chinamobile_IAPChinaMobile_setDebugMode(JSContext *cx, uint32_t argc, jsval *vp);
#endif

