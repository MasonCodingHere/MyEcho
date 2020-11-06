/*************************************************************************
	> File Name: MyClient.cpp
	> Author: GeekPanda
	> Mail: xgx127@126.com 
	> Created Time: 2020年11月06日 星期五 09时47分22秒
 ************************************************************************/

#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include "../include/MyClient.h"

void MyClient::MyGetAddrInfo()
{
	struct addrinfo hints;

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_NUMERICSERV;
	hints.ai_flags |= AI_ADDRCONFIG;

	getaddrinfo(mc_serverIP.c_str(), mc_serverPort.c_str(), &hints, &mc_listp);
}

int MyClient::GetClientFd()
{
	struct addrinfo *p;
	for (p = mc_listp; p; p = p->ai_next)
	{
		mc_clientfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
		if (mc_clientfd < 0)
			continue;

		if (connect(mc_clientfd, p->ai_addr, p->ai_addrlen) != -1)
			break;

		close(mc_clientfd);
	}

	freeaddrinfo(mc_listp);
	if (!p)
		return -1;
	else
		return 0;
}

void MyClient::ClientRW()
{
	while (fgets(mc_buf, MAXLINE, stdin) != NULL)
	{
		write(mc_clientfd, mc_buf, strlen(mc_buf));
		read(mc_clientfd, mc_buf, MAXLINE);
		fputs(mc_buf, stdout);
	}

	close(mc_clientfd);
}
