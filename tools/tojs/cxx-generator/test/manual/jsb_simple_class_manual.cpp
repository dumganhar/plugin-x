#include "jsb_simple_class_manual.h"
#include ""

extern JSObject *js_autogentestbindings_SimpleNativeClass_prototype;

static jsval anonEvaluate(JSContext *cx, JSObject *thisObj, const char* string) {
    jsval out;
    if (JS_EvaluateScript(cx, thisObj, string, strlen(string), "(string)", 1, &out) == JS_TRUE) {
        return out;
    }
    return JSVAL_VOID;
}

class JSB_MyCallbackDelegate : public MyCallbackDelegate
{
public:
    virtual void onCallback(SimpleNativeClass* cls, int arg)
    {
        // invoke js function.
        std::string jsFunctionName = "onCallback";
        js_proxy_t * p;
        JS_GET_PROXY(p, cls);
        if (!p) return;
        
        JSBool hasAction;
        jsval retval;
        jsval temp_retval;
        jsval dataVal[2];
        dataVal[0] = OBJECT_TO_JSVAL(p->obj);
        dataVal[1] = INT_TO_JSVAL(arg);
        
        JSContext* cx = ScriptingCore::getInstance()->getGlobalContext();
        JSObject* obj = m_pJSDelegate;
        
        if (JS_HasProperty(cx, obj, jsFunctionName.c_str(), &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, jsFunctionName.c_str(), &temp_retval)) {
                return;
            }
            if(temp_retval == JSVAL_VOID) {
                return;
            }
            JSAutoCompartment ac(cx, obj);
            JS_CallFunctionName(cx, obj, jsFunctionName.c_str(),
                                2, dataVal, &retval);
        }
    }


    void setJSDelegate(JSObject* pJSDelegate)
    {
        m_pJSDelegate = pJSDelegate;
    }
private:
    JSObject* m_pJSDelegate;
};

JSBool js_autogentestbindings_SimpleNativeClass_setDelegate(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    JSObject *obj = JS_THIS_OBJECT(cx, vp);
    js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
    SimpleNativeClass* cobj = (SimpleNativeClass *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");

    // if (argc == 1) {
    //     MyCallbackDelegate* arg0;
    //     do {
    //         js_proxy_t *proxy;
    //         JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
    //         JS_GET_NATIVE_PROXY(proxy, tmpObj);
    // proxy will always be NULL.
    //         arg0 = (MyCallbackDelegate*)(proxy ? proxy->ptr : NULL);
    //         JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
    //     } while (0);
    //     JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
    //     cobj->setDelegate(arg0);
    //     JS_SET_RVAL(cx, vp, JSVAL_VOID);
    //     return JS_TRUE;
    // }

    if (argc == 1) {
        MyCallbackDelegate* arg0 = new JSB_MyCallbackDelegate(); // memory leak?
        arg0->setJSDelegate(JSVAL_TO_OBJECT(argv[0]));  // save js delegate, used in cpp callback.
        cobj->setDelegate(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }

    JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
    return JS_FALSE;
}

void register_simple_class_extension(JSContext* cx, JSObject* obj)
{
       // first, try to get the ns
    jsval nsval;
    JSObject *ns;
    JS_GetProperty(cx, global, "myns", &nsval);
    if (nsval == JSVAL_VOID) {
        ns = JS_NewObject(cx, NULL, NULL, NULL);
        nsval = OBJECT_TO_JSVAL(ns);
        JS_SetProperty(cx, global, "myns", &nsval);
    } else {
        JS_ValueToObject(cx, nsval, &ns);
    }

    JSObject *tmpObj;

    // Static method
    // tmpObj = JSVAL_TO_OBJECT(anonEvaluate(cx, global, "(function () { return pluginx.ProtocolIAP; })()"));
    // JS_DefineFunction(cx, tmpObj, "setResultListener", js_pluginx_ProtocolIAP_setResultListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);

    // Member method
    JS_DefineFunction(cx, js_autogentestbindings_SimpleNativeClass_prototype, "setDelegate", js_autogentestbindings_SimpleNativeClass_setDelegate, 1, JSPROP_READONLY | JSPROP_PERMANENT);
}

