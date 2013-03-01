#ifndef __pluginx_h__
#define __pluginx_h__

#include "cocos2d.h"
#include "ScriptingCore.h"
#include "cocos2d_specifics.hpp"
#include "jsb_pluginx_basic_conversions.h"

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
JSBool js_pluginx_ProtocolIAP_setResultListener(JSContext *cx, uint32_t argc, jsval *vp);

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
#endif

