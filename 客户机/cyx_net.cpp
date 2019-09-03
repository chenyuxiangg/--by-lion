#include "cyx_net.h"
#include <iostream>
using namespace std;

Cserve::Cserve(int af, int type, int protocol)
{
	WSADATA wsadata;
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
	{
		cout << "winsock��ʼ��ʧ�ܣ�" << endl;
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
		cout << "�����׽��ִ���" << endl;
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
		cout << "���ܰ󶨵�ַ��Ϣ���׽���!" << endl;
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
		cout << "��������" << endl;
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
		cout << "�����������ڵȴ����Կͻ���������......" << endl;
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
		cout << "�ͻ������׽��ֳ�ʼ��ʧ�ܣ�" << endl;
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
		cout << "�ͻ����������׽���ʧ�ܣ�" << endl;
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
		cout << "�ͻ�������������ʧ�ܣ�" << endl;
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