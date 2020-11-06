/*************************************************************************
	> File Name: MyServer.cpp
	> Author: GeekPanda
	> Mail: xgx127@126.com 
	> Created Time: 2020年11月06日 星期五 10时59分49秒
 ************************************************************************/

#include "../include/MyServer.h"
#include <string.h>
#include <unistd.h>

void MyServer::MyGetAddrInfo()
{
	struct addrinfo hints;

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG;
	hints.ai_flags |= AI_NUMERICSERV;

	getaddrinfo(NULL, ms_serverPort.c_str(), &hints, &ms_listp);
}

int MyServer::MyListenFd()
{
	struct addrinfo *p;
	
	for (p = ms_listp; p; p = p->ai_next)
	{
		ms_listenfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
		if (ms_listenfd < 0)
			continue;
		
		setsockopt(ms_listenfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&ms_optval, sizeof(int));

		if (bind(ms_listenfd, p->ai_addr, p->ai_addrlen) == 0)
			break;

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
