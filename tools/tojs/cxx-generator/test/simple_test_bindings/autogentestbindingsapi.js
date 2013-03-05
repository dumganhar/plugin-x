
/**
 * @class SimpleNativeClass
 */
SimpleNativeClass = {

/**
 * @method getAnotherMoreComplexField
 * @return A value converted from C/C++ "const char*"
 */
getAnotherMoreComplexField : function () {},

/**
 * @method receivesLongLong
 * @return A value converted from C/C++ "long long"
 * @param {long long}
 */
receivesLongLong : function () {},

/**
 * @method thisReturnsALongLong
 * @return A value converted from C/C++ "long long"
 */
thisReturnsALongLong : function () {},

/**
 * @method setAnotherMoreComplexField
 * @param {const char*}
 */
setAnotherMoreComplexField : function () {},

/**
 * @method setSomeOtherField
 * @param {int}
 */
setSomeOtherField : function () {},

/**
 * @method virtualFoo
 */
virtualFoo : function () {},

/**
 * @method getSomeOtherField
 * @return A value converted from C/C++ "int"
 */
getSomeOtherField : function () {},

/**
 * @method instance_func
 * @return A value converted from C/C++ "int"
 * @param {int}
 * @param {std::string}
 */
instance_func : function () {},

/**
 * @method returnsACString
 * @return A value converted from C/C++ "const char*"
 */
returnsACString : function () {},

/**
 * @method doSomeProcessing
 * @return A value converted from C/C++ "int"
 * @param {std::string}
 * @param {std::string}
 */
doSomeProcessing : function () {},

/**
 * @method getSomeField
 * @return A value converted from C/C++ "int"
 */
getSomeField : function () {},

/**
 * @method returnsAString
 * @return A value converted from C/C++ "std::string"
 */
returnsAString : function () {},

/**
 * @method static_func
 * @return A value converted from C/C++ "int"
 * @param {int}
 * @param {std::string}
 */
static_func : function () {},

};

/**
 * @class SubClass
 */
SubClass = {

/**
 * @method foo
 * @return A value converted from C/C++ "std::string"
 * @param {int}
 */
foo : function () {},

/**
 * @method virtualFoo
 */
virtualFoo : function () {},

/**
 * @method hello
 */
hello : function () {},

};

/**
 * @class AnotherClass
 */
AnotherClass = {

/**
 * @method setJustOneField
 */
setJustOneField : function () {},

/**
 * @method getJustOneField
 * @return A value converted from C/C++ "int"
 */
getJustOneField : function () {},

/**
 * @method doSomethingSimple
 */
doSomethingSimple : function () {},

/**
 * @method AnotherClass
 * @constructor
 */
AnotherClass : function () {},

};
