#include "Controller.h"
#include <iostream>
using namespace std;

Controller::Controller(QObject* parent /* = 0 */) :QObject(parent) {
	m_worker = new cyx_Worker;
	timer = new QTimer;
	m_worker->moveToThread(&m_workthread);
	connect(timer, SIGNAL(timeout()), this, SIGNAL(sig_stop()));
	connect(&m_workthread, SIGNAL(finished()), m_worker, SLOT(deleteLater()));
	connect(this, SIGNAL(sig_doWork()), m_worker, SLOT(slot_doWork()));
	connect(this, SIGNAL(sig_stop()), this, SLOT(slot_stop()));
}

Controller::~Controller() {
	m_workthread.quit();
	m_workthread.wait();		//m_workthread��û��new����������ʹ��wait�ȴ��߳�ִ�н��������ʹ��new�������deleteLater���߳���ɱ
}

void Controller::Start() {
	timer->setSingleShot(true);
	timer->start(10000);
	m_workthread.start();
	emit sig_doWork();
}

void Controller::slot_stop() {
	m_worker->Stop();
}