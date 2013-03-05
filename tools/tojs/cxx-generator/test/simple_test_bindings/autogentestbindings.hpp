#ifndef __autogentestbindings_h__
#define __autogentestbindings_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *js_autogentestbindings_SimpleNativeClass_class;
extern JSObject *js_autogentestbindings_SimpleNativeClass_prototype;

JSBool js_autogentestbindings_SimpleNativeClass_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_autogentestbindings_SimpleNativeClass_finalize(JSContext *cx, JSObject *obj);
void js_register_autogentestbindings_SimpleNativeClass(JSContext *cx, JSObject *global);
void register_all_autogentestbindings(JSContext* cx, JSObject* obj);
JSBool js_autogentestbindings_SimpleNativeClass_getAnotherMoreComplexField(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_autogentestbindings_SimpleNativeClass_setSomeField(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_autogentestbindings_SimpleNativeClass_receivesLongLong(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_autogentestbindings_SimpleNativeClass_thisReturnsALongLong(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_autogentestbindings_SimpleNativeClass_setAnotherMoreComplexField(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_autogentestbindings_SimpleNativeClass_setSomeOtherField(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_autogentestbindings_SimpleNativeClass_virtualFoo(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_autogentestbindings_SimpleNativeClass_getSomeOtherField(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_autogentestbindings_SimpleNativeClass_instance_func(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_autogentestbindings_SimpleNativeClass_returnsACString(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_autogentestbindings_SimpleNativeClass_doSomeProcessing(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_autogentestbindings_SimpleNativeClass_instance_func_overroad(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_autogentestbindings_SimpleNativeClass_getSomeField(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_autogentestbindings_SimpleNativeClass_returnsAString(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_autogentestbindings_SimpleNativeClass_static_func(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_autogentestbindings_SimpleNativeClass_static_func_overroad(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_autogentestbindings_SimpleNativeClass_func(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_autogentestbindings_SimpleNativeClass_SimpleNativeClass(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *js_autogentestbindings_SubClass_class;
extern JSObject *js_autogentestbindings_SubClass_prototype;

JSBool js_autogentestbindings_SubClass_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_autogentestbindings_SubClass_finalize(JSContext *cx, JSObject *obj);
void js_register_autogentestbindings_SubClass(JSContext *cx, JSObject *global);
void register_all_autogentestbindings(JSContext* cx, JSObject* obj);
JSBool js_autogentestbindings_SubClass_foo(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_autogentestbindings_SubClass_virtualFoo(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_autogentestbindings_SubClass_hello(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *js_autogentestbindings_AnotherClass_class;
extern JSObject *js_autogentestbindings_AnotherClass_prototype;

JSBool js_autogentestbindings_AnotherClass_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_autogentestbindings_AnotherClass_finalize(JSContext *cx, JSObject *obj);
void js_register_autogentestbindings_AnotherClass(JSContext *cx, JSObject *global);
void register_all_autogentestbindings(JSContext* cx, JSObject* obj);
JSBool js_autogentestbindings_AnotherClass_setJustOneField(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_autogentestbindings_AnotherClass_getJustOneField(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_autogentestbindings_AnotherClass_doSomethingSimple(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_autogentestbindings_AnotherClass_AnotherClass(JSContext *cx, uint32_t argc, jsval *vp);
#endif

