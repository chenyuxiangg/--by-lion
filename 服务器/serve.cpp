#include "cyx_net.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "输入参数有误！" << endl;
		system("pause");
		return 0;
	}

	char* port = argv[1];

	Cserve serve;
	struct addrinfo* plist = NULL;
	struct addrinfo* ptr = NULL;
	struct addrinfo hints;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	int ret = getaddrinfo(NULL, port, &hints, &plist);
	if (ret != 0)
	{
		cout << "服务器：获取地址信息有误！" << endl;
		closesocket(serve.GetSocket(1));
		WSACleanup();
		system("pause");
		return 0;
	}

	serve.Bind(serve.GetSocket(1), plist->ai_addr, plist->ai_addrlen);
	for (ptr = plist; ptr; ptr = ptr->ai_next)
	{
		if (serve.Listen(serve.GetSocket(1)) == 0)
			break;
		continue;
	}
	freeaddrinfo(plist);
	closesocket(serve.GetSocket(0));

	if (!ptr)
	{
		cout << "服务器：没有客户机存在！" << endl;
		closesocket(serve.GetSocket(1));
		system("pause");
		return 0;
	}

	serve.Accept(serve.GetSocket(1));

	//若连接成功，则向已连接客户机一条问候
	int recvlen = 0;
	int sendlen = 0;
	char recvbuf[1024];
	memset(recvbuf, 0, sizeof(recvbuf));
	char sendbuf[1024] = "有朋自远方来，不亦说乎！";
	send(serve.GetSocket(1), sendbuf, strlen(sendbuf), 0);
	memset(sendbuf, 0, sizeof(sendbuf));

	do
	{
		recvlen = recv(serve.GetSocket(1), recvbuf, sizeof(recvbuf), 0);
		strcpy_s(sendbuf, recvlen + 1, recvbuf);
		cout << recvbuf << endl;
		sendlen = send(serve.GetSocket(1), sendbuf, recvlen, 0);
		memset(sendbuf, 0, sizeof(sendbuf));
		memset(recvbuf, 0, sizeof(recvbuf));
	} while (recvlen);

	shutdown(serve.GetSocket(1), SD_SEND);
	closesocket(serve.GetSocket(1));
	system("pause");
	return 0;

}