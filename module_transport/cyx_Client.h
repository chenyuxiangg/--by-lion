#pragma once
#ifndef CYX_CLIENT_H
#define CYX_CLIENT_H

#include "cyx_NetManager.h"
#include <QTcpSocket>

class Client :public QObject,public cyx::cyx_NetManager {
	Q_OBJECT

public:
	Client(int port,QObject* parent = NULL);
	~Client();
	void SetFileName(const QString& name);

	virtual void VRecv(QByteArray data);

	public slots:void slot_Read();

private:
	QString m_filename;
};

#endif