/**
 * @module pluginx
 */
var pluginx = pluginx = pluginx || {};

/**
 * @class PluginProtocol
 */
pluginx.PluginProtocol = {

/**
 * @method setUserData
 * @param {void*}
 */
setUserData : function () {},

/**
 * @method getUserData
 * @return A value converted from C/C++ "void*"
 */
getUserData : function () {},

/**
 * @method getPluginName
 * @return A value converted from C/C++ "const char*"
 */
getPluginName : function () {},

/**
 * @method getPluginVersion
 * @return A value converted from C/C++ "const char*"
 */
getPluginVersion : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method setDebugMode
 * @param {bool}
 */
setDebugMode : function () {},

};

/**
 * @class PluginManager
 */
pluginx.PluginManager = {

/**
 * @method unloadPlugin
 * @param {const char*}
 */
unloadPlugin : function () {},

/**
 * @method loadPlugin
 * @return A value converted from C/C++ "cocos2d::plugin::PluginProtocol*"
 * @param {const char*}
 */
loadPlugin : function () {},

/**
 * @method end
 */
end : function () {},

/**
 * @method getInstance
 * @return A value converted from C/C++ "cocos2d::plugin::PluginManager*"
 */
getInstance : function () {},

};

/**
 * @class ProtocolIAP
 */
pluginx.ProtocolIAP = {

/**
 * @method initDeveloperInfo
 * @param {TDeveloperInfo}
 */
initDeveloperInfo : function () {},

/**
 * @method getPluginVersion
 * @return A value converted from C/C++ "const char*"
 */
getPluginVersion : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method payForProduct
 * @param {TProductInfo}
 */
payForProduct : function () {},

/**
 * @method getSDKVersion
 * @return A value converted from C/C++ "const char*"
 */
getSDKVersion : function () {},

/**
 * @method setDebugMode
 * @param {bool}
 */
setDebugMode : function () {},

/**
 * @method getPluginName
 * @return A value converted from C/C++ "const char*"
 */
getPluginName : function () {},

/**
 * @method payResult
 * @param {cocos2d::plugin::EPayResult}
 * @param {const char*}
 */
payResult : function () {},

/**
 * @method setResultListener
 * @param {cocos2d::plugin::PayResultListener*}
 */
setResultListener : function () {},

};

/**
 * @class IAPAlipay
 */
pluginx.IAPAlipay = {

/**
 * @method getPluginName
 * @return A value converted from C/C++ "const char*"
 */
getPluginName : function () {},

/**
 * @method getPluginVersion
 * @return A value converted from C/C++ "const char*"
 */
getPluginVersion : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method initDeveloperInfo
 * @param {TDeveloperInfo}
 */
initDeveloperInfo : function () {},

/**
 * @method payForProduct
 * @param {TProductInfo}
 */
payForProduct : function () {},

/**
 * @method getSDKVersion
 * @return A value converted from C/C++ "const char*"
 */
getSDKVersion : function () {},

/**
 * @method setDebugMode
 * @param {bool}
 */
setDebugMode : function () {},

/**
 * @method createPlugin
 * @return A value converted from C/C++ "cocos2d::plugin::PluginProtocol*"
 */
createPlugin : function () {},

};

/**
 * @class IAPNd91
 */
pluginx.IAPNd91 = {

/**
 * @method getPluginName
 * @return A value converted from C/C++ "const char*"
 */
getPluginName : function () {},

/**
 * @method getPluginVersion
 * @return A value converted from C/C++ "const char*"
 */
getPluginVersion : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method initDeveloperInfo
 * @param {TDeveloperInfo}
 */
initDeveloperInfo : function () {},

/**
 * @method payForProduct
 * @param {TProductInfo}
 */
payForProduct : function () {},

/**
 * @method getSDKVersion
 * @return A value converted from C/C++ "const char*"
 */
getSDKVersion : function () {},

/**
 * @method setDebugMode
 * @param {bool}
 */
setDebugMode : function () {},

/**
 * @method createPlugin
 * @return A value converted from C/C++ "cocos2d::plugin::PluginProtocol*"
 */
createPlugin : function () {},

};
