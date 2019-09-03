#pragma once

#include <QtWidgets/QMainWindow>
#include <QPushButton>
#include <QTcpServer>
#include <QNetWorkInterface>
#include <QTcpSocket>
#include <QMessageBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>
#include <QGroupBox>

class QtServer : public QWidget
{
	Q_OBJECT

public:
	QtServer(QWidget *parent = Q_NULLPTR);
	~QtServer();

private:
	QTcpServer* tcpServer;
	QList<QTcpSocket*> tcpClient;
	QTcpSocket* curClient;

	QPushButton* btnConnect;
	QPushButton* btnClear;
	QPushButton* btnSend;

	QLabel* lbIP;
	QLabel* lbPort;

	QComboBox* cblink;

	QCheckBox* ckb;

	QLineEdit* edtIP;
	QLineEdit* edtPort;

	QTextEdit* teRecv;
	QTextEdit* teSend;

	QGridLayout* all;
	QHBoxLayout* hsend;
	QVBoxLayout* vnet;
	QVBoxLayout* vrecv;

	QGroupBox* gbsend;
	QGroupBox* gbnet;
	QGroupBox* gbrecv;

	private slots:
	void newConnectionSlot();
	void disConnectedSlot();
	void ReadData();

	void on_btnConnect_clicked();
	void on_btnSend_clicked();
	void on_btnClear_clicked();
};
