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

/**
 * @class ProtocolAnalytics
 */
pluginx.ProtocolAnalytics = {

/**
 * @method logTimedEventBegin
 * @param {const char*}
 */
logTimedEventBegin : function () {},

/**
 * @method logError
 * @param {const char*}
 * @param {const char*}
 */
logError : function () {},

/**
 * @method setCaptureUncaughtException
 * @param {bool}
 */
setCaptureUncaughtException : function () {},

/**
 * @method getSDKVersion
 * @return A value converted from C/C++ "const char*"
 */
getSDKVersion : function () {},

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
 * @method logEvent
 * @param {const char*}
 * @param {LogEventParamMap*}
 * @param {double}
 */
logEvent : function () {},

/**
 * @method setSessionContinueMillis
 * @param {long}
 */
setSessionContinueMillis : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method startSession
 * @param {const char*}
 */
startSession : function () {},

/**
 * @method stopSession
 */
stopSession : function () {},

/**
 * @method logTimedEventEnd
 * @param {const char*}
 */
logTimedEventEnd : function () {},

/**
 * @method aaadfasdf
 */
aaadfasdf : function () {},

/**
 * @method setDebugMode
 * @param {bool}
 */
setDebugMode : function () {},

};

/**
 * @class AnalyticsFlurry
 */
pluginx.AnalyticsFlurry = {

/**
 * @method setUserId
 * @param {const char*}
 */
setUserId : function () {},

/**
 * @method logError
 * @param {const char*}
 * @param {const char*}
 */
logError : function () {},

/**
 * @method setCaptureUncaughtException
 * @param {bool}
 */
setCaptureUncaughtException : function () {},

/**
 * @method setGender
 * @param {cocos2d::plugin::AnalyticsFlurry::Gender}
 */
setGender : function () {},

/**
 * @method logPageView
 */
logPageView : function () {},

/**
 * @method getPluginName
 * @return A value converted from C/C++ "const char*"
 */
getPluginName : function () {},

/**
 * @method setReportLocation
 * @param {bool}
 */
setReportLocation : function () {},

/**
 * @method getPluginVersion
 * @return A value converted from C/C++ "const char*"
 */
getPluginVersion : function () {},

/**
 * @method logEvent
 * @param {const char*}
 * @param {LogEventParamMap*}
 */
logEvent : function () {},

/**
 * @method setSessionContinueMillis
 * @param {long}
 */
setSessionContinueMillis : function () {},

/**
 * @method setAge
 * @param {int}
 */
setAge : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method setVersionName
 * @param {const char*}
 */
setVersionName : function () {},

/**
 * @method startSession
 * @param {const char*}
 */
startSession : function () {},

/**
 * @method stopSession
 */
stopSession : function () {},

/**
 * @method setUseHttps
 * @param {bool}
 */
setUseHttps : function () {},

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
 * @class AnalyticsUmeng
 */
pluginx.AnalyticsUmeng = {

/**
 * @method setSessionContinueMillis
 * @param {long}
 */
setSessionContinueMillis : function () {},

/**
 * @method stopSession
 */
stopSession : function () {},

/**
 * @method getSDKVersion
 * @return A value converted from C/C++ "const char*"
 */
getSDKVersion : function () {},

/**
 * @method updateOnlineConfig
 */
updateOnlineConfig : function () {},

/**
 * @method logTimedEventBegin
 * @param {const char*}
 */
logTimedEventBegin : function () {},

/**
 * @method logError
 * @param {const char*}
 * @param {const char*}
 */
logError : function () {},

/**
 * @method checkUpdate
 */
checkUpdate : function () {},

/**
 * @method getPluginVersion
 * @return A value converted from C/C++ "const char*"
 */
getPluginVersion : function () {},

/**
 * @method setDefaultReportPolicy
 * @param {cocos2d::plugin::AnalyticsUmeng::UmengReportPolicy}
 */
setDefaultReportPolicy : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method logTimedKVEventEnd
 * @param {const char*}
 * @param {const char*}
 */
logTimedKVEventEnd : function () {},

/**
 * @method logTimedKVEventBegin
 * @param {const char*}
 * @param {const char*}
 * @param {LogEventParamMap*}
 */
logTimedKVEventBegin : function () {},

/**
 * @method setCaptureUncaughtException
 * @param {bool}
 */
setCaptureUncaughtException : function () {},

/**
 * @method getConfigParams
 * @return A value converted from C/C++ "const char*"
 * @param {const char*}
 */
getConfigParams : function () {},

/**
 * @method getPluginName
 * @return A value converted from C/C++ "const char*"
 */
getPluginName : function () {},

/**
 * @method logTimedEventWithLabelBegin
 * @param {const char*}
 * @param {const char*}
 */
logTimedEventWithLabelBegin : function () {},

/**
 * @method logTimedEventWithLabelEnd
 * @param {const char*}
 * @param {const char*}
 */
logTimedEventWithLabelEnd : function () {},

/**
 * @method logEvent
 * @param {const char*}
 * @param {LogEventParamMap*}
 */
logEvent : function () {},

/**
 * @method logTimedEventEnd
 * @param {const char*}
 */
logTimedEventEnd : function () {},

/**
 * @method logEventWithLabel
 * @param {const char*}
 * @param {const char*}
 */
logEventWithLabel : function () {},

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
