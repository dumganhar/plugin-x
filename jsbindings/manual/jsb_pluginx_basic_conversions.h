#ifndef __JSB_PLUGINX_BASIC_CONVERSIONS_H__
#define __JSB_PLUGINX_BASIC_CONVERSIONS_H__

#include "jsapi.h"
#include "jsfriendapi.h"

#include "ProtocolIAP.h"

using namespace cocos2d::plugin;

JSBool jsval_to_TProductInfo(JSContext *cx, jsval v, TProductInfo* ret);
JSBool jsval_to_TDeveloperInfo(JSContext *cx, jsval v, TDeveloperInfo* ret);

jsval TProductInfo_to_jsval(JSContext *cx, TProductInfo& ret);

#endif /* __JSB_PLUGINX_BASIC_CONVERSIONS_H__ */
