/*
 * GameActionManager.h
 *
 *  Created on: 2014年5月12日
 *      Author: leon
 */

#ifndef GAMEACTIONMANAGER_H_
#define GAMEACTIONMANAGER_H_

#include "GameAction.h"
#include "Singleton.h"
#include "BlockingQueue.h"

class GameActionManager : public Singleton<GameActionManager>
{
public:
	GameActionManager();
	virtual ~GameActionManager();

	void addAction(GameAction *action);
	GameAction* getAction();
    
    void processAction();

private:
	BlockingQueue<GameAction>  m_actionQueue;	// action处理队列 execute in mainLoop
};

#define sGameActionManager GameActionManager::instance()

#endif /* GAMEACTIONMANAGER_H_ */
