#include "cyx_Client.h"
#include <QHostAddress>
#include <iostream>
#include <QFile>
#include <QDateTime>

Client::Client(int port,QObject* parent):QObject(parent),m_filename(){
	m_ptcpsocket = new QTcpSocket;
	connect(m_ptcpsocket, SIGNAL(readyRead()), this, SLOT(slot_Read()));
	m_ptcpsocket->connectToHost(QHostAddress::LocalHost, port);
}

Client::~Client() {

}

void Client::slot_Read() {
	while (m_ptcpsocket->bytesAvailable()) {
		int recvlen = m_ptcpsocket->bytesAvailable();
		QByteArray buf;
		buf = m_ptcpsocket->readAll();
		UnPacket(buf, recvlen);
	}
}

void Client::SetFileName(const QString& name) {
	m_filename = name;
}

void Client::VRecv(QByteArray data) {
	qint64 currenttime = QDateTime::currentMSecsSinceEpoch();
	QString path = "./Resources/output/" + QString::number(currenttime) + ".yuv";
	SetFileName(path);

	QFile recvfile(m_filename);
	if (recvfile.open(QIODevice::WriteOnly | QIODevice::Append)) {
		recvfile.write(data);
		recvfile.close();
	}
	std::cout << "´«ÊäÍê³É" << std::endl;
}