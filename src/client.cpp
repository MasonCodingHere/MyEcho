/*************************************************************************
	> File Name: client.cpp
	> Author: GeekPanda
	> Mail: xgx127@126.com 
	> Created Time: 2020年11月06日 星期五 10时25分51秒
 ************************************************************************/

#include <iostream>
#include <string>
#include "../include/MyClient.h"

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << "Usage: "
				  << argv[0]
				  << " <Server IP Address> <Server Port ID>"
				  << std::endl;
		exit(-1);
	}
	const std::string serverIP = argv[1];
	const std::string serverPort = argv[2];
	MyClient myclient(serverIP, serverPort);
	myclient.MyGetAddrInfo();
	myclient.GetClientFd();
	myclient.ClientRW();

	return 0;
}
