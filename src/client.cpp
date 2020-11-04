/*************************************************************************
	> File Name: client.cpp
	> Author: GeekPanda
	> Mail: xgx127@126.com 
	> Created Time: 2020年11月04日 星期三 16时43分11秒
 ************************************************************************/

#include <iostream>
#include "../include/ClientFD.h"

int main(int argc, char **argv)
{
	if (argc != 3)
		std::cout << "Usage: " 
				  << argv[0]
				  << "<IP addres> <port ID>"
				  << std::endl;
	ClientFD myclient(argv[1], argv[2]);
	myclient.MyGetAddrInfo();
	myclient.MyConnect();
	myclient.MyClientWrite();

	return 0;
}
