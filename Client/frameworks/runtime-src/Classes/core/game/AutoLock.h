/*
 * AutoLock.h
 *	自定义的一个互斥锁
 *  Created on: 2012-12-11
 *      Author: yonglei
 */

#ifndef AUTOLOCK_H_
#define AUTOLOCK_H_

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include <windows.h>
#else
#include "pthread.h"
#endif

class ThreadMutex
{
public:
	ThreadMutex();
    ~ThreadMutex();

    void lock() ;
    void unlock() ;

private:
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	HANDLE m_pMutex;
#else
    pthread_mutex_t *m_pMutex;
#endif

};

class AutoLock
{
public:
	AutoLock(ThreadMutex *threadMutex);
	virtual ~AutoLock();

private:
	ThreadMutex *m_threadMutex;		// 定义一个互斥锁

};

#endif /* AUTOLOCK_H_ */
