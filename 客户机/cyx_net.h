#pragma once
#ifndef CYX_NET
#define CYX_NET
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib,"ws2_32.lib")

/*
*考虑是否应该使用静态成员函数？
*考虑Cserve Cclient是否需要继承自同一个父类？
*/

class Cserve {
public:
	Cserve(int af = AF_INET,int type = SOCK_STREAM,int protocol = IPPROTO_TCP);
	~Cserve();

	SOCKET Socket(int af, int type, int protocol);
	int Bind(SOCKET S, const struct sockaddr* name, int namelen);
	int Listen(SOCKET s, int backlog = SOMAXCONN);
	SOCKET Accept(SOCKET s, sockaddr* addr = NULL, int * addrlen = NULL);
	SOCKET GetSocket(int i);

private:
	SOCKET m_socket;
	SOCKET m_listen;
};


class Cclient {
public:
	Cclient(int af = AF_INET,int type = SOCK_STREAM,int protocol = IPPROTO_TCP);
	~Cclient();

	SOCKET Socket(int af, int type, int protocol);
	int Connect(SOCKET s, const struct sockaddr* name, int namelen);
	SOCKET GetSocket();

private:
	SOCKET m_socket;
};

#endif