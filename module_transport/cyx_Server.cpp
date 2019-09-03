#include "cyx_Server.h"
#include <iostream>
#include <QFile>

Server::Server(int port,QObject* parent):QTcpServer(parent) {
	connect(this, SIGNAL(newConnection()), this, SLOT(slot_newConnection()));
	listen(QHostAddress::Any, port);
}

Server::~Server() {

}

void Server::slot_newConnection() {
	std::cout << "Á´½Ó³É¹¦" << std::endl;
	m_ptcpsocket = this->nextPendingConnection();
	QByteArray data;

	QFile file1("./Resources/raws/ds_480x272.yuv");
	if (file1.open(QIODevice::ReadOnly)) {
		data = file1.readAll();
		DoPacket(data, data.count());
		file1.close();
	}

	QFile file2("./Resources/raws/ds_480x272.yuv");
	if (file2.open(QIODevice::ReadOnly)) {
		data = file2.readAll();
		DoPacket(data, data.count());
		file2.close();
	}
}