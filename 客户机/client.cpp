#include "cyx_net.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	if(argc <= 2)
	{
		cout << "�����������!" << endl;
		system("pause");
		return 0;
	}

	char* name = argv[1];
	char* port = argv[2];

	Cclient client;
	struct addrinfo* plist = NULL;
	struct addrinfo* ptr = NULL;
	struct addrinfo hints;
	memset(&hints,0,sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	int ret = getaddrinfo(name, port, &hints, &plist);
	if (ret != 0)
	{
		cout << "�ͻ�������ȡ��������Ϣʧ�ܣ�" << endl;
		closesocket(client.GetSocket());
		WSACleanup();
		system("pause");
		return 0;
	}

	for (ptr = plist; ptr; ptr = ptr->ai_next)
	{
		if (client.Connect(client.GetSocket(), ptr->ai_addr, ptr->ai_addrlen) == 0)
			break;
		continue;
	}

	freeaddrinfo(plist);

	if (!ptr)
	{
		cout << "�ͻ�����û���ҵ�������������ʧ�ܣ�" << endl;
		closesocket(client.GetSocket());
		return 0;
	}

	//�ӷ�������ȡ��Ϣ
	char recvbuf[1024];
	char sendbuf[1024];
	memset(recvbuf, 0, sizeof(recvbuf));
	memset(sendbuf, 0, sizeof(sendbuf));
	int Length = recv(client.GetSocket(), recvbuf, 1024, 0);
	cout << recvbuf << endl;
	memset(recvbuf, 0, sizeof(recvbuf));

	while (fgets(sendbuf, sizeof(sendbuf), stdin) != NULL)
	{
		int sendlen = send(client.GetSocket(), sendbuf, strlen(sendbuf), 0);
		int recvlen = recv(client.GetSocket(), recvbuf, 1024, 0);
		cout << recvbuf << endl;

		memset(recvbuf, 0, sizeof(recvbuf));
		memset(sendbuf, 0, sizeof(sendbuf));
	}

	//�Ͽ��׽������ӣ������������ݣ������Խ���
	shutdown(client.GetSocket(), SD_SEND);
	closesocket(client.GetSocket());
	system("pause");
	return 0;
}