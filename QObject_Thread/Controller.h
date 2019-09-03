#pragma once
#include <QThread>
#include <QTimer>
#include "cyx_Worker.h"

class Controller :public QObject {
	Q_OBJECT
public:
	Controller(QObject* parent = 0);
	~Controller();
	void Start();

signals:
	void sig_stop();
	void sig_doWork();

public slots:
	void slot_stop();

private:
	QThread m_workthread;
	QTimer* timer;
	cyx_Worker* m_worker;
};