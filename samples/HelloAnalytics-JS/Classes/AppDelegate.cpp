#include "AppDelegate.h"

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "ScriptingCore.h"
#include "generated/cocos2dx.hpp"
#include "cocos2d_specifics.hpp"
#include "js_bindings_chipmunk_registration.h"
#include "js_bindings_system_registration.h"
#include "js_bindings_ccbreader.h"
#include "pluginx_protocols.hpp"
#include "pluginx_umeng.hpp"
#include "pluginx_flurry.hpp"
#include "cocos2dx_other.hpp"
#include "jsb_pluginx_extension_registration.h"

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
    CCScriptEngineManager::sharedManager()->purgeSharedManager();
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());
    
    // turn on display FPS
    pDirector->setDisplayStats(true);
    
    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);
    CCLOG("applicationDidFinishLaunching 01");
    ScriptingCore* sc = ScriptingCore::getInstance();
    sc->addRegisterCallback(register_all_cocos2dx);
    sc->addRegisterCallback(register_cocos2dx_js_extensions);
    sc->addRegisterCallback(register_CCBuilderReader);
    sc->addRegisterCallback(jsb_register_chipmunk);
    sc->addRegisterCallback(jsb_register_system);
    sc->addRegisterCallback(register_all_pluginx_protocols);
    sc->addRegisterCallback(register_all_pluginx_umeng);
    sc->addRegisterCallback(register_all_pluginx_flurry);
    sc->addRegisterCallback(register_pluginx_js_extensions);
    sc->addRegisterCallback(register_all_cocos2dx_other);
    sc->start();
    CCLOG("applicationDidFinishLaunching 02");
    CCScriptEngineProtocol *pEngine = ScriptingCore::getInstance();
    CCScriptEngineManager::sharedManager()->setScriptEngine(pEngine);
    ScriptingCore::getInstance()->runScript("main.js");
       CCLOG("applicationDidFinishLaunching 03");
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();

    ScriptingCore* sc = ScriptingCore::getInstance();
    jsval nsval;
    JS_GetProperty(sc->getGlobalContext(), sc->getGlobalObject(), "plugin", &nsval);
    if (nsval != JSVAL_VOID) {
        sc->executeFunctionWithOwner(nsval, "onApplicationDidEnterBackground", JSVAL_NULL);
    }
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();

    ScriptingCore* sc = ScriptingCore::getInstance();
    jsval nsval;
    JS_GetProperty(sc->getGlobalContext(), sc->getGlobalObject(), "plugin", &nsval);
    if (nsval != JSVAL_VOID) {
        sc->executeFunctionWithOwner(nsval, "onApplicationWillEnterForeground", JSVAL_NULL);
    }
}
