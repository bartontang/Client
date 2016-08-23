//
//  NetWorker.h
//  Client
//
//  Created by barton on 16/8/23.
//
//

#ifndef NetWorker_h
#define NetWorker_h

#include <stdio.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include "cocos2d.h"

// 最大的数据缓冲区
#define MAX_BUFFER_SIZE		1024*1024
// 包头大小
#define PACKAGE_HEDER_LENGTH    2

// 收到字节的个数
static int m_recvCount;
// 接收缓冲区
static char *receiveBuff;
// 缓冲区字节数
static int m_haveCount;

class NetWorker {
public:
    NetWorker();
    virtual ~NetWorker();
    
    bool init();
    
    bool connect(const char* ip, int port);
    
    bool disconnect();
    
    
    
private:

    // 发送线程执行的回调函数
    static void* sendThread(void *manager);
    
    // 接收线程的回调函数
    static void* receiveThread(void *manager);
    
    
private:
    int m_socketfd;

    
    // 接收数据线程
    pthread_t m_receiveThreadId;
    // 发送数据线程
    pthread_t m_sendThreadId;
    
};

#endif /* NetWorker_hpp */
