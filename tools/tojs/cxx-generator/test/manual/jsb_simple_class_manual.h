#ifndef __JSB_SIMPLE_CLASS_MANUAL_H__
#define __JSB_SIMPLE_CLASS_MANUAL_H__

JSBool js_autogentestbindings_SimpleNativeClass_setDelegate(JSContext *cx, uint32_t argc, jsval *vp);

void register_simple_class_extension(JSContext* cx, JSObject* obj);

#endif /* __JSB_SIMPLE_CLASS_MANUAL_H__ */
