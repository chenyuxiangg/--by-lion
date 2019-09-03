#include "cyx_Worker.h"
#include <QDateTime>
#include <QMutexLocker>
#include <iostream>
using namespace std;

cyx_Worker::cyx_Worker(QObject* parent /* = 0 */) :QObject(parent) {
	m_bstop = false;
}

cyx_Worker::~cyx_Worker(){}

void cyx_Worker::slot_doWork() {
	qint64 currenttime = QDateTime::currentMSecsSinceEpoch();
	int count = 0;
	{
		QMutexLocker locker(&m_mutex);
		m_bstop = false;
	}
	while (!m_bstop) {
		if (QDateTime::currentMSecsSinceEpoch() - currenttime >= 2000) {
			currenttime = QDateTime::currentMSecsSinceEpoch();
			cout << count << endl;
			count++;
		}
	}
}

void cyx_Worker::Stop() {
	cout << "stop!" << endl;
	QMutexLocker locker(&m_mutex);
	m_bstop = true;
}