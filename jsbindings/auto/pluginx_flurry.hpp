#ifndef __pluginx_flurry_h__
#define __pluginx_flurry_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *js_AnalyticsFlurry_class;
extern JSObject *js_AnalyticsFlurry_prototype;

JSBool js_AnalyticsFlurry_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_AnalyticsFlurry_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_flurry_AnalyticsFlurry(JSContext *cx, JSObject *global);
void register_all_pluginx_flurry(JSContext* cx, JSObject* obj);
JSBool js_AnalyticsFlurry_logTimedEventBegin(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_AnalyticsFlurry_setUserId(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_AnalyticsFlurry_logError(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_AnalyticsFlurry_setCaptureUncaughtException(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_AnalyticsFlurry_setGender(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_AnalyticsFlurry_logPageView(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_AnalyticsFlurry_getPluginName(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_AnalyticsFlurry_setReportLocation(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_AnalyticsFlurry_getPluginVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_AnalyticsFlurry_logEvent(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_AnalyticsFlurry_setSessionContinueMillis(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_AnalyticsFlurry_setAge(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_AnalyticsFlurry_init(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_AnalyticsFlurry_setVersionName(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_AnalyticsFlurry_startSession(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_AnalyticsFlurry_stopSession(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_AnalyticsFlurry_setUseHttps(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_AnalyticsFlurry_logTimedEventEnd(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_AnalyticsFlurry_getSDKVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_AnalyticsFlurry_setDebugMode(JSContext *cx, uint32_t argc, jsval *vp);
#endif

