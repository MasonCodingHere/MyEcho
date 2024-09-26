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

	if((getaddrinfo(mc_serverIP.c_str(), mc_serverPort.c_str(), &hints, &mc_listp)) == 0)
		std::cout << "转换为套接字地址结构成功" << std::endl;
	else
		std::cout << "转换为套接字地址结构失败" << std::endl;
}

int MyClient::GetClientFd()
{
	struct addrinfo *p;
	for (p = mc_listp; p; p = p->ai_next)
	{
		mc_clientfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
		if (mc_clientfd < 0)
		{
			std::cout << "创建套接字描述符失败" << std::endl;
			continue;
		}
		else
			std::cout << "创建套接字描述符成功" << std::endl;

		if (connect(mc_clientfd, p->ai_addr, p->ai_addrlen) != -1)
		{
			std::cout << "与服务器建立连接成功" << std::endl;
			break;
		}

		else
		{
			std::cout << "与服务器建立连接失败" << std::endl;
			exit(-1);
		}		
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
	while (1)
	{
		bzero(mc_buf, sizeof(mc_buf));
		scanf("%s", mc_buf);
		write(mc_clientfd, mc_buf, sizeof(mc_buf));
		bzero(mc_buf, sizeof(mc_buf));
		read(mc_clientfd, mc_buf, sizeof(mc_buf));
		printf("来自服务器:%s\n", mc_buf);
	}

	close(mc_clientfd);
}
