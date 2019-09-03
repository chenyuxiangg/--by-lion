#include "cyx_net.h"
#include <iostream>
using namespace std;

Cserve::Cserve(int af, int type, int protocol)
{
	WSADATA wsadata;
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
	{
		cout << "winsock初始化失败！" << endl;
		WSACleanup();
		system("pause");
		exit(-1);
	}
	m_socket = Socket(af, type, protocol);
	m_listen = SOCKET_ERROR;
}

SOCKET Cserve::GetSocket(int i)
{
	if (i == 0)
		return m_listen;
	else
		return m_socket;
}

SOCKET Cserve::Socket(int af, int type, int protocol)
{
	SOCKET s = socket(af, type, protocol);
	if (s == INVALID_SOCKET)
	{
		cout << "创建套接字错误" << endl;
		WSACleanup();
		system("pause");
		exit(-1);
	}
	return s;
}

int Cserve::Bind(SOCKET s, const struct sockaddr* name, int namelen)
{
	int ret = bind(s, name, namelen);
	if (ret == SOCKET_ERROR)
	{
		cout << "不能绑定地址信息到套接字!" << endl;
		closesocket(m_socket);
		WSACleanup();
		system("pause");
		exit(-1);
	}
	return ret;
}

int Cserve::Listen(SOCKET s, int backlog)
{
	int ret = listen(s, backlog);
	if (ret == SOCKET_ERROR)
	{
		cout << "监听出错！" << endl;
		closesocket(m_socket);
		WSACleanup();
		system("pause");
		exit(-1);
	}
	return ret;
}

SOCKET Cserve::Accept(SOCKET s, sockaddr* addr, int* addrlen)
{
	while (m_listen == SOCKET_ERROR)
	{
		cout << "服务器：正在等待来自客户机的连接......" << endl;
		m_listen = accept(s, addr, addrlen);
	}
	m_socket = m_listen;
	return m_socket;
}

Cserve::~Cserve()
{
	WSACleanup();
}

Cclient::Cclient(int fa, int type, int protocol)
{
	WSADATA wsadata;
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
	{
		cout << "客户机：套接字初始化失败！" << endl;
		WSACleanup();
		system("pause");
		exit(-1);
	}
	m_socket = Socket(fa, type, protocol);
}

SOCKET Cclient::Socket(int fa, int type, int protocol)
{
	SOCKET s = socket(fa, type, protocol);
	if (s == INVALID_SOCKET)
	{
		cout << "客户机：创建套接字失败！" << endl;
		WSACleanup();
		system("pause");
		exit(-1);
	}
	return s;
}

int Cclient::Connect(SOCKET s, const struct sockaddr* name, int namelen)
{
	int ret = connect(s, name, namelen);
	if (ret == SOCKET_ERROR)
	{
		cout << "客户机：建立连接失败！" << endl;
		closesocket(m_socket);
		WSACleanup();
		system("pause");
		exit(-1);
	}
	return ret;
}

SOCKET Cclient::GetSocket()
{
	return m_socket;
}

Cclient::~Cclient()
{
	WSACleanup();
}