/*************************************************************************
	> File Name: MyServer.cpp
	> Author: GeekPanda
	> Mail: xgx127@126.com 
	> Created Time: 2020年11月06日 星期五 10时59分49秒
 ************************************************************************/

#include "../include/MyServer.h"
#include <string.h>
#include <unistd.h>
#include <iostream>

void MyServer::MyGetAddrInfo()
{
	struct addrinfo hints;

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG;
	hints.ai_flags |= AI_NUMERICSERV;

	if((getaddrinfo(NULL, ms_serverPort.c_str(), &hints, &ms_listp)) == 0)
		std::cout << "服务端：转换为套接字地址结构成功" << std::endl;
	else
		std::cout << "服务端：转换为套接字地址结构失败" << std::endl;
}

int MyServer::MyListenFd()
{
	struct addrinfo *p;
	
	for (p = ms_listp; p; p = p->ai_next)
	{
		ms_listenfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
		if (ms_listenfd < 0)
		{
			std::cout << "服务端：创建套接字描述符失败" << std::endl;
			continue;
		}
		else
			std::cout << "服务端：创建套接字描述符成功" << std::endl;

		setsockopt(ms_listenfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&ms_optval, sizeof(int));

		if (bind(ms_listenfd, p->ai_addr, p->ai_addrlen) == 0)
		{
			std::cout << "服务端：bind执行成功" << std::endl;
			break;
		}
		else
			std::cout << "服务端：bind执行失败" << std::endl;

		close(ms_listenfd);
	}

	freeaddrinfo(ms_listp);
	if(!p)
		return -1;
	if (listen(ms_listenfd, 1024) < 0)
	{
		close(ms_listenfd);
		return -1;
	}

	return 0;
}

void MyServer::MyServerRW()
{
	socklen_t clientlen;
	struct sockaddr_storage clientaddr;
	char client_hostname[MAXLINE], client_port[MAXLINE];
	
	while(1)
	{
		size_t n;
		clientlen = sizeof(struct sockaddr_storage);
		ms_connfd = accept(ms_listenfd, (sockaddr *)&clientaddr, &clientlen);
		getnameinfo((sockaddr *) &clientaddr, clientlen, client_hostname, MAXLINE, client_port, MAXLINE, 0);
		printf("连接到(%s, %s)\n", client_hostname, client_port);

		while((n = read(ms_connfd, ms_buf, MAXLINE)) > 0)
		{
			printf("服务器收到了 %d 个字节\n", (int)n);
			write(ms_connfd, ms_buf, n);
		}

		close(ms_connfd);
	}
}
