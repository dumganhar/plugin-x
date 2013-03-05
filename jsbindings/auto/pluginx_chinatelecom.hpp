#ifndef __pluginx_chinatelecom_h__
#define __pluginx_chinatelecom_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *js_IAPChinaTelecom_class;
extern JSObject *js_IAPChinaTelecom_prototype;

JSBool js_IAPChinaTelecom_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_IAPChinaTelecom_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_chinatelecom_IAPChinaTelecom(JSContext *cx, JSObject *global);
void register_all_pluginx_chinatelecom(JSContext* cx, JSObject* obj);
JSBool js_IAPChinaTelecom_getPluginName(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_IAPChinaTelecom_getPluginVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_IAPChinaTelecom_init(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_IAPChinaTelecom_initDeveloperInfo(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_IAPChinaTelecom_payForProduct(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_IAPChinaTelecom_getSDKVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_IAPChinaTelecom_setDebugMode(JSContext *cx, uint32_t argc, jsval *vp);
#endif

