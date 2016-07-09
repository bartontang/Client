//
//  GameAction.cpp
//  FantasyTown
//
//  Created by yong lei on 12-11-29.
//
//

#include "GameAction.h"

GameAction::GameAction(int actionID)
{
	m_actionID = actionID;
	
	m_int0 = 0;
	m_int1 = 0;
	m_int2 = 0;
	m_int3 = 0;
	m_int4 = 0;

	m_string0 = "";
	m_string1 = "";

	m_next = NULL;
	m_data = NULL;
	m_data1 = NULL;

	m_float0 = 0;
	m_float1 = 0;
	m_bool0 = false;
	m_bool1 = false;
}

GameAction::~GameAction()
{
}
