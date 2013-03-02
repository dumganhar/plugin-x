#include "jsb_pluginx_registration.h"
#include "pluginx.hpp"
#include "jsb_pluginx_extension_registration.h"

void jsb_register_pluginx(JSContext* cx, JSObject* global)
{
    register_all_pluginx(cx, global);
    register_pluginx_js_extensions(cx, global);
}