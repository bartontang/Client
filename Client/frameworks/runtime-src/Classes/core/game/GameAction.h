/*[class name]	GameAction
 *[function]    游戏指令
 *              主要用于在UI界面获得用户操作指令的时候封装好消息，
 *              交给Maincontroller分发处理
 *
 *[author]		leiyong
 *[date]		2012-11-29
 */
/*******************************************************/


#ifndef FantasyTown_GameAction_h
#define FantasyTown_GameAction_h

#include "cocos2d.h"
#include <vector>

using namespace std;
using namespace cocos2d;


class GameAction
{
    
public:
    // action附带的数据部分用于进行数据传递
    int m_actionID;
	int m_int0, m_int1, m_int2, m_int3, m_int4;
	float m_float0, m_float1;
	string m_string0;
    string m_string1;
    bool m_bool0, m_bool1;

    // 用于传递任何指针类型
    char* m_data;
	void* m_data1;

    // the next pointer
	GameAction* m_next;

public:
    GameAction(int actionID);
    virtual ~GameAction();
};

#endif
