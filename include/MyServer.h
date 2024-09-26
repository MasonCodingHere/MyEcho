#ifndef _MY_SERVER_H_
#define _MY_SERVER_H_

#include <netdb.h>
#include <string>

const int MAXLINE = 256;

class MyServer
{
public:
	MyServer() = default;
	~MyServer() = default;
	MyServer(const std::string serverPort):ms_serverPort(serverPort) {}
	void MyGetAddrInfo();
	int MyListenFd();
	void MyServerRW();
private:
	const std::string ms_serverPort = "2020";
	struct addrinfo *ms_listp;
	int ms_listenfd;
	const int ms_optval = 1;
	int ms_connfd;
	char ms_buf[MAXLINE];
};


#endif
