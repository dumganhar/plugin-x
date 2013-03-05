#include "jsapi.h"
#include "jsfriendapi.h"
#include "jsb_pluginx_spidermonkey_specifics.h"
#include "jsb_pluginx_basic_conversions.h"
#include "autogentestbindings.hpp"
#include "simple_class.h"

using namespace pluginx;

template<class T>
static JSBool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
	TypeTest<T> t;
	T* cobj = new T();
//#ifdef COCOS2D_JAVASCRIPT
	// cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
	// if (_ccobj) {
	// 	_ccobj->autorelease();
	// }
//#endif
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	assert(p);
	JSObject *_tmp = JS_NewObject(cx, p->jsclass, p->proto, p->parentProto);
	js_proxy_t *pp;
	JS_NEW_PROXY(pp, cobj, _tmp);
//#ifdef COCOS2D_JAVASCRIPT
//	JS_AddObjectRoot(cx, &pp->obj);
//#endif
	JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));

	return JS_TRUE;
}

static JSBool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
	return JS_FALSE;
}


JSClass  *js_autogentestbindings_SimpleNativeClass_class;
JSObject *js_autogentestbindings_SimpleNativeClass_prototype;

JSBool js_autogentestbindings_SimpleNativeClass_getAnotherMoreComplexField(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	SimpleNativeClass* cobj = (SimpleNativeClass *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		const char* ret = cobj->getAnotherMoreComplexField();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_autogentestbindings_SimpleNativeClass_setSomeField(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;

	JSObject *obj = NULL;
	SimpleNativeClass* cobj = NULL;
	obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cobj = (SimpleNativeClass *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	do {
		if (argc == 2) {
			double arg0;
			ok &= JS_ValueToNumber(cx, argv[0], &arg0);
			if (!ok) { ok = JS_TRUE; break; }
			double arg1;
			ok &= JS_ValueToNumber(cx, argv[1], &arg1);
			if (!ok) { ok = JS_TRUE; break; }
			cobj->setSomeField(arg0, arg1);
			JS_SET_RVAL(cx, vp, JSVAL_VOID);
			return JS_TRUE;
		}
	} while(0);

	do {
		if (argc == 3) {
			double arg0;
			ok &= JS_ValueToNumber(cx, argv[0], &arg0);
			if (!ok) { ok = JS_TRUE; break; }
			double arg1;
			ok &= JS_ValueToNumber(cx, argv[1], &arg1);
			if (!ok) { ok = JS_TRUE; break; }
			const char* arg2;
			std::string arg2_tmp; ok &= jsval_to_std_string(cx, argv[2], &arg2_tmp); arg2 = arg2_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			cobj->setSomeField(arg0, arg1, arg2);
			JS_SET_RVAL(cx, vp, JSVAL_VOID);
			return JS_TRUE;
		}
	} while(0);

	do {
		if (argc == 4) {
			double arg0;
			ok &= JS_ValueToNumber(cx, argv[0], &arg0);
			if (!ok) { ok = JS_TRUE; break; }
			double arg1;
			ok &= JS_ValueToNumber(cx, argv[1], &arg1);
			if (!ok) { ok = JS_TRUE; break; }
			const char* arg2;
			std::string arg2_tmp; ok &= jsval_to_std_string(cx, argv[2], &arg2_tmp); arg2 = arg2_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			int arg3;
			ok &= jsval_to_int32(cx, argv[3], (int32_t *)&arg3);
			if (!ok) { ok = JS_TRUE; break; }
			cobj->setSomeField(arg0, arg1, arg2, arg3);
			JS_SET_RVAL(cx, vp, JSVAL_VOID);
			return JS_TRUE;
		}
	} while(0);

	do {
		if (argc == 1) {
			int arg0;
			ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
			if (!ok) { ok = JS_TRUE; break; }
			cobj->setSomeField(arg0);
			JS_SET_RVAL(cx, vp, JSVAL_VOID);
			return JS_TRUE;
		}
	} while(0);

	do {
		if (argc == 0) {
			cobj->setSomeField();
			JS_SET_RVAL(cx, vp, JSVAL_VOID);
			return JS_TRUE;
		}
	} while(0);

	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}
JSBool js_autogentestbindings_SimpleNativeClass_receivesLongLong(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	SimpleNativeClass* cobj = (SimpleNativeClass *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 1) {
		long long arg0;
		ok &= jsval_to_long_long(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		long long ret = cobj->receivesLongLong(arg0);
		jsval jsret;
		jsret = long_long_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_autogentestbindings_SimpleNativeClass_thisReturnsALongLong(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	SimpleNativeClass* cobj = (SimpleNativeClass *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		long long ret = cobj->thisReturnsALongLong();
		jsval jsret;
		jsret = long_long_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_autogentestbindings_SimpleNativeClass_setAnotherMoreComplexField(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	SimpleNativeClass* cobj = (SimpleNativeClass *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setAnotherMoreComplexField(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_autogentestbindings_SimpleNativeClass_setSomeOtherField(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	SimpleNativeClass* cobj = (SimpleNativeClass *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setSomeOtherField(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_autogentestbindings_SimpleNativeClass_virtualFoo(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	SimpleNativeClass* cobj = (SimpleNativeClass *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		cobj->virtualFoo();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_autogentestbindings_SimpleNativeClass_getSomeOtherField(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	SimpleNativeClass* cobj = (SimpleNativeClass *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		int ret = cobj->getSomeOtherField();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_autogentestbindings_SimpleNativeClass_instance_func(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	SimpleNativeClass* cobj = (SimpleNativeClass *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		int ret = cobj->instance_func(arg0);
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	if (argc == 2) {
		int arg0;
		std::string arg1;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		ok &= jsval_to_std_string(cx, argv[1], &arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		int ret = cobj->instance_func(arg0, arg1);
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_autogentestbindings_SimpleNativeClass_returnsACString(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	SimpleNativeClass* cobj = (SimpleNativeClass *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		const char* ret = cobj->returnsACString();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_autogentestbindings_SimpleNativeClass_doSomeProcessing(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	SimpleNativeClass* cobj = (SimpleNativeClass *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 2) {
		std::string arg0;
		std::string arg1;
		ok &= jsval_to_std_string(cx, argv[0], &arg0);
		ok &= jsval_to_std_string(cx, argv[1], &arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		int ret = cobj->doSomeProcessing(arg0, arg1);
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_autogentestbindings_SimpleNativeClass_instance_func_overroad(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;

	JSObject *obj = NULL;
	SimpleNativeClass* cobj = NULL;
	obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cobj = (SimpleNativeClass *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	do {
		if (argc == 1) {
			std::string arg0;
			ok &= jsval_to_std_string(cx, argv[0], &arg0);
			if (!ok) { ok = JS_TRUE; break; }
			int ret = cobj->instance_func_overroad(arg0);
			jsval jsret; jsret = int32_to_jsval(cx, ret);
			JS_SET_RVAL(cx, vp, jsret);
			return JS_TRUE;
		}
	} while(0);

	do {
		if (argc == 0) {
			int ret = cobj->instance_func_overroad();
			jsval jsret; jsret = int32_to_jsval(cx, ret);
			JS_SET_RVAL(cx, vp, jsret);
			return JS_TRUE;
		}
	} while(0);

	do {
		if (argc == 1) {
			int arg0;
			ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
			if (!ok) { ok = JS_TRUE; break; }
			int ret = cobj->instance_func_overroad(arg0);
			jsval jsret; jsret = int32_to_jsval(cx, ret);
			JS_SET_RVAL(cx, vp, jsret);
			return JS_TRUE;
		}
	} while(0);

	do {
		if (argc == 2) {
			int arg0;
			ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
			if (!ok) { ok = JS_TRUE; break; }
			const char* arg1;
			std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			int ret = cobj->instance_func_overroad(arg0, arg1);
			jsval jsret; jsret = int32_to_jsval(cx, ret);
			JS_SET_RVAL(cx, vp, jsret);
			return JS_TRUE;
		}
	} while(0);

	do {
		if (argc == 2) {
			JSBool arg0;
			ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
			if (!ok) { ok = JS_TRUE; break; }
			int arg1;
			ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
			if (!ok) { ok = JS_TRUE; break; }
			int ret = cobj->instance_func_overroad(arg0, arg1);
			jsval jsret; jsret = int32_to_jsval(cx, ret);
			JS_SET_RVAL(cx, vp, jsret);
			return JS_TRUE;
		}
	} while(0);

	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}
JSBool js_autogentestbindings_SimpleNativeClass_getSomeField(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	SimpleNativeClass* cobj = (SimpleNativeClass *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		int ret = cobj->getSomeField();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_autogentestbindings_SimpleNativeClass_returnsAString(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	SimpleNativeClass* cobj = (SimpleNativeClass *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		std::string ret = cobj->returnsAString();
		jsval jsret;
		jsret = std_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_autogentestbindings_SimpleNativeClass_static_func(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		int ret = SimpleNativeClass::static_func(arg0);
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	if (argc == 2) {
		int arg0;
		std::string arg1;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		ok &= jsval_to_std_string(cx, argv[1], &arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		int ret = SimpleNativeClass::static_func(arg0, arg1);
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}

JSBool js_autogentestbindings_SimpleNativeClass_static_func_overroad(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	do {
		if (argc == 1) {
			int arg0;
			ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
			if (!ok) { ok = JS_TRUE; break; }
			int ret = SimpleNativeClass::static_func_overroad(arg0);
			jsval jsret;
			jsret = int32_to_jsval(cx, ret);
			JS_SET_RVAL(cx, vp, jsret);
			return JS_TRUE;
		}
	} while (0);
	do {
		if (argc == 0) {
			int ret = SimpleNativeClass::static_func_overroad();
			jsval jsret;
			jsret = int32_to_jsval(cx, ret);
			JS_SET_RVAL(cx, vp, jsret);
			return JS_TRUE;
		}
	} while (0);
	do {
		if (argc == 1) {
			std::string arg0;
			ok &= jsval_to_std_string(cx, argv[0], &arg0);
			if (!ok) { ok = JS_TRUE; break; }
			int ret = SimpleNativeClass::static_func_overroad(arg0);
			jsval jsret;
			jsret = int32_to_jsval(cx, ret);
			JS_SET_RVAL(cx, vp, jsret);
			return JS_TRUE;
		}
	} while (0);
	do {
		if (argc == 2) {
			int arg0;
			ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
			if (!ok) { ok = JS_TRUE; break; }
			const char* arg1;
			std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			int ret = SimpleNativeClass::static_func_overroad(arg0, arg1);
			jsval jsret;
			jsret = int32_to_jsval(cx, ret);
			JS_SET_RVAL(cx, vp, jsret);
			return JS_TRUE;
		}
	} while (0);
	do {
		if (argc == 2) {
			JSBool arg0;
			ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
			if (!ok) { ok = JS_TRUE; break; }
			int arg1;
			ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
			if (!ok) { ok = JS_TRUE; break; }
			int ret = SimpleNativeClass::static_func_overroad(arg0, arg1);
			jsval jsret;
			jsret = int32_to_jsval(cx, ret);
			JS_SET_RVAL(cx, vp, jsret);
			return JS_TRUE;
		}
	} while (0);
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}
JSBool js_autogentestbindings_SimpleNativeClass_func(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	do {
		if (argc == 1) {
			int arg0;
			ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
			if (!ok) { ok = JS_TRUE; break; }
			SimpleNativeClass::func(arg0);
			return JS_TRUE;
		}
	} while (0);
	do {
		if (argc == 0) {
			SimpleNativeClass::func();
			return JS_TRUE;
		}
	} while (0);
	do {
		if (argc == 2) {
			int arg0;
			ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
			if (!ok) { ok = JS_TRUE; break; }
			double arg1;
			ok &= JS_ValueToNumber(cx, argv[1], &arg1);
			if (!ok) { ok = JS_TRUE; break; }
			SimpleNativeClass::func(arg0, arg1);
			return JS_TRUE;
		}
	} while (0);
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}
JSBool js_autogentestbindings_SimpleNativeClass_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;

	JSObject *obj = NULL;
	SimpleNativeClass* cobj = NULL;

	do {
		if (argc == 1) {
			int arg0;
			ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
			if (!ok) { ok = JS_TRUE; break; }
			cobj = new SimpleNativeClass(arg0);
	//#ifdef COCOS2D_JAVASCRIPT
			// cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			// if (_ccobj) {
			// 	_ccobj->autorelease();
			// }
	//#endif
			TypeTest<SimpleNativeClass> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t *proxy;
			JS_NEW_PROXY(proxy, cobj, obj);
	//#ifdef COCOS2D_JAVASCRIPT
	//		JS_AddNamedObjectRoot(cx, &proxy->obj, "SimpleNativeClass");
	//#endif
		}
	} while(0);

	do {
		if (argc == 0) {
			cobj = new SimpleNativeClass();
	//#ifdef COCOS2D_JAVASCRIPT
			// cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			// if (_ccobj) {
			// 	_ccobj->autorelease();
			// }
	//#endif
			TypeTest<SimpleNativeClass> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t *proxy;
			JS_NEW_PROXY(proxy, cobj, obj);
	//#ifdef COCOS2D_JAVASCRIPT
	//		JS_AddNamedObjectRoot(cx, &proxy->obj, "SimpleNativeClass");
	//#endif
		}
	} while(0);

	do {
		if (argc == 2) {
			int arg0;
			ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
			if (!ok) { ok = JS_TRUE; break; }
			int arg1;
			ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
			if (!ok) { ok = JS_TRUE; break; }
			cobj = new SimpleNativeClass(arg0, arg1);
	//#ifdef COCOS2D_JAVASCRIPT
			// cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			// if (_ccobj) {
			// 	_ccobj->autorelease();
			// }
	//#endif
			TypeTest<SimpleNativeClass> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t *proxy;
			JS_NEW_PROXY(proxy, cobj, obj);
	//#ifdef COCOS2D_JAVASCRIPT
	//		JS_AddNamedObjectRoot(cx, &proxy->obj, "SimpleNativeClass");
	//#endif
		}
	} while(0);

	do {
		if (argc == 1) {
			std::string arg0;
			ok &= jsval_to_std_string(cx, argv[0], &arg0);
			if (!ok) { ok = JS_TRUE; break; }
			cobj = new SimpleNativeClass(arg0);
	//#ifdef COCOS2D_JAVASCRIPT
			// cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			// if (_ccobj) {
			// 	_ccobj->autorelease();
			// }
	//#endif
			TypeTest<SimpleNativeClass> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t *proxy;
			JS_NEW_PROXY(proxy, cobj, obj);
	//#ifdef COCOS2D_JAVASCRIPT
	//		JS_AddNamedObjectRoot(cx, &proxy->obj, "SimpleNativeClass");
	//#endif
		}
	} while(0);

	do {
		if (argc == 2) {
			std::string arg0;
			ok &= jsval_to_std_string(cx, argv[0], &arg0);
			if (!ok) { ok = JS_TRUE; break; }
			double arg1;
			ok &= JS_ValueToNumber(cx, argv[1], &arg1);
			if (!ok) { ok = JS_TRUE; break; }
			cobj = new SimpleNativeClass(arg0, arg1);
	//#ifdef COCOS2D_JAVASCRIPT
			// cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			// if (_ccobj) {
			// 	_ccobj->autorelease();
			// }
	//#endif
			TypeTest<SimpleNativeClass> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t *proxy;
			JS_NEW_PROXY(proxy, cobj, obj);
	//#ifdef COCOS2D_JAVASCRIPT
	//		JS_AddNamedObjectRoot(cx, &proxy->obj, "SimpleNativeClass");
	//#endif
		}
	} while(0);

	if (cobj) {
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}



void js_autogentestbindings_SimpleNativeClass_finalize(JSFreeOp *fop, JSObject *obj) {
//#ifdef COCOS2D_JAVASCRIPT
	LOGD("js_autogentestbindings_SimpleNativeClass_finalize\n");
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JS_GET_NATIVE_PROXY(jsproxy, obj);
    if (jsproxy) {
        JS_GET_PROXY(nproxy, jsproxy->ptr);
        JS_REMOVE_PROXY(nproxy, jsproxy);
    }
//#endif 
}

void js_register_autogentestbindings_SimpleNativeClass(JSContext *cx, JSObject *global) {
	js_autogentestbindings_SimpleNativeClass_class = (JSClass *)calloc(1, sizeof(JSClass));
	js_autogentestbindings_SimpleNativeClass_class->name = "SimpleNativeClass";
	js_autogentestbindings_SimpleNativeClass_class->addProperty = JS_PropertyStub;
	js_autogentestbindings_SimpleNativeClass_class->delProperty = JS_PropertyStub;
	js_autogentestbindings_SimpleNativeClass_class->getProperty = JS_PropertyStub;
	js_autogentestbindings_SimpleNativeClass_class->setProperty = JS_StrictPropertyStub;
	js_autogentestbindings_SimpleNativeClass_class->enumerate = JS_EnumerateStub;
	js_autogentestbindings_SimpleNativeClass_class->resolve = JS_ResolveStub;
	js_autogentestbindings_SimpleNativeClass_class->convert = JS_ConvertStub;
	js_autogentestbindings_SimpleNativeClass_class->finalize = js_autogentestbindings_SimpleNativeClass_finalize;
	js_autogentestbindings_SimpleNativeClass_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, 0, 0}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("getAnotherMoreComplexField", js_autogentestbindings_SimpleNativeClass_getAnotherMoreComplexField, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setSomeField", js_autogentestbindings_SimpleNativeClass_setSomeField, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("receivesLongLong", js_autogentestbindings_SimpleNativeClass_receivesLongLong, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("thisReturnsALongLong", js_autogentestbindings_SimpleNativeClass_thisReturnsALongLong, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setAnotherMoreComplexField", js_autogentestbindings_SimpleNativeClass_setAnotherMoreComplexField, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setSomeOtherField", js_autogentestbindings_SimpleNativeClass_setSomeOtherField, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("virtualFoo", js_autogentestbindings_SimpleNativeClass_virtualFoo, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getSomeOtherField", js_autogentestbindings_SimpleNativeClass_getSomeOtherField, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("instance_func", js_autogentestbindings_SimpleNativeClass_instance_func, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("returnsACString", js_autogentestbindings_SimpleNativeClass_returnsACString, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("doSomeProcessing", js_autogentestbindings_SimpleNativeClass_doSomeProcessing, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("instance_func_overroad", js_autogentestbindings_SimpleNativeClass_instance_func_overroad, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getSomeField", js_autogentestbindings_SimpleNativeClass_getSomeField, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("returnsAString", js_autogentestbindings_SimpleNativeClass_returnsAString, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("static_func", js_autogentestbindings_SimpleNativeClass_static_func, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("static_func_overroad", js_autogentestbindings_SimpleNativeClass_static_func_overroad, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("func", js_autogentestbindings_SimpleNativeClass_func, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	js_autogentestbindings_SimpleNativeClass_prototype = JS_InitClass(
		cx, global,
		NULL, // parent proto
		js_autogentestbindings_SimpleNativeClass_class,
		js_autogentestbindings_SimpleNativeClass_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "SimpleNativeClass", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<SimpleNativeClass> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = js_autogentestbindings_SimpleNativeClass_class;
		p->proto = js_autogentestbindings_SimpleNativeClass_prototype;
		p->parentProto = NULL;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}


JSClass  *js_autogentestbindings_SubClass_class;
JSObject *js_autogentestbindings_SubClass_prototype;

JSBool js_autogentestbindings_SubClass_foo(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	SubClass* cobj = (SubClass *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		std::string ret = cobj->foo(arg0);
		jsval jsret;
		jsret = std_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_autogentestbindings_SubClass_virtualFoo(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	SubClass* cobj = (SubClass *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		cobj->virtualFoo();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_autogentestbindings_SubClass_hello(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	SubClass* cobj = (SubClass *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		cobj->hello();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}


void js_autogentestbindings_SubClass_finalize(JSFreeOp *fop, JSObject *obj) {
//#ifdef COCOS2D_JAVASCRIPT
	LOGD("js_autogentestbindings_SubClass_finalize\n");
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JS_GET_NATIVE_PROXY(jsproxy, obj);
    if (jsproxy) {
        JS_GET_PROXY(nproxy, jsproxy->ptr);
        JS_REMOVE_PROXY(nproxy, jsproxy);
    }
//#endif 
}

void js_register_autogentestbindings_SubClass(JSContext *cx, JSObject *global) {
	js_autogentestbindings_SubClass_class = (JSClass *)calloc(1, sizeof(JSClass));
	js_autogentestbindings_SubClass_class->name = "SubClass";
	js_autogentestbindings_SubClass_class->addProperty = JS_PropertyStub;
	js_autogentestbindings_SubClass_class->delProperty = JS_PropertyStub;
	js_autogentestbindings_SubClass_class->getProperty = JS_PropertyStub;
	js_autogentestbindings_SubClass_class->setProperty = JS_StrictPropertyStub;
	js_autogentestbindings_SubClass_class->enumerate = JS_EnumerateStub;
	js_autogentestbindings_SubClass_class->resolve = JS_ResolveStub;
	js_autogentestbindings_SubClass_class->convert = JS_ConvertStub;
	js_autogentestbindings_SubClass_class->finalize = js_autogentestbindings_SubClass_finalize;
	js_autogentestbindings_SubClass_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	JSPropertySpec *properties = NULL;

	static JSFunctionSpec funcs[] = {
		JS_FN("foo", js_autogentestbindings_SubClass_foo, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("virtualFoo", js_autogentestbindings_SubClass_virtualFoo, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("hello", js_autogentestbindings_SubClass_hello, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	JSFunctionSpec *st_funcs = NULL;

	js_autogentestbindings_SubClass_prototype = JS_InitClass(
		cx, global,
		js_autogentestbindings_SimpleNativeClass_prototype,
		js_autogentestbindings_SubClass_class,
		dummy_constructor<SubClass>, 0, // no constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "SubClass", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<SubClass> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = js_autogentestbindings_SubClass_class;
		p->proto = js_autogentestbindings_SubClass_prototype;
		p->parentProto = js_autogentestbindings_SimpleNativeClass_prototype;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}


JSClass  *js_autogentestbindings_AnotherClass_class;
JSObject *js_autogentestbindings_AnotherClass_prototype;

JSBool js_autogentestbindings_AnotherClass_setJustOneField(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	SomeNamespace::AnotherClass* cobj = (SomeNamespace::AnotherClass *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		cobj->setJustOneField();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_autogentestbindings_AnotherClass_getJustOneField(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	SomeNamespace::AnotherClass* cobj = (SomeNamespace::AnotherClass *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		int ret = cobj->getJustOneField();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_autogentestbindings_AnotherClass_doSomethingSimple(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	SomeNamespace::AnotherClass* cobj = (SomeNamespace::AnotherClass *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		cobj->doSomethingSimple();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_autogentestbindings_AnotherClass_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{

	if (argc == 0) {
				SomeNamespace::AnotherClass* cobj = new SomeNamespace::AnotherClass();
//#ifdef COCOS2D_JAVASCRIPT
//		cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
//		if (_ccobj) {
//			_ccobj->autorelease();
//		}
//#endif
		TypeTest<SomeNamespace::AnotherClass> t;
		js_type_class_t *typeClass;
		uint32_t typeId = t.s_id();
		HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
		assert(typeClass);
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t *p;
		JS_NEW_PROXY(p, cobj, obj);
//#ifdef COCOS2D_JAVASCRIPT
//		JS_AddNamedObjectRoot(cx, &p->obj, "SomeNamespace::AnotherClass");
//#endif
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}



void js_autogentestbindings_AnotherClass_finalize(JSFreeOp *fop, JSObject *obj) {
//#ifdef COCOS2D_JAVASCRIPT
	LOGD("js_autogentestbindings_AnotherClass_finalize\n");
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JS_GET_NATIVE_PROXY(jsproxy, obj);
    if (jsproxy) {
        JS_GET_PROXY(nproxy, jsproxy->ptr);
        JS_REMOVE_PROXY(nproxy, jsproxy);
    }
//#endif 
}

void js_register_autogentestbindings_AnotherClass(JSContext *cx, JSObject *global) {
	js_autogentestbindings_AnotherClass_class = (JSClass *)calloc(1, sizeof(JSClass));
	js_autogentestbindings_AnotherClass_class->name = "AnotherClass";
	js_autogentestbindings_AnotherClass_class->addProperty = JS_PropertyStub;
	js_autogentestbindings_AnotherClass_class->delProperty = JS_PropertyStub;
	js_autogentestbindings_AnotherClass_class->getProperty = JS_PropertyStub;
	js_autogentestbindings_AnotherClass_class->setProperty = JS_StrictPropertyStub;
	js_autogentestbindings_AnotherClass_class->enumerate = JS_EnumerateStub;
	js_autogentestbindings_AnotherClass_class->resolve = JS_ResolveStub;
	js_autogentestbindings_AnotherClass_class->convert = JS_ConvertStub;
	js_autogentestbindings_AnotherClass_class->finalize = js_autogentestbindings_AnotherClass_finalize;
	js_autogentestbindings_AnotherClass_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, 0, 0}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("setJustOneField", js_autogentestbindings_AnotherClass_setJustOneField, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getJustOneField", js_autogentestbindings_AnotherClass_getJustOneField, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("doSomethingSimple", js_autogentestbindings_AnotherClass_doSomethingSimple, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	JSFunctionSpec *st_funcs = NULL;

	js_autogentestbindings_AnotherClass_prototype = JS_InitClass(
		cx, global,
		NULL, // parent proto
		js_autogentestbindings_AnotherClass_class,
		js_autogentestbindings_AnotherClass_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "AnotherClass", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<SomeNamespace::AnotherClass> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = js_autogentestbindings_AnotherClass_class;
		p->proto = js_autogentestbindings_AnotherClass_prototype;
		p->parentProto = NULL;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}

void register_all_autogentestbindings(JSContext* cx, JSObject* obj) {

	js_register_autogentestbindings_AnotherClass(cx, obj);
	js_register_autogentestbindings_SimpleNativeClass(cx, obj);
	js_register_autogentestbindings_SubClass(cx, obj);
}

