/**
 * @module pluginx_punchbox
 */
var plugin = plugin || {};

/**
 * @class IAPPunchbox
 */
plugin.IAPPunchbox = {

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

};

/**
 * @class AnalyticsPunchbox
 */
plugin.AnalyticsPunchbox = {

/**
 * @method confirmPay
 * @param {TPaymentInfo}
 */
confirmPay : function () {},

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
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method userFeedback
 * @param {const char*}
 * @param {const char*}
 */
userFeedback : function () {},

/**
 * @method redeemWithCode
 * @param {const char*}
 */
redeemWithCode : function () {},

/**
 * @method stopSession
 */
stopSession : function () {},

/**
 * @method startSessionWithpath
 * @param {const char*}
 * @param {const char*}
 */
startSessionWithpath : function () {},

/**
 * @method preparePay
 * @param {TPaymentInfo}
 */
preparePay : function () {},

/**
 * @method setDebugMode
 * @param {bool}
 */
setDebugMode : function () {},

};
