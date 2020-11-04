/*************************************************************************
	> File Name: ClientFD.cpp
	> Author: GeekPanda
	> Mail: xgx127@126.com 
	> Created Time: 2020年11月04日 星期三 15时29分22秒
 ************************************************************************/

#include <iostream>
#include <string.h>
#include <unistd.h>
#include "../include/ClientFD.h"

int ClientFD::MyGetAddrInfo(){
	struct addrinfo hints;

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_NUMERICSERV;
	hints.ai_flags |= AI_ADDRCONFIG;

	getaddrinfo(hostname.c_str(), port.c_str(), &hints, &listp);

	return 0;
}

int ClientFD::MyConnect(){
	struct addrinfo *p;
	for(p = listp; p; p = p->ai_next)
	{
		clientfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
		if (clientfd < 0)
			continue;

		if (connect(clientfd, p->ai_addr, p->ai_addrlen) != -1)
			break;
		close(clientfd);
	}
	
	freeaddrinfo(listp);
	if(!p)
		return -1;
	else
		return 0;
}

int ClientFD::MyClientWrite(){
	while (fgets(buf, MAXLINE, stdin) != NULL)
	{
		read(clientfd, &buf, MAXLINE);
	}
	return 0;	
}
