#pragma once
#include <QTimer>
#include "cyx_Client.h"
#include "cyx_Server.h"

class test :public QObject{
	Q_OBJECT
public:
	test(QObject* parent = 0);
	~test();

	Server* server;
	Client* client;
	QTimer* timer;

public slots:void run();
};