#ifndef _MY_CLIENT_H_
#define _MY_CLIENT_H_

#include <netdb.h>

const int MAXLINE = 256;

class MyClient
{
public:
	MyClient() = default;
	~MyClient() = default;
	MyClient(const std::string serverIP, const std::string serverPort):mc_serverIP(serverIP), mc_serverPort(serverPort) {}
	void MyGetAddrInfo();
	int GetClientFd();
	void ClientRW(); 

private:
	std::string mc_serverIP = "127.0.0.1";
	std::string mc_serverPort = "2020";
	struct addrinfo *mc_listp;
	int mc_clientfd;
	char mc_buf[MAXLINE];
};

#endif
