/*
 * GameActionManager.cpp
 *
 *  Created on: 2014年5月12日
 *      Author: leon
 */

#include "GameActionManager.h"
#include "ActionConstants.h"
//#include "LuaManager.h"

DECLARE_SINGLETON_MEMBER(GameActionManager);

GameActionManager::GameActionManager()
{
	// TODO Auto-generated constructor stub
    
}

GameActionManager::~GameActionManager()
{
	// TODO Auto-generated destructor stub
}

/**
 * 加入action到bolockQueue
 */
void GameActionManager::addAction(GameAction *action)
{
	m_actionQueue.push(action);
}

/**
 *	取出待处理的action
 */
GameAction* GameActionManager::getAction()
{
	return m_actionQueue.pop();
}

/**
 *	process the action by main loop with the acitonqueue
 */
void GameActionManager::processAction()
{
    auto action = getAction();
    if (action == NULL)
    {
        return;
    }
	int actionType = action->m_actionID;
    
    switch (actionType)
	{
            // 处理网络传输数据
        case ActionType::NETWORK:
        {

            break;
        }
            
        default:
            break;
    }
    
    CC_SAFE_DELETE(action);
}
