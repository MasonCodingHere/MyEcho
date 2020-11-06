/*************************************************************************
	> File Name: server.cpp
	> Author: GeekPanda
	> Mail: xgx127@126.com 
	> Created Time: 2020年11月06日 星期五 13时00分33秒
 ************************************************************************/

#include <iostream>
#include "../include/MyServer.h"

int main(int argc, char **argv)
{
	MyServer myserver;
	myserver.MyGetAddrInfo();
	myserver.MyListenFd();
	myserver.MyServerRW();

	return 0;
}
