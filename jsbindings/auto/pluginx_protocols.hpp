#ifndef __pluginx_protocols_h__
#define __pluginx_protocols_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *js_PluginProtocol_class;
extern JSObject *js_PluginProtocol_prototype;

JSBool js_PluginProtocol_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_PluginProtocol_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_protocols_PluginProtocol(JSContext *cx, JSObject *global);
void register_all_pluginx_protocols(JSContext* cx, JSObject* obj);
JSBool js_PluginProtocol_setUserData(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_PluginProtocol_getUserData(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_PluginProtocol_getPluginName(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_PluginProtocol_getPluginVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_PluginProtocol_init(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_PluginProtocol_setDebugMode(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *js_PluginManager_class;
extern JSObject *js_PluginManager_prototype;

JSBool js_PluginManager_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_PluginManager_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_protocols_PluginManager(JSContext *cx, JSObject *global);
void register_all_pluginx_protocols(JSContext* cx, JSObject* obj);
JSBool js_PluginManager_unloadPlugin(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_PluginManager_loadPlugin(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_PluginManager_end(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_PluginManager_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *js_ProtocolAnalytics_class;
extern JSObject *js_ProtocolAnalytics_prototype;

JSBool js_ProtocolAnalytics_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_ProtocolAnalytics_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_protocols_ProtocolAnalytics(JSContext *cx, JSObject *global);
void register_all_pluginx_protocols(JSContext* cx, JSObject* obj);
JSBool js_ProtocolAnalytics_logTimedEventBegin(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_ProtocolAnalytics_logError(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_ProtocolAnalytics_setCaptureUncaughtException(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_ProtocolAnalytics_getPluginName(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_ProtocolAnalytics_getPluginVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_ProtocolAnalytics_logEvent(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_ProtocolAnalytics_setSessionContinueMillis(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_ProtocolAnalytics_init(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_ProtocolAnalytics_startSession(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_ProtocolAnalytics_stopSession(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_ProtocolAnalytics_logTimedEventEnd(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_ProtocolAnalytics_getSDKVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_ProtocolAnalytics_setDebugMode(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *js_ProtocolIAP_class;
extern JSObject *js_ProtocolIAP_prototype;

JSBool js_ProtocolIAP_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_ProtocolIAP_finalize(JSContext *cx, JSObject *obj);
void js_register_pluginx_protocols_ProtocolIAP(JSContext *cx, JSObject *global);
void register_all_pluginx_protocols(JSContext* cx, JSObject* obj);
JSBool js_ProtocolIAP_initDeveloperInfo(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_ProtocolIAP_getPluginVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_ProtocolIAP_init(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_ProtocolIAP_payForProduct(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_ProtocolIAP_getSDKVersion(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_ProtocolIAP_setDebugMode(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_ProtocolIAP_getPluginName(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_ProtocolIAP_payResult(JSContext *cx, uint32_t argc, jsval *vp);
#endif

