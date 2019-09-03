#include "QtClient.h"
#include <QByteArray>

QtClient::QtClient(QWidget *parent)
	: QWidget(parent)
{
	this->resize(QSize(500,400));
	tcpClient = new QTcpSocket(this);
	gbRecv = new QGroupBox("Recv Window",this);
	gbSend = new QGroupBox("Send Window",this);
	gbnet = new QGroupBox("Net Window",this);

	vnet = new QVBoxLayout;
	vall = new QGridLayout;
	hsend = new QHBoxLayout;
	vrecv = new QVBoxLayout;

	edtIP = new QLineEdit(gbnet);
	edtPort = new QLineEdit(gbnet);
	btnConnct = new QPushButton("connect",gbnet);
	btnSend = new QPushButton("send",gbSend);
	btnClean = new QPushButton("clean",gbnet);
	lbIP = new QLabel("IP",gbnet);
	lbPort = new QLabel("Port", gbnet);
	teRecv = new QTextEdit(gbRecv);
	teSend = new QTextEdit(gbSend);
	cbhex = new QCheckBox("hex",gbnet);
	btnSend->setEnabled(false);
	btnClean->setEnabled(true);
	btnConnct->setEnabled(true);

	vnet->addWidget(lbIP);
	vnet->addWidget(edtIP);
	vnet->addWidget(lbPort);
	vnet->addWidget(edtPort);
	vnet->addWidget(cbhex);
	vnet->addWidget(btnConnct);
	vnet->addWidget(btnClean);
	gbnet->setLayout(vnet);

	vrecv->addWidget(teRecv);
	gbRecv->setLayout(vrecv);

	hsend->addWidget(teSend);
	hsend->addWidget(btnSend);
	gbSend->setLayout(hsend);

	vall->addWidget(gbRecv, 1, 1);
	vall->addWidget(gbnet, 1, 2);
	vall->addWidget(gbSend,2,1);
	this->setLayout(vall);

	tcpClient->abort();//取消原有连接
	connect(tcpClient, SIGNAL(readyRead()), this, SLOT(ReadData()));
	connect(tcpClient, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(ReadError(QAbstractSocket::SocketError)));
	connect(btnConnct, SIGNAL(clicked()), this, SLOT(on_btnConnect_clicked()));
	connect(btnClean, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
	connect(btnSend, SIGNAL(clicked()), this, SLOT(on_btnSend_clicked()));
}

void QtClient::ReadData()
{
	QByteArray buffer = tcpClient->readAll();
	if (!buffer.isEmpty())
	{
		this->teRecv->append(buffer);
	}
}

void QtClient::ReadError(QAbstractSocket::SocketError)
{
	tcpClient->disconnectFromHost();
	this->btnConnct->setText("connect");
	QMessageBox msgbox;
	msgbox.setText(tr("failed to connect server because %1").arg(tcpClient->errorString()));
	msgbox.exec();
}

void QtClient::on_btnConnect_clicked()
{
	if (this->btnConnct->text() == "connect")
	{
		tcpClient->connectToHost(this->edtIP->text(), this->edtPort->text().toInt());
		if (tcpClient->waitForConnected(1000))
		{
			this->btnConnct->setText("close");
			this->btnSend->setEnabled(true);
		}
	}
	else
	{
		tcpClient->disconnectFromHost();
		if (tcpClient->state() == QAbstractSocket::UnconnectedState || tcpClient->waitForDisconnected(1000))
		{
			this->btnConnct->setText("connect");
			this->btnSend->setEnabled(false);
		}
	}
}

void QtClient::on_btnSend_clicked()
{
	QString data = this->teSend->toPlainText();
	if (data != "")
	{
		tcpClient->write(data.toLatin1());
	}
}

void QtClient::on_pushButton_clicked()
{
	this->teRecv->clear();
}

QtClient::~QtClient()
{
	delete tcpClient;

	delete btnConnct;
	delete btnSend;
	delete btnClean;

	delete edtIP;
	delete edtPort;

	delete vnet;
	delete hsend;
	delete vall;
	delete vrecv;

	delete lbIP;
	delete lbPort;

	delete teRecv;
	delete teSend;

	delete cbhex;

	delete gbRecv;
	delete gbSend;
	delete gbnet;
}
