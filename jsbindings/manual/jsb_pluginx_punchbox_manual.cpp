#include "jsb_pluginx_punchbox_manual.h"
#include "jsb_pluginx_basic_conversions.h"
#include "jsb_pluginx_spidermonkey_specifics.h"
#include "AnalyticsPunchbox.h"

using namespace pluginx;

static JSContext* s_cx = NULL;

static jsval anonEvaluate(JSContext *cx, JSObject *thisObj, const char* string) {
    jsval out;
    if (JS_EvaluateScript(cx, thisObj, string, strlen(string), "(string)", 1, &out) == JS_TRUE) {
        return out;
    }
    return JSVAL_VOID;
}

class JSB_RedeemListener : public cocos2d::plugin::RedeemListener
{
public:
    virtual void redeemSuccess(int returnID)
    {   
        JSContext* cx = s_cx;

        JSBool hasAction;
        jsval retval;
        jsval temp_retval;
        jsval dataVal[1];
        dataVal[0] = INT_TO_JSVAL(returnID);
        const char* functionName = "redeemSuccess";
        LOGD("%s, return id = %d", functionName, returnID);
        JSObject* obj = m_pJSDelegate;
        
        if (JS_HasProperty(cx, obj, functionName, &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, functionName, &temp_retval)) {
                LOGD("skip...");
                return;
            }
            if(temp_retval == JSVAL_VOID) {
                LOGD("JSVAL_VOID...");
                return;
            }
            LOGD("JS_CallFunctionName...");
            JSAutoCompartment ac(cx, obj);
            JS_CallFunctionName(cx, obj, functionName,
                                1, dataVal, &retval);
        }
        LOGD("end %s, return id = %d", functionName, returnID);
    }

    virtual void redeemFailed(ERedeemErrorCode code, const char* msg)
    {
        JSContext* cx = s_cx;

        JSBool hasAction;
        jsval retval;
        jsval temp_retval;
        jsval dataVal[2];
        dataVal[0] = INT_TO_JSVAL(code);
        std::string strMsgInfo = msg;
        dataVal[1] = std_string_to_jsval(cx, strMsgInfo);
        const char* functionName = "redeemFailed";
        LOGD("%s, return code = %d", functionName, code);
        JSObject* obj = m_pJSDelegate;
        
        if (JS_HasProperty(cx, obj, functionName, &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, functionName, &temp_retval)) {
                LOGD("skip...");
                return;
            }
            if(temp_retval == JSVAL_VOID) {
                LOGD("JSVAL_VOID...");
                return;
            }
            LOGD("JS_CallFunctionName...");
            JSAutoCompartment ac(cx, obj);
            JS_CallFunctionName(cx, obj, functionName,
                                2, dataVal, &retval);
        }
        LOGD("end %s, return code = %d", functionName, code);
    }

    void setJSDelegate(JSObject* pJSDelegate)
    {
        m_pJSDelegate = pJSDelegate;
    }

private:
    JSObject* m_pJSDelegate;
};

class JSB_FeedbackListener : public cocos2d::plugin::FeedbackListener
{
public:
    virtual void feedbackResult(EFeedResult ret, const char* msg)
    {
        JSContext* cx = s_cx;

        JSBool hasAction;
        jsval retval;
        jsval temp_retval;
        jsval dataVal[2];
        dataVal[0] = INT_TO_JSVAL(ret);
        std::string strMsgInfo = msg;
        dataVal[1] = std_string_to_jsval(cx, strMsgInfo);
        const char* functionName = "feedbackResult";
        LOGD("%s, return ret = %d", functionName, ret);

        JSObject* obj = m_pJSDelegate;
        
        if (JS_HasProperty(cx, obj, functionName, &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, functionName, &temp_retval)) {
                LOGD("skip...");
                return;
            }
            if(temp_retval == JSVAL_VOID) {
                LOGD("JSVAL_VOID...");
                return;
            }
            LOGD("JS_CallFunctionName...");
            JSAutoCompartment ac(cx, obj);
            JS_CallFunctionName(cx, obj, functionName,
                                2, dataVal, &retval);
        }

        LOGD("end %s, return ret = %d", functionName, ret);
    }

    void setJSDelegate(JSObject* pJSDelegate)
    {
        m_pJSDelegate = pJSDelegate;
    }

private:
    JSObject* m_pJSDelegate;
};

JSBool js_pluginx_Punchbox_setRedeemListener(JSContext *cx, uint32_t argc, jsval *vp)
{
    s_cx = cx;
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;

    if (argc == 1) {
        // save the delegate
        JSObject *jsDelegate = JSVAL_TO_OBJECT(argv[0]);
        JSB_RedeemListener* nativeDelegate = new JSB_RedeemListener();
        nativeDelegate->setJSDelegate(jsDelegate);
        cocos2d::plugin::AnalyticsPunchbox::setRedeemListener(nativeDelegate);
        
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }

    JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
    return JS_FALSE;
}

JSBool js_pluginx_Punchbox_setFeedbackListener(JSContext *cx, uint32_t argc, jsval *vp)
{
    s_cx = cx;
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;

    if (argc == 1) {
        // save the delegate
        JSObject *jsDelegate = JSVAL_TO_OBJECT(argv[0]);
        JSB_FeedbackListener* nativeDelegate = new JSB_FeedbackListener();
        nativeDelegate->setJSDelegate(jsDelegate);
        cocos2d::plugin::AnalyticsPunchbox::setFeedbackListener(nativeDelegate);
        
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }

    JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
    return JS_FALSE;
}

void register_pluginx_punchbox_manual(JSContext* cx, JSObject* global)
{
    // first, try to get the ns
    jsval nsval;
    JSObject *ns;
    JS_GetProperty(cx, global, "plugin", &nsval);
    if (nsval == JSVAL_VOID) {
        ns = JS_NewObject(cx, NULL, NULL, NULL);
        nsval = OBJECT_TO_JSVAL(ns);
        JS_SetProperty(cx, global, "plugin", &nsval);
    } else {
        JS_ValueToObject(cx, nsval, &ns);
    }

    JSObject *tmpObj;

    tmpObj = JSVAL_TO_OBJECT(anonEvaluate(cx, global, "(function () { return plugin.AnalyticsPunchbox; })()"));
    JS_DefineFunction(cx, tmpObj, "setFeedbackListener", js_pluginx_Punchbox_setFeedbackListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
    JS_DefineFunction(cx, tmpObj, "setRedeemListener", js_pluginx_Punchbox_setRedeemListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
}
