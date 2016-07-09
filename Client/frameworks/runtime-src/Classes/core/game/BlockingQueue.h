/*
 * BlockingQueue.h
 *	blcoking队列主要用于网络,响应请求处理
 *  Created on: 2012-12-11
 *      Author: yonglei
 */

#pragma once

#ifndef BLOCKINGQUEUE_H_
#define BLOCKINGQUEUE_H_

#include "AutoLock.h"

template <class T> class BlockingQueue
{
public:
	BlockingQueue()
	{
		first = NULL;
		last = NULL;
	}

	virtual ~BlockingQueue()
	{

	}

	// 是否为空队列
	bool isEmpty()
	{
		bool ret;
		AutoLock lock(&m_threadMutex);
		ret = (first == NULL);

		return ret;
	}

	// 入队
	void push(T * t)
	{
		t->m_next = NULL;
		AutoLock lock(&m_threadMutex);

		if (first)
		{
			last->m_next = t;
		}
		else
		{
			first = t;
		}

		last = t;
	}

	// 出队
	T* pop()
	{
		T * ret;
		AutoLock lock(&m_threadMutex);

		if (first)
		{
			ret = first;
			first = first->m_next;
			if (!first)
			{
				last = NULL;
			}
		}
		else
		{
			ret = NULL;
		}

		return ret;
	}

private:
	ThreadMutex m_threadMutex;	// 互斥锁
	T *first;					// 队列头
	T *last;					// 队列尾

};

#endif /* BLOCKINGQUEUE_H_ */
