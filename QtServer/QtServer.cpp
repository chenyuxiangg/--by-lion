#include "QtServer.h"
#include <QByteArray>

QtServer::QtServer(QWidget *parent)
	: QWidget(parent)
{
	//网络设置
	gbnet = new QGroupBox("net window",this);
	lbIP = new QLabel("IP", gbnet);
	edtIP = new QLineEdit(gbnet);
	lbPort = new QLabel("Port", gbnet);
	edtPort = new QLineEdit(gbnet);
	btnConnect = new QPushButton("listen", gbnet);
	ckb = new QCheckBox("hex", gbnet);
	btnClear = new QPushButton("clear", gbnet);
	cblink = new QComboBox(gbnet);
	vnet = new QVBoxLayout;
	vnet->addWidget(lbIP);
	vnet->addWidget(edtIP);
	vnet->addWidget(lbPort);
	vnet->addWidget(edtPort);
	vnet->addWidget(btnConnect);
	vnet->addWidget(btnClear);
	vnet->addWidget(ckb);
	vnet->addWidget(cblink);
	gbnet->setLayout(vnet);

	//接收窗口
	gbrecv = new QGroupBox("recv window", this);
	teRecv = new QTextEdit(gbrecv);
	teRecv->setStyleSheet("QTextEdit{background:lightGray}");
	teRecv->setEnabled(false);
	vrecv = new QVBoxLayout;
	vrecv->addWidget(teRecv);
	gbrecv->setLayout(vrecv);

	//发送窗口
	gbsend = new QGroupBox("send window", this);
	teSend = new QTextEdit(gbsend);
	btnSend = new QPushButton("Send", gbsend);
	hsend = new QHBoxLayout;
	hsend->addWidget(teSend);
	hsend->addWidget(btnSend);
	gbsend->setLayout(hsend);

	//总窗口
	all = new QGridLayout(this);
	all->addWidget(gbrecv, 1, 1);
	all->addWidget(gbnet, 1, 2);
	all->addWidget(gbsend, 2, 1);
	this->setLayout(all);

	//Socket
	tcpServer = new QTcpServer(this);
	this->edtIP->setText(QNetworkInterface().allAddresses().at(1).toString());
	this->btnConnect->setEnabled(true);
	this->btnSend->setEnabled(false);

	//信号与槽连接
	connect(btnConnect, SIGNAL(clicked()), this, SLOT(on_btnConnect_clicked()));
	connect(btnClear, SIGNAL(clicked()), this, SLOT(on_btnClear_clicked()));
	connect(btnSend, SIGNAL(clicked()), this, SLOT(on_btnSend_clicked()));
	connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newConnectionSlot()));
}

QtServer::~QtServer()
{
	delete tcpServer;
	delete btnConnect;
	delete btnClear;
	delete btnSend;

	delete lbIP;
	delete lbPort;

	delete cblink;

	delete ckb;

	delete edtIP;
	delete edtPort;

	delete teRecv;
	delete teSend;

	delete all;
	delete hsend;
	delete vnet;
	delete vrecv;

	delete gbsend;
	delete gbnet;
	delete gbrecv;
}

void QtServer::on_btnClear_clicked()
{
	this->teRecv->clear();
}

void QtServer::on_btnConnect_clicked()
{
	if (this->btnConnect->text() == "listen")
	{
		bool ok = tcpServer->listen(QHostAddress::Any, this->edtPort->text().toInt());
		if (ok)
		{
			this->btnConnect->setText("close");
			this->btnSend->setEnabled(true);
		}
	}
	else
	{
		//错了，不应该在此处处理，需要修改。
		if (tcpClient.length() != 0)
		{
			tcpClient[cblink->currentIndex()]->disconnectFromHost();
		}
		tcpServer->close();//停止监听
		this->btnConnect->setText("listen");
		this->btnSend->setEnabled(false);
	}
}

void QtServer::on_btnSend_clicked()
{
	QString data = this->teSend->toPlainText();
	if (data == "")
		return;
	if (this->cblink->currentIndex() == 0)
	{
		for (int i = 0; i < tcpClient.length(); ++i)
		{
			tcpClient[i]->write(data.toLatin1());
		}
	}
	else
	{
		QString clientIP = this->cblink->currentText().split(":")[0];
		int clientPort = this->cblink->currentText().split(":")[1].toInt();
		for (int i = 0; i < tcpClient.length(); ++i)
		{
			if (tcpClient[i]->peerAddress().toString().split("::ffff:")[1] == clientIP\
				&& tcpClient[i]->peerPort() == clientPort)
			{
				tcpClient[i]->write(data.toLatin1());
				return;
			}
		}
	}
}

void QtServer::disConnectedSlot()
{
	for (int i = 0; i < tcpClient.length(); ++i)
	{
		if (tcpClient[i]->state() == QAbstractSocket::UnconnectedState)
		{
			this->cblink->removeItem(this->cblink->findText(tr("%1:%2").arg(tcpClient[i]->peerAddress().toString().split("::ffff:")[1])\
				.arg(tcpClient[i]->peerPort())));
			tcpClient[i]->destroyed();
			tcpClient.removeAt(i);
		}
	}
}

void QtServer::newConnectionSlot()
{
	curClient = tcpServer->nextPendingConnection();
	tcpClient.append(curClient);
	this->cblink->addItem(tr("%1:%2").arg(curClient->peerAddress().toString().split("::ffff:")[1]).arg(curClient->peerPort()));
	connect(curClient, SIGNAL(readyRead()), this, SLOT(ReadData()));
	connect(curClient, SIGNAL(disconnected()), this, SLOT(disConnectedSlot()));
}

void QtServer::ReadData()
{
	for (int i = 0; i < tcpClient.length(); ++i)
	{
		QByteArray buffer = tcpClient[i]->readAll();
		if(buffer.isEmpty())
			continue;
		static QString IP_Port, IP_Port_Pre;
		IP_Port = tr("[%1:%2]:").arg(tcpClient[i]->peerAddress().toString().split("::ffff:")[1]).arg(tcpClient[i]->peerPort());

		if (IP_Port != IP_Port_Pre)
			this->teRecv->append(IP_Port);
		this->teRecv->append(buffer);
		IP_Port_Pre = IP_Port;
	}
}