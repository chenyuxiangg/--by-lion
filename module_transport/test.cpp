#include "test.h"
#include <QDataStream>
#include <QFile>
#include <iostream>

test::test(QObject* parent) :QObject(parent) {
	//timer = new QTimer;
	//timer->setSingleShot(true);
	//server = new Server(12345);
	//connect(timer, SIGNAL(timeout()), this, SLOT(run()));
	//timer->start(1000);

	QString inputpath = "D:/testggg/CountryCreate/Resources/output/recv.yuv";
	QString outputpath = "D:/testggg/CountryCreate/Resources/output/" + inputpath.split("/")[5].split(".")[0] + ".avi";
	std::cout << outputpath.toLocal8Bit().data() << std::endl;
}

test::~test() {
	if (timer)
		delete timer;
	if (server)
		delete server;
	if (client)
		delete client;
	timer = nullptr;
	server = nullptr;
	client = nullptr;
}

void test::run() {
	client = new Client(12345);
}