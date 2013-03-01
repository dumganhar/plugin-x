#include "jsapi.h"
#include "jsfriendapi.h"
#include "js_bindings_config.h"
#include "pluginx.hpp"
#include "PluginManager.h"
#include "IAPAlipay.h"
#include "IAPNd91.h"

template<class T>
static JSBool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
	TypeTest<T> t;
	T* cobj = new T();
#ifdef COCOS2D_JAVASCRIPT
	cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
	if (_ccobj) {
		_ccobj->autorelease();
	}
#endif
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	assert(p);
	JSObject *_tmp = JS_NewObject(cx, p->jsclass, p->proto, p->parentProto);
	js_proxy_t *pp;
	JS_NEW_PROXY(pp, cobj, _tmp);
	JS_AddObjectRoot(cx, &pp->obj);
	JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));

	return JS_TRUE;
}

static JSBool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
	return JS_FALSE;
}


JSClass  *js_pluginx_PluginProtocol_class;
JSObject *js_pluginx_PluginProtocol_prototype;

JSBool js_pluginx_PluginProtocol_setUserData(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::PluginProtocol* cobj = (cocos2d::plugin::PluginProtocol *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 1) {
		void* arg0;
		#pragma warning NO CONVERSION TO NATIVE FOR void*;
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setUserData(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_pluginx_PluginProtocol_getUserData(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::PluginProtocol* cobj = (cocos2d::plugin::PluginProtocol *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		void* ret = cobj->getUserData();
		jsval jsret;
		#pragma warning NO CONVERSION FROM NATIVE FOR void*;
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_pluginx_PluginProtocol_getPluginName(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::PluginProtocol* cobj = (cocos2d::plugin::PluginProtocol *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		const char* ret = cobj->getPluginName();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_pluginx_PluginProtocol_getPluginVersion(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::PluginProtocol* cobj = (cocos2d::plugin::PluginProtocol *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		const char* ret = cobj->getPluginVersion();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_pluginx_PluginProtocol_init(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::PluginProtocol* cobj = (cocos2d::plugin::PluginProtocol *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		bool ret = cobj->init();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_pluginx_PluginProtocol_setDebugMode(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::PluginProtocol* cobj = (cocos2d::plugin::PluginProtocol *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setDebugMode(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}


void js_pluginx_PluginProtocol_finalize(JSFreeOp *fop, JSObject *obj) {
}

void js_register_pluginx_PluginProtocol(JSContext *cx, JSObject *global) {
	js_pluginx_PluginProtocol_class = (JSClass *)calloc(1, sizeof(JSClass));
	js_pluginx_PluginProtocol_class->name = "PluginProtocol";
	js_pluginx_PluginProtocol_class->addProperty = JS_PropertyStub;
	js_pluginx_PluginProtocol_class->delProperty = JS_PropertyStub;
	js_pluginx_PluginProtocol_class->getProperty = JS_PropertyStub;
	js_pluginx_PluginProtocol_class->setProperty = JS_StrictPropertyStub;
	js_pluginx_PluginProtocol_class->enumerate = JS_EnumerateStub;
	js_pluginx_PluginProtocol_class->resolve = JS_ResolveStub;
	js_pluginx_PluginProtocol_class->convert = JS_ConvertStub;
	js_pluginx_PluginProtocol_class->finalize = js_pluginx_PluginProtocol_finalize;
	js_pluginx_PluginProtocol_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, 0, 0}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("setUserData", js_pluginx_PluginProtocol_setUserData, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getUserData", js_pluginx_PluginProtocol_getUserData, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPluginName", js_pluginx_PluginProtocol_getPluginName, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPluginVersion", js_pluginx_PluginProtocol_getPluginVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("init", js_pluginx_PluginProtocol_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setDebugMode", js_pluginx_PluginProtocol_setDebugMode, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	JSFunctionSpec *st_funcs = NULL;

	js_pluginx_PluginProtocol_prototype = JS_InitClass(
		cx, global,
		NULL, // parent proto
		js_pluginx_PluginProtocol_class,
		empty_constructor, 0,
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "PluginProtocol", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::plugin::PluginProtocol> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = js_pluginx_PluginProtocol_class;
		p->proto = js_pluginx_PluginProtocol_prototype;
		p->parentProto = NULL;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}


JSClass  *js_pluginx_PluginManager_class;
JSObject *js_pluginx_PluginManager_prototype;

JSBool js_pluginx_PluginManager_unloadPlugin(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::PluginManager* cobj = (cocos2d::plugin::PluginManager *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->unloadPlugin(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_pluginx_PluginManager_loadPlugin(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::PluginManager* cobj = (cocos2d::plugin::PluginManager *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cocos2d::plugin::PluginProtocol* ret = cobj->loadPlugin(arg0);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::plugin::PluginProtocol>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_pluginx_PluginManager_end(JSContext *cx, uint32_t argc, jsval *vp)
{
	cocos2d::plugin::PluginManager::end();
	JS_SET_RVAL(cx, vp, JSVAL_VOID);
	return JS_TRUE;
}

JSBool js_pluginx_PluginManager_getInstance(JSContext *cx, uint32_t argc, jsval *vp)
{
	cocos2d::plugin::PluginManager* ret = cocos2d::plugin::PluginManager::getInstance();
	jsval jsret;
	do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::plugin::PluginManager>(cx, ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
	JS_SET_RVAL(cx, vp, jsret);
	return JS_TRUE;
}



void js_pluginx_PluginManager_finalize(JSFreeOp *fop, JSObject *obj) {
}

void js_register_pluginx_PluginManager(JSContext *cx, JSObject *global) {
	js_pluginx_PluginManager_class = (JSClass *)calloc(1, sizeof(JSClass));
	js_pluginx_PluginManager_class->name = "PluginManager";
	js_pluginx_PluginManager_class->addProperty = JS_PropertyStub;
	js_pluginx_PluginManager_class->delProperty = JS_PropertyStub;
	js_pluginx_PluginManager_class->getProperty = JS_PropertyStub;
	js_pluginx_PluginManager_class->setProperty = JS_StrictPropertyStub;
	js_pluginx_PluginManager_class->enumerate = JS_EnumerateStub;
	js_pluginx_PluginManager_class->resolve = JS_ResolveStub;
	js_pluginx_PluginManager_class->convert = JS_ConvertStub;
	js_pluginx_PluginManager_class->finalize = js_pluginx_PluginManager_finalize;
	js_pluginx_PluginManager_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	JSPropertySpec *properties = NULL;

	static JSFunctionSpec funcs[] = {
		JS_FN("unloadPlugin", js_pluginx_PluginManager_unloadPlugin, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("loadPlugin", js_pluginx_PluginManager_loadPlugin, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("end", js_pluginx_PluginManager_end, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getInstance", js_pluginx_PluginManager_getInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	js_pluginx_PluginManager_prototype = JS_InitClass(
		cx, global,
		NULL, // parent proto
		js_pluginx_PluginManager_class,
		empty_constructor, 0,
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "PluginManager", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::plugin::PluginManager> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = js_pluginx_PluginManager_class;
		p->proto = js_pluginx_PluginManager_prototype;
		p->parentProto = NULL;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}


JSClass  *js_pluginx_ProtocolIAP_class;
JSObject *js_pluginx_ProtocolIAP_prototype;

JSBool js_pluginx_ProtocolIAP_initDeveloperInfo(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::ProtocolIAP* cobj = (cocos2d::plugin::ProtocolIAP *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 1) {
		TDeveloperInfo arg0;
		ok &= jsval_to_TDeveloperInfo(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->initDeveloperInfo(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_pluginx_ProtocolIAP_getPluginVersion(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::ProtocolIAP* cobj = (cocos2d::plugin::ProtocolIAP *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		const char* ret = cobj->getPluginVersion();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_pluginx_ProtocolIAP_init(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::ProtocolIAP* cobj = (cocos2d::plugin::ProtocolIAP *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		bool ret = cobj->init();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_pluginx_ProtocolIAP_payForProduct(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::ProtocolIAP* cobj = (cocos2d::plugin::ProtocolIAP *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 1) {
		TProductInfo arg0;
		ok &= jsval_to_TProductInfo(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->payForProduct(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_pluginx_ProtocolIAP_getSDKVersion(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::ProtocolIAP* cobj = (cocos2d::plugin::ProtocolIAP *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		const char* ret = cobj->getSDKVersion();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_pluginx_ProtocolIAP_setDebugMode(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::ProtocolIAP* cobj = (cocos2d::plugin::ProtocolIAP *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setDebugMode(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_pluginx_ProtocolIAP_getPluginName(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::ProtocolIAP* cobj = (cocos2d::plugin::ProtocolIAP *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		const char* ret = cobj->getPluginName();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_pluginx_ProtocolIAP_payResult(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;

	cocos2d::plugin::EPayResult arg0;
	const char* arg1;
	JSB_PRECONDITION2( argc >= 2, cx, JS_FALSE, "Invalid number of arguments" );

	ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
	std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
	JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
	cocos2d::plugin::ProtocolIAP::payResult(arg0, arg1);
	JS_SET_RVAL(cx, vp, JSVAL_VOID);
	return JS_TRUE;
}

JSBool js_pluginx_ProtocolIAP_setResultListener(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;

	cocos2d::plugin::PayResultListener* arg0;
	JSB_PRECONDITION2( argc >= 1, cx, JS_FALSE, "Invalid number of arguments" );

	do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg0 = (cocos2d::plugin::PayResultListener*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
	JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
	cocos2d::plugin::ProtocolIAP::setResultListener(arg0);
	JS_SET_RVAL(cx, vp, JSVAL_VOID);
	return JS_TRUE;
}



void js_pluginx_ProtocolIAP_finalize(JSFreeOp *fop, JSObject *obj) {
}

void js_register_pluginx_ProtocolIAP(JSContext *cx, JSObject *global) {
	js_pluginx_ProtocolIAP_class = (JSClass *)calloc(1, sizeof(JSClass));
	js_pluginx_ProtocolIAP_class->name = "ProtocolIAP";
	js_pluginx_ProtocolIAP_class->addProperty = JS_PropertyStub;
	js_pluginx_ProtocolIAP_class->delProperty = JS_PropertyStub;
	js_pluginx_ProtocolIAP_class->getProperty = JS_PropertyStub;
	js_pluginx_ProtocolIAP_class->setProperty = JS_StrictPropertyStub;
	js_pluginx_ProtocolIAP_class->enumerate = JS_EnumerateStub;
	js_pluginx_ProtocolIAP_class->resolve = JS_ResolveStub;
	js_pluginx_ProtocolIAP_class->convert = JS_ConvertStub;
	js_pluginx_ProtocolIAP_class->finalize = js_pluginx_ProtocolIAP_finalize;
	js_pluginx_ProtocolIAP_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	JSPropertySpec *properties = NULL;

	static JSFunctionSpec funcs[] = {
		JS_FN("initDeveloperInfo", js_pluginx_ProtocolIAP_initDeveloperInfo, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPluginVersion", js_pluginx_ProtocolIAP_getPluginVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("init", js_pluginx_ProtocolIAP_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("payForProduct", js_pluginx_ProtocolIAP_payForProduct, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getSDKVersion", js_pluginx_ProtocolIAP_getSDKVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setDebugMode", js_pluginx_ProtocolIAP_setDebugMode, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPluginName", js_pluginx_ProtocolIAP_getPluginName, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("payResult", js_pluginx_ProtocolIAP_payResult, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setResultListener", js_pluginx_ProtocolIAP_setResultListener, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	js_pluginx_ProtocolIAP_prototype = JS_InitClass(
		cx, global,
		js_pluginx_PluginProtocol_prototype,
		js_pluginx_ProtocolIAP_class,
		empty_constructor, 0,
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "ProtocolIAP", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::plugin::ProtocolIAP> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = js_pluginx_ProtocolIAP_class;
		p->proto = js_pluginx_ProtocolIAP_prototype;
		p->parentProto = js_pluginx_PluginProtocol_prototype;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}


JSClass  *js_pluginx_IAPAlipay_class;
JSObject *js_pluginx_IAPAlipay_prototype;

JSBool js_pluginx_IAPAlipay_getPluginName(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::IAPAlipay* cobj = (cocos2d::plugin::IAPAlipay *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		const char* ret = cobj->getPluginName();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_pluginx_IAPAlipay_getPluginVersion(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::IAPAlipay* cobj = (cocos2d::plugin::IAPAlipay *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		const char* ret = cobj->getPluginVersion();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_pluginx_IAPAlipay_init(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::IAPAlipay* cobj = (cocos2d::plugin::IAPAlipay *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		bool ret = cobj->init();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_pluginx_IAPAlipay_initDeveloperInfo(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::IAPAlipay* cobj = (cocos2d::plugin::IAPAlipay *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 1) {
		TDeveloperInfo arg0;
		ok &= jsval_to_TDeveloperInfo(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->initDeveloperInfo(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_pluginx_IAPAlipay_payForProduct(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::IAPAlipay* cobj = (cocos2d::plugin::IAPAlipay *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 1) {
		TProductInfo arg0;
		ok &= jsval_to_TProductInfo(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->payForProduct(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_pluginx_IAPAlipay_getSDKVersion(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::IAPAlipay* cobj = (cocos2d::plugin::IAPAlipay *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		const char* ret = cobj->getSDKVersion();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_pluginx_IAPAlipay_setDebugMode(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::IAPAlipay* cobj = (cocos2d::plugin::IAPAlipay *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setDebugMode(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_pluginx_IAPAlipay_createPlugin(JSContext *cx, uint32_t argc, jsval *vp)
{
	cocos2d::plugin::PluginProtocol* ret = cocos2d::plugin::IAPAlipay::createPlugin();
	jsval jsret;
	do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::plugin::PluginProtocol>(cx, ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
	JS_SET_RVAL(cx, vp, jsret);
	return JS_TRUE;
}



void js_pluginx_IAPAlipay_finalize(JSFreeOp *fop, JSObject *obj) {
}

void js_register_pluginx_IAPAlipay(JSContext *cx, JSObject *global) {
	js_pluginx_IAPAlipay_class = (JSClass *)calloc(1, sizeof(JSClass));
	js_pluginx_IAPAlipay_class->name = "IAPAlipay";
	js_pluginx_IAPAlipay_class->addProperty = JS_PropertyStub;
	js_pluginx_IAPAlipay_class->delProperty = JS_PropertyStub;
	js_pluginx_IAPAlipay_class->getProperty = JS_PropertyStub;
	js_pluginx_IAPAlipay_class->setProperty = JS_StrictPropertyStub;
	js_pluginx_IAPAlipay_class->enumerate = JS_EnumerateStub;
	js_pluginx_IAPAlipay_class->resolve = JS_ResolveStub;
	js_pluginx_IAPAlipay_class->convert = JS_ConvertStub;
	js_pluginx_IAPAlipay_class->finalize = js_pluginx_IAPAlipay_finalize;
	js_pluginx_IAPAlipay_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	JSPropertySpec *properties = NULL;

	static JSFunctionSpec funcs[] = {
		JS_FN("getPluginName", js_pluginx_IAPAlipay_getPluginName, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPluginVersion", js_pluginx_IAPAlipay_getPluginVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("init", js_pluginx_IAPAlipay_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("initDeveloperInfo", js_pluginx_IAPAlipay_initDeveloperInfo, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("payForProduct", js_pluginx_IAPAlipay_payForProduct, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getSDKVersion", js_pluginx_IAPAlipay_getSDKVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setDebugMode", js_pluginx_IAPAlipay_setDebugMode, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("createPlugin", js_pluginx_IAPAlipay_createPlugin, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	js_pluginx_IAPAlipay_prototype = JS_InitClass(
		cx, global,
		js_pluginx_ProtocolIAP_prototype,
		js_pluginx_IAPAlipay_class,
		empty_constructor, 0,
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "IAPAlipay", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::plugin::IAPAlipay> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = js_pluginx_IAPAlipay_class;
		p->proto = js_pluginx_IAPAlipay_prototype;
		p->parentProto = js_pluginx_ProtocolIAP_prototype;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}


JSClass  *js_pluginx_IAPNd91_class;
JSObject *js_pluginx_IAPNd91_prototype;

JSBool js_pluginx_IAPNd91_getPluginName(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::IAPNd91* cobj = (cocos2d::plugin::IAPNd91 *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		const char* ret = cobj->getPluginName();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_pluginx_IAPNd91_getPluginVersion(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::IAPNd91* cobj = (cocos2d::plugin::IAPNd91 *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		const char* ret = cobj->getPluginVersion();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_pluginx_IAPNd91_init(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::IAPNd91* cobj = (cocos2d::plugin::IAPNd91 *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		bool ret = cobj->init();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_pluginx_IAPNd91_initDeveloperInfo(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::IAPNd91* cobj = (cocos2d::plugin::IAPNd91 *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 1) {
		TDeveloperInfo arg0;
		ok &= jsval_to_TDeveloperInfo(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->initDeveloperInfo(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_pluginx_IAPNd91_payForProduct(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::IAPNd91* cobj = (cocos2d::plugin::IAPNd91 *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 1) {
		TProductInfo arg0;
		ok &= jsval_to_TProductInfo(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->payForProduct(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_pluginx_IAPNd91_getSDKVersion(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::IAPNd91* cobj = (cocos2d::plugin::IAPNd91 *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 0) {
		const char* ret = cobj->getSDKVersion();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_pluginx_IAPNd91_setDebugMode(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::plugin::IAPNd91* cobj = (cocos2d::plugin::IAPNd91 *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setDebugMode(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_pluginx_IAPNd91_createPlugin(JSContext *cx, uint32_t argc, jsval *vp)
{
	cocos2d::plugin::PluginProtocol* ret = cocos2d::plugin::IAPNd91::createPlugin();
	jsval jsret;
	do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::plugin::PluginProtocol>(cx, ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
	JS_SET_RVAL(cx, vp, jsret);
	return JS_TRUE;
}



void js_pluginx_IAPNd91_finalize(JSFreeOp *fop, JSObject *obj) {
}

void js_register_pluginx_IAPNd91(JSContext *cx, JSObject *global) {
	js_pluginx_IAPNd91_class = (JSClass *)calloc(1, sizeof(JSClass));
	js_pluginx_IAPNd91_class->name = "IAPNd91";
	js_pluginx_IAPNd91_class->addProperty = JS_PropertyStub;
	js_pluginx_IAPNd91_class->delProperty = JS_PropertyStub;
	js_pluginx_IAPNd91_class->getProperty = JS_PropertyStub;
	js_pluginx_IAPNd91_class->setProperty = JS_StrictPropertyStub;
	js_pluginx_IAPNd91_class->enumerate = JS_EnumerateStub;
	js_pluginx_IAPNd91_class->resolve = JS_ResolveStub;
	js_pluginx_IAPNd91_class->convert = JS_ConvertStub;
	js_pluginx_IAPNd91_class->finalize = js_pluginx_IAPNd91_finalize;
	js_pluginx_IAPNd91_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	JSPropertySpec *properties = NULL;

	static JSFunctionSpec funcs[] = {
		JS_FN("getPluginName", js_pluginx_IAPNd91_getPluginName, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPluginVersion", js_pluginx_IAPNd91_getPluginVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("init", js_pluginx_IAPNd91_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("initDeveloperInfo", js_pluginx_IAPNd91_initDeveloperInfo, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("payForProduct", js_pluginx_IAPNd91_payForProduct, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getSDKVersion", js_pluginx_IAPNd91_getSDKVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setDebugMode", js_pluginx_IAPNd91_setDebugMode, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("createPlugin", js_pluginx_IAPNd91_createPlugin, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	js_pluginx_IAPNd91_prototype = JS_InitClass(
		cx, global,
		js_pluginx_ProtocolIAP_prototype,
		js_pluginx_IAPNd91_class,
		empty_constructor, 0,
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "IAPNd91", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::plugin::IAPNd91> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = js_pluginx_IAPNd91_class;
		p->proto = js_pluginx_IAPNd91_prototype;
		p->parentProto = js_pluginx_ProtocolIAP_prototype;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}

void register_all_pluginx(JSContext* cx, JSObject* obj) {
	// first, try to get the ns
	jsval nsval;
	JSObject *ns;
	JS_GetProperty(cx, obj, "pluginx", &nsval);
	if (nsval == JSVAL_VOID) {
		ns = JS_NewObject(cx, NULL, NULL, NULL);
		nsval = OBJECT_TO_JSVAL(ns);
		JS_SetProperty(cx, obj, "pluginx", &nsval);
	} else {
		JS_ValueToObject(cx, nsval, &ns);
	}
	obj = ns;

	js_register_pluginx_PluginProtocol(cx, obj);
	js_register_pluginx_ProtocolIAP(cx, obj);
	js_register_pluginx_IAPNd91(cx, obj);
	js_register_pluginx_PluginManager(cx, obj);
	js_register_pluginx_IAPAlipay(cx, obj);
}

