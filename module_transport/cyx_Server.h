#ifndef CYX_SERVER_H
#define CYX_SERVER_H
#include "cyx_NetManager.h"
#include <QTcpServer>
#include <QTcpSocket>

class Server:public QTcpServer, public cyx::cyx_NetManager {
	Q_OBJECT
public:
	Server(int port,QObject* parent = NULL);
	~Server();

	public slots: void slot_newConnection();
};


#endif