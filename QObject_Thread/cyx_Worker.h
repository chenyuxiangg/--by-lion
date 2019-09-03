#pragma once
#include <QObject>
#include <QMutex>

class cyx_Worker :public QObject {
	Q_OBJECT
public:
	cyx_Worker(QObject* parent = 0);
	~cyx_Worker();
	void Stop();

public slots:
	virtual void slot_doWork();

private:
	bool m_bstop;
	QMutex m_mutex;
};