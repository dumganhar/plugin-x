#ifndef __pluginx_punchbox_h__
#define __pluginx_punchbox_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *jsb_IAPPunchbox_class;
extern JSObject *jsb_IAPPunchbox_prototype;

JSBool js_pluginx_punchbox_IAPPunchbox_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_pluginx_punchbox_IAPPunchbox_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_punchbox_IAPPunchbox(JSContext *cx, JSObject *global);
void register_all_pluginx_punchbox(JSContext* cx, JSObject* obj);
JSBool js_pluginx_punchbox_IAPPunchbox_getPluginName(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_punchbox_IAPPunchbox_getPluginVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_punchbox_IAPPunchbox_init(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_punchbox_IAPPunchbox_initDeveloperInfo(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_punchbox_IAPPunchbox_payForProduct(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_punchbox_IAPPunchbox_getSDKVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_punchbox_IAPPunchbox_setDebugMode(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_AnalyticsPunchbox_class;
extern JSObject *jsb_AnalyticsPunchbox_prototype;

JSBool js_pluginx_punchbox_AnalyticsPunchbox_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_pluginx_punchbox_AnalyticsPunchbox_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_punchbox_AnalyticsPunchbox(JSContext *cx, JSObject *global);
void register_all_pluginx_punchbox(JSContext* cx, JSObject* obj);
JSBool js_pluginx_punchbox_AnalyticsPunchbox_confirmPay(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_punchbox_AnalyticsPunchbox_getSDKVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_punchbox_AnalyticsPunchbox_getPluginName(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_punchbox_AnalyticsPunchbox_getPluginVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_punchbox_AnalyticsPunchbox_init(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_punchbox_AnalyticsPunchbox_userFeedback(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_punchbox_AnalyticsPunchbox_redeemWithCode(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_punchbox_AnalyticsPunchbox_stopSession(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_punchbox_AnalyticsPunchbox_startSessionWithpath(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_punchbox_AnalyticsPunchbox_preparePay(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_punchbox_AnalyticsPunchbox_setDebugMode(JSContext *cx, uint32_t argc, jsval *vp);
#endif

