/*************************************************************************
	> File Name: ClientFD.h
	> Author: GeekPanda
	> Mail: xgx127@126.com 
	> Created Time: 2020年11月04日 星期三 14时46分05秒
 ************************************************************************/
#include <netdb.h>

const int MAXLINE = 256;

class ClientFD 
{
public:
	ClientFD() = default;
	ClientFD(const std::string hostIP, const std::string portID):hostname(hostIP),port(portID) {}
	~ClientFD() = default;
	int MyGetAddrInfo();
	int MyConnect();
	int MyClientWrite();

private:
	std::string hostname;
	std::string port;
	struct addrinfo *listp;
	int clientfd;
	char buf[MAXLINE];
};
