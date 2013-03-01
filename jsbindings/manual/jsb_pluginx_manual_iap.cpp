#include "jsb_pluginx_manual_iap.h"
#include "jsb_pluginx_basic_conversions.h"
#include "cocos2d.h"
#include "cocos2d_specifics.hpp"
#include "ScriptingCore.h"

using namespace cocos2d;
//extern JSObject *js_pluginx_ProtocolIAP_prototype;

class Pluginx_PurchaseResult : public cocos2d::plugin::PayResultListener
{
public:
    virtual void payResult(cocos2d::plugin::EPayResult ret, const char* msg, cocos2d::plugin::TProductInfo info)
    {
        char goodInfo[1024] = { 0 };
        sprintf(goodInfo, "商品名称:%s\n商品价格:%s\n商品描述:%s",
                info.find("productName")->second.c_str(),
                info.find("productPrice")->second.c_str(),
                info.find("productDesc")->second.c_str());
        CCMessageBox(goodInfo , msg);
        
        JSContext* cx = ScriptingCore::getInstance()->getGlobalContext();

        JSBool hasAction;
        jsval retval;
        jsval temp_retval;
        jsval dataVal[3];
        dataVal[0] = INT_TO_JSVAL(ret);
        std::string strMsgInfo = msg;
        dataVal[1] = std_string_to_jsval(cx, strMsgInfo);
        dataVal[2] = TProductInfo_to_jsval(cx, info);
        
        JSObject* obj = m_pJSDelegate;
        
        if (JS_HasProperty(cx, obj, "payResult", &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, "payResult", &temp_retval)) {
                return;
            }
            if(temp_retval == JSVAL_VOID) {
                return;
            }
            JSAutoCompartment ac(cx, obj);
            JS_CallFunctionName(cx, obj, "payResult",
                                3, dataVal, &retval);
        }
    }

    void setJSDelegate(JSObject* pJSDelegate)
    {
        m_pJSDelegate = pJSDelegate;
    }

private:
    JSObject* m_pJSDelegate;
};

JSBool js_pluginx_ProtocolIAP_setResultListener(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;

    if (argc == 1) {
        // save the delegate
        JSObject *jsDelegate = JSVAL_TO_OBJECT(argv[0]);
        Pluginx_PurchaseResult* nativeDelegate = new Pluginx_PurchaseResult();
        nativeDelegate->setJSDelegate(jsDelegate);
        cocos2d::plugin::ProtocolIAP::setResultListener(nativeDelegate);
        
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }

    JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
    return JS_FALSE;
}