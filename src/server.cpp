#include <iostream>
#include "../include/MyServer.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: "
				  << argv[0]
				  << " <Server Port ID>"
				  << std::endl;
		exit(-1);
	}
	MyServer myserver;
	myserver.MyGetAddrInfo();
	myserver.MyListenFd();
	myserver.MyServerRW();

	return 0;
}
