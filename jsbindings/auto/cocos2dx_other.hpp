#ifndef __cocos2dx_other_h__
#define __cocos2dx_other_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *js_CCApplicationProtocol_class;
extern JSObject *js_CCApplicationProtocol_prototype;

JSBool js_CCApplicationProtocol_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_CCApplicationProtocol_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_other_CCApplicationProtocol(JSContext *cx, JSObject *global);
void register_all_cocos2dx_other(JSContext* cx, JSObject* obj);
JSBool js_CCApplicationProtocol_getTargetPlatform(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_CCApplicationProtocol_getCurrentLanguage(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_CCApplicationProtocol_setAnimationInterval(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *js_CCApplication_class;
extern JSObject *js_CCApplication_prototype;

JSBool js_CCApplication_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_CCApplication_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_other_CCApplication(JSContext *cx, JSObject *global);
void register_all_cocos2dx_other(JSContext* cx, JSObject* obj);
JSBool js_CCApplication_getTargetPlatform(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_CCApplication_setAnimationInterval(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_CCApplication_getCurrentLanguage(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_CCApplication_sharedApplication(JSContext *cx, uint32_t argc, jsval *vp);
#endif

