#ifndef __JSB_PLUGINX_BASIC_CONVERSIONS_H__
#define __JSB_PLUGINX_BASIC_CONVERSIONS_H__

#include "jsapi.h"
#include "jsfriendapi.h"

#include "ProtocolIAP.h"

using namespace cocos2d::plugin;

namespace pluginx {

// to native
JSBool jsval_to_int32( JSContext *cx, jsval vp, int32_t *ret );
JSBool jsval_to_uint32( JSContext *cx, jsval vp, uint32_t *ret );
JSBool jsval_to_uint16( JSContext *cx, jsval vp, uint16_t *ret );
JSBool jsval_to_long_long(JSContext *cx, jsval v, long long* ret);
JSBool jsval_to_std_string(JSContext *cx, jsval v, std::string* ret);
JSBool jsval_to_TProductInfo(JSContext *cx, jsval v, TProductInfo* ret);
JSBool jsval_to_TDeveloperInfo(JSContext *cx, jsval v, TDeveloperInfo* ret);

// from native
jsval int32_to_jsval( JSContext *cx, int32_t l);
jsval uint32_to_jsval( JSContext *cx, uint32_t number );
jsval long_long_to_jsval(JSContext* cx, long long v);
jsval std_string_to_jsval(JSContext* cx, std::string& v);
jsval c_string_to_jsval(JSContext* cx, const char* v);
jsval TProductInfo_to_jsval(JSContext *cx, TProductInfo& ret);


} // namespace pluginx {

#endif /* __JSB_PLUGINX_BASIC_CONVERSIONS_H__ */
