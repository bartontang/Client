//
//  SocketUtil.h
//  Client
//
//  Created by barton on 16/8/23.
//
//

#ifndef SocketUtil_h
#define SocketUtil_h

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include "Endianness.h"

static uint32_t queryIP(const  char * szIP) {
    uint32_t ip;
    
    // 将字符串地址信息转化成uint 地址信息
    ip = inet_addr(szIP);
    
    if (ip == INADDR_NONE) {
        struct hostent *host = NULL;
        
        host = gethostbyname(szIP);
        if(host != NULL) {
            memcpy(&ip, host->h_addr_list[0], host->h_length);
        } else {
            return INADDR_NONE;
        }
    }
    return ip;
}

static int getSocket(const char *ip, int port) {
    
    // 创建socket获取套接字
    int sckLocal = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP) ;
    // 超时次数
    int timeOutNum = 0;
    
    // 连接地址
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr= queryIP(ip);
    
    if (addr.sin_addr.s_addr == INADDR_NONE) {
        return 0;
    }
    
    // 设置超时时间
    int iTimeOut = 5 * 1000;
    
    // 发送超时设定
    setsockopt(sckLocal, SOL_SOCKET, SO_RCVTIMEO, (void*)&iTimeOut, sizeof(iTimeOut));
    
    int flag = 0;
    // 连接server
    while ((flag = connect(sckLocal, (struct sockaddr*)&addr, sizeof(addr))) == -1) {
        timeOutNum++;
        if (timeOutNum > 6) {
            return 0;
        }
        
        printf("connect failed! reconnect ip = %s, port = %d, count = %d \n", ip, port, timeOutNum);
        
        sleep(timeOutNum);
    }
    
    return sckLocal;
}



#endif /* SocketUtil_h */
