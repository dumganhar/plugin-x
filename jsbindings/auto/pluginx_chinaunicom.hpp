#ifndef __pluginx_chinaunicom_h__
#define __pluginx_chinaunicom_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *js_IAPChinaUnicom_class;
extern JSObject *js_IAPChinaUnicom_prototype;

JSBool js_IAPChinaUnicom_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_IAPChinaUnicom_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_chinaunicom_IAPChinaUnicom(JSContext *cx, JSObject *global);
void register_all_pluginx_chinaunicom(JSContext* cx, JSObject* obj);
JSBool js_IAPChinaUnicom_getPluginName(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_IAPChinaUnicom_getPluginVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_IAPChinaUnicom_init(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_IAPChinaUnicom_initDeveloperInfo(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_IAPChinaUnicom_payForProduct(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_IAPChinaUnicom_getSDKVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_IAPChinaUnicom_setDebugMode(JSContext *cx, uint32_t argc, jsval *vp);
#endif

