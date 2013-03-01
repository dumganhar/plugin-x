#include "jsb_pluginx_basic_conversions.h"
#include "ScriptingCore.h"

JSBool jsval_to_TProductInfo(JSContext *cx, jsval v, TProductInfo* ret)
{
    JSObject* tmp = JSVAL_TO_OBJECT(v);
    JSObject* it = JS_NewPropertyIterator(cx, tmp);

    while (true)
    {
        jsid idp;
        jsval key;
        if (! JS_NextProperty(cx, it, &idp) || ! JS_IdToValue(cx, idp, &key))
            return JS_FALSE; // error
        if (key == JSVAL_VOID)
            break; // end of iteration
        if (! JSVAL_IS_STRING(key))
            continue; // ignore integer properties
        jsval value;
        JS_GetPropertyById(cx, tmp, idp, &value);
        if (! JSVAL_IS_STRING(value))
            continue; // ignore integer properties

        JSStringWrapper strWrapper(JSVAL_TO_STRING(key));
        JSStringWrapper strWrapper2(JSVAL_TO_STRING(value));

        (*ret)[strWrapper.get()] = strWrapper2.get();
        CCLOG("iterate object: key = %s, value = %s", strWrapper.get().c_str(), strWrapper2.get().c_str());
    }

    return JS_TRUE;
}

JSBool jsval_to_TDeveloperInfo(JSContext *cx, jsval v, TDeveloperInfo* ret)
{
    return jsval_to_TProductInfo(cx, v, ret);
}