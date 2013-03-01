#ifndef __JSB_PLUGINX_EXTENSION_REGISTRATION_H__
#define __JSB_PLUGINX_EXTENSION_REGISTRATION_H__

#include "jsapi.h"
#include "jsfriendapi.h"

void register_pluginx_js_extensions(JSContext* cx, JSObject* global);

#endif /* __JSB_PLUGINX_EXTENSION_REGISTRATION_H__ */
