/*
 * AutoLock.cpp
 *
 *  Created on: 2012-12-11
 *      Author: yonglei
 */

#include "AutoLock.h"

ThreadMutex::ThreadMutex()
{
	// 初始化一个互斥锁
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	m_pMutex = CreateMutex(NULL, FALSE, NULL);
#else
	m_pMutex = new pthread_mutex_t;
	pthread_mutex_init(m_pMutex, NULL);
#endif
}

ThreadMutex::~ThreadMutex()
{
	// 销毁一个互斥锁
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)	
	CloseHandle(m_pMutex);
#else
	pthread_mutex_destroy(m_pMutex);

	if (m_pMutex)
	{
		delete m_pMutex;
	    m_pMutex = NULL;
	}
#endif
}

/**
 * 上锁
 */
void ThreadMutex::lock()
{
    if (NULL == m_pMutex)
    {
        return;
    }
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	// @param INFINITE 表示一直阻塞
	WaitForSingleObject(m_pMutex, INFINITE);
#else
    pthread_mutex_lock(m_pMutex);
#endif
}

/**
 * 解锁
 */
void ThreadMutex::unlock()
{
    if (NULL == m_pMutex)
    {
        return;
    }
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	ReleaseMutex(m_pMutex);
#else
    pthread_mutex_unlock(m_pMutex);
#endif
}

/**
 * 封装成自动锁
 */
AutoLock::AutoLock(ThreadMutex *threadMutex)
{
	 m_threadMutex = threadMutex;
	 m_threadMutex->lock();
}

/**
 * 析构自动解锁
 */
AutoLock::~AutoLock()
{
	m_threadMutex->unlock();
}

