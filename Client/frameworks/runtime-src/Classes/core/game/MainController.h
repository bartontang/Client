//
//  MainController.h
//  cocos2d_libs
//
//  Created by barton on 14/12/1.
//
//

#ifndef __cocos2d_libs__MainController__
#define __cocos2d_libs__MainController__

#include <iostream>
#include "cocos2d.h"
#include "GameAction.h"

using namespace cocos2d;

class MainController : public cocos2d::Ref
{
public:
    MainController();
    virtual ~MainController();
    
    static MainController* getInstance();
    
    // 开始游戏
    void startGame();
    
    // Schedule callback function
	virtual void update(float dt);
    
    // 发送操作指令到currentStage,主要用于游戏的逻辑
    void sendAction(GameAction *pAction);
    
    // 处理搜索的文件夹
    void handleSearchFolder();
    
    // 注册用户自己的类到lua的接口
    void register_usertolua_package();
};

#endif /* defined(__cocos2d_libs__MainController__) */
