//
//  NetWorker.cpp
//  Client
//
//  Created by barton on 16/8/23.
//
//

#include "NetWorker.h"
#include "SocketUtil.h"

NetWorker::NetWorker()
:m_socketfd(0) {

}

NetWorker::~NetWorker() {

}

bool NetWorker::connect(const char* ip, int port) {
    
    if (m_socketfd <= 0) {
        if (NULL == receiveBuff)
        {
            receiveBuff = new char[MAX_BUFFER_SIZE];
        }
        
        memset(receiveBuff, 0, MAX_BUFFER_SIZE);
        m_socketfd = getSocket(ip, port);
        
        if (m_socketfd > 0) {
            // 创建发送线程
            if (m_sendThreadId == 0) {
                pthread_create(&m_sendThreadId, NULL, sendThread, this);
            }
            
            // 创建接收线程
            if (m_receiveThreadId == 0)
            {
                pthread_create(&m_receiveThreadId, NULL, receiveThread, this);
            }
            
            return true;
        } else {
            this->disconnect();
            return false;
        }
    }

    return true;
}

bool NetWorker::disconnect() {
    if (m_sendThreadId > 0) {
        close(m_socketfd);
        m_socketfd = 0;
        
        // 重置已接数据量
        m_haveCount = 0;
        
        // 重置缓冲区
        memset(receiveBuff, 0, MAX_BUFFER_SIZE);
    }
    return true;
}

// 发送线程执行的回调函数
void* NetWorker::sendThread(void *manager) {
    NetWorker *pThis = (NetWorker*) manager;
    if (NULL == pThis) {
        return NULL;
    }
    
    return NULL;
}

// 接收线程的回调函数
void* NetWorker::receiveThread(void *manager) {
    NetWorker *pThis = (NetWorker*) manager;
    if (NULL == pThis) {
        return NULL;
    }
    
    return NULL;
}
