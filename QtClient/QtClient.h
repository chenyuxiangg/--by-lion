#pragma once

#include <QtWidgets/QMainWindow>
#include <qtcpsocket.h>
#include <qhostaddress.h>
#include <qmessagebox.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QComboBox>
#include <QGroupBox>
#include <QCheckBox>

class QtClient : public QWidget
{
	Q_OBJECT

public:
	QtClient(QWidget *parent = Q_NULLPTR);
	~QtClient();

private:
	QTcpSocket* tcpClient;

	QPushButton* btnConnct;
	QPushButton* btnSend;
	QPushButton* btnClean;

	QLineEdit* edtIP;
	QLineEdit* edtPort;

	QVBoxLayout* vnet;
	QHBoxLayout* hsend;
	QGridLayout* vall;
	QVBoxLayout* vrecv;

	QLabel* lbIP;
	QLabel* lbPort;

	QTextEdit* teRecv;
	QTextEdit* teSend;

	QCheckBox* cbhex;

	QGroupBox* gbRecv;
	QGroupBox* gbSend;
	QGroupBox* gbnet;

private slots:
	//¿Í»§¿î²Ûº¯Êý
	void ReadData();
	void ReadError(QAbstractSocket::SocketError);
	void on_btnConnect_clicked();
	void on_btnSend_clicked();
	void on_pushButton_clicked();
};
