//
//  MainController.cpp
//  cocos2d_libs
//
//  Created by barton on 14/12/1.
//
//

#include "MainController.h"
#include "GameActionManager.h"
#include "cocos2d.h"
#include "CCLuaEngine.h"
#include "pbc-lua.h"


static MainController* g_mainController = NULL;
MainController::MainController()
{
    Director::getInstance()->getScheduler()->scheduleUpdate(this, 0, false);
}

MainController::~MainController()
{
    Director::getInstance()->getScheduler()->unscheduleAllForTarget(this);
}

MainController* MainController::getInstance()
{
    if (NULL == g_mainController)
    {
        g_mainController = new MainController();
    }
    return g_mainController;
}

void MainController::update(float dt)
{
    sGameActionManager->processAction();
}

/**
 * 发送操作指令到currentStage,主要用于游戏的逻辑
 */
void MainController::sendAction(GameAction *pAction)
{
    if (NULL == pAction)
	{
		CCLOG("MainController::sendAction error action is null");
		return;
	}
    
    sGameActionManager->addAction(pAction);
}

/**
 * 开始游戏
 */
void MainController::startGame()
{
//    ScreenUtil::init();
    // 477e67d5 ba0b4591 c305d723 ec9ffe04
    // 设置plist纹理解析秘钥
//    ZipUtils::setPvrEncryptionKey(0x477e67d5, 0xba0b4591, 0xc305d723, 0xec9ffe04);
    
    auto engine = LuaEngine::getInstance();
    LuaStack* stack = engine->getLuaStack();
    
    // 注册pbc
    luaopen_protobuf_c(stack->getLuaState());
    // 注册snpshot
//    luaopen_snapshot(stack->getLuaState());
    
    // copy proto文件到可写路径
//    LuaManager::copyProroFile();
    // 注册C++方法到lua
//    LuaManager::setCPPFuncToLua();
    register_usertolua_package();
    
    // 执行lua的入口文件
    FileUtils::getInstance()->addSearchPath("src");
    FileUtils::getInstance()->addSearchPath("res");
    
    // 处理搜索文件夹，将可写路径写入路径簇里
    handleSearchFolder();
    
    engine->executeScriptFile("main.lua");
}

/**
 * 处理搜索的文件夹
 */
void MainController::handleSearchFolder()
{
    string writePath = FileUtils::getInstance()->getWritablePath();
    
    std::vector<string> searchPaths = FileUtils::getInstance()->getSearchPaths();
    
    std::vector<string>::iterator it = searchPaths.begin();
    searchPaths.insert(it, writePath);
    
    FileUtils::getInstance()->setSearchPaths(searchPaths);
}

/**
 * 注册用户自己的类到lua的接口
 */
void MainController::register_usertolua_package()
{
    auto engine = LuaEngine::getInstance();
    lua_State* state = engine->getLuaStack()->getLuaState();
    
    lua_getglobal(state, "_G");
//    register_all_custom_api(state);
    lua_pop(state, 1);
    
    // 注册动画工具接口
//    register_lua_animation_module();
    
    // 注册设备工具接口
//    register_lua_device_module();
}


