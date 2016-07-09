/*
 * Singleton.h
 *
 *  Created on: 2014年5月12日
 *      Author: leon
 */

#ifndef SINGLETON_H_
#define SINGLETON_H_

template <class T> class Singleton
{
public:
	static inline T* instance();
	void destory();

protected:
	Singleton(void){}
	~Singleton(void){}
	static T* mInstance;
};

template <class T> inline T* Singleton<T>::instance()
{
	if (!mInstance)
    {
    	mInstance = new T;
    }

	return mInstance;
}

template <class T> void Singleton<T>::destory()
{
	if (!mInstance)
    {
        return;
    }

	delete mInstance;
	mInstance = 0;
}

#define DECLARE_SINGLETON_MEMBER(_Ty)	\
template <> _Ty* Singleton<_Ty>::mInstance = nullptr;


#endif /* SINGLETON_H_ */
