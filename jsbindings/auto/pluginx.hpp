#ifndef __pluginx_h__
#define __pluginx_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *js_pluginx_PluginProtocol_class;
extern JSObject *js_pluginx_PluginProtocol_prototype;

JSBool js_pluginx_PluginProtocol_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_pluginx_PluginProtocol_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_PluginProtocol(JSContext *cx, JSObject *global);
void register_all_pluginx(JSContext* cx, JSObject* obj);
JSBool js_pluginx_PluginProtocol_setUserData(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_PluginProtocol_getUserData(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_PluginProtocol_getPluginName(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_PluginProtocol_getPluginVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_PluginProtocol_init(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_PluginProtocol_setDebugMode(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *js_pluginx_PluginManager_class;
extern JSObject *js_pluginx_PluginManager_prototype;

JSBool js_pluginx_PluginManager_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_pluginx_PluginManager_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_PluginManager(JSContext *cx, JSObject *global);
void register_all_pluginx(JSContext* cx, JSObject* obj);
JSBool js_pluginx_PluginManager_unloadPlugin(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_PluginManager_loadPlugin(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_PluginManager_end(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_PluginManager_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *js_pluginx_ProtocolIAP_class;
extern JSObject *js_pluginx_ProtocolIAP_prototype;

JSBool js_pluginx_ProtocolIAP_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_pluginx_ProtocolIAP_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_ProtocolIAP(JSContext *cx, JSObject *global);
void register_all_pluginx(JSContext* cx, JSObject* obj);
JSBool js_pluginx_ProtocolIAP_initDeveloperInfo(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_ProtocolIAP_getPluginVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_ProtocolIAP_init(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_ProtocolIAP_payForProduct(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_ProtocolIAP_getSDKVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_ProtocolIAP_setDebugMode(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_ProtocolIAP_getPluginName(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_ProtocolIAP_payResult(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *js_pluginx_IAPAlipay_class;
extern JSObject *js_pluginx_IAPAlipay_prototype;

JSBool js_pluginx_IAPAlipay_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_pluginx_IAPAlipay_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_IAPAlipay(JSContext *cx, JSObject *global);
void register_all_pluginx(JSContext* cx, JSObject* obj);
JSBool js_pluginx_IAPAlipay_getPluginName(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_IAPAlipay_getPluginVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_IAPAlipay_init(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_IAPAlipay_initDeveloperInfo(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_IAPAlipay_payForProduct(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_IAPAlipay_getSDKVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_IAPAlipay_setDebugMode(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_IAPAlipay_createPlugin(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *js_pluginx_IAPNd91_class;
extern JSObject *js_pluginx_IAPNd91_prototype;

JSBool js_pluginx_IAPNd91_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_pluginx_IAPNd91_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_IAPNd91(JSContext *cx, JSObject *global);
void register_all_pluginx(JSContext* cx, JSObject* obj);
JSBool js_pluginx_IAPNd91_getPluginName(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_IAPNd91_getPluginVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_IAPNd91_init(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_IAPNd91_initDeveloperInfo(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_IAPNd91_payForProduct(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_IAPNd91_getSDKVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_IAPNd91_setDebugMode(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_IAPNd91_createPlugin(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *js_pluginx_ProtocolAnalytics_class;
extern JSObject *js_pluginx_ProtocolAnalytics_prototype;

JSBool js_pluginx_ProtocolAnalytics_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_pluginx_ProtocolAnalytics_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_ProtocolAnalytics(JSContext *cx, JSObject *global);
void register_all_pluginx(JSContext* cx, JSObject* obj);
JSBool js_pluginx_ProtocolAnalytics_logTimedEventBegin(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_ProtocolAnalytics_logError(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_ProtocolAnalytics_setCaptureUncaughtException(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_ProtocolAnalytics_getPluginName(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_ProtocolAnalytics_getPluginVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_ProtocolAnalytics_logEvent(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_ProtocolAnalytics_setSessionContinueMillis(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_ProtocolAnalytics_init(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_ProtocolAnalytics_startSession(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_ProtocolAnalytics_stopSession(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_ProtocolAnalytics_logTimedEventEnd(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_ProtocolAnalytics_getSDKVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_ProtocolAnalytics_setDebugMode(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *js_pluginx_AnalyticsFlurry_class;
extern JSObject *js_pluginx_AnalyticsFlurry_prototype;

JSBool js_pluginx_AnalyticsFlurry_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_pluginx_AnalyticsFlurry_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_AnalyticsFlurry(JSContext *cx, JSObject *global);
void register_all_pluginx(JSContext* cx, JSObject* obj);
JSBool js_pluginx_AnalyticsFlurry_logTimedEventBegin(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsFlurry_setUserId(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsFlurry_logError(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsFlurry_setCaptureUncaughtException(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsFlurry_setGender(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsFlurry_logPageView(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsFlurry_getPluginName(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsFlurry_setReportLocation(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsFlurry_getPluginVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsFlurry_logEvent(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsFlurry_setSessionContinueMillis(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsFlurry_setAge(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsFlurry_init(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsFlurry_setVersionName(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsFlurry_startSession(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsFlurry_stopSession(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsFlurry_setUseHttps(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsFlurry_logTimedEventEnd(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsFlurry_getSDKVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsFlurry_setDebugMode(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsFlurry_createPlugin(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *js_pluginx_AnalyticsUmeng_class;
extern JSObject *js_pluginx_AnalyticsUmeng_prototype;

JSBool js_pluginx_AnalyticsUmeng_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_pluginx_AnalyticsUmeng_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_AnalyticsUmeng(JSContext *cx, JSObject *global);
void register_all_pluginx(JSContext* cx, JSObject* obj);
JSBool js_pluginx_AnalyticsUmeng_setSessionContinueMillis(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsUmeng_startSession(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsUmeng_stopSession(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsUmeng_getSDKVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsUmeng_updateOnlineConfig(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsUmeng_logTimedEventBegin(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsUmeng_logError(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsUmeng_logEventWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsUmeng_checkUpdate(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsUmeng_getPluginVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsUmeng_setDefaultReportPolicy(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsUmeng_init(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsUmeng_logTimedKVEventEnd(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsUmeng_logTimedKVEventBegin(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsUmeng_setCaptureUncaughtException(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsUmeng_getConfigParams(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsUmeng_getPluginName(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsUmeng_logTimedEventWithLabelBegin(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsUmeng_logTimedEventWithLabelEnd(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsUmeng_logEvent(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsUmeng_logTimedEventEnd(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsUmeng_logEventWithLabel(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsUmeng_setDebugMode(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_pluginx_AnalyticsUmeng_createPlugin(JSContext *cx, uint32_t argc, jsval *vp);
#endif

