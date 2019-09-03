#include "cyx_NetManager.h"
#include <iostream>
using namespace cyx;

cyx_NetManager::cyx_NetManager():m_bfirst(true),m_bodylen(0) {

}

cyx_NetManager::~cyx_NetManager() {
	if (m_ptcpsocket) {
		delete m_ptcpsocket;
		m_ptcpsocket = nullptr;
	}
}

void cyx_NetManager::DoPacket(QByteArray data,int len) {
	QString str = QString::number(len);
	data.insert(0, str);
	int llen = str.size();
	QString slen = QString::number(llen);
	if (slen.size() < 2) {
		slen = "0" + slen;
		data.insert(0, slen);
	}
	else {
		data.insert(0, slen);
	}

	if (m_ptcpsocket) {
		m_ptcpsocket->write(data);
	}
	else {
		return;
	}
}

void cyx_NetManager::UnPacket(QByteArray data, int len) {
	m_buffer.AddMsg(data, len);				//将消息放入缓冲区
	int totlelen = m_buffer.GetDataSize();
	while (totlelen > 0) {

		if (m_bfirst) {
			int llen = QString(m_buffer.GetBuffer().left(2)).toInt();
			m_buffer.GetBuffer().remove(0, 2);
			m_bodylen = QString(m_buffer.GetBuffer().left(llen)).toInt();
			m_buffer.GetBuffer().remove(0, llen);
			m_bfirst = false;
		}
		
		if (totlelen < m_bodylen)
			break;

		//如果数据足够多
		QByteArray recvdata = m_buffer.GetBuffer().left(m_bodylen);
		VRecv(recvdata);
		m_bfirst = true;
		m_buffer.GetBuffer().remove(0, m_bodylen);
		totlelen -= m_bodylen;
	}
}

void cyx_NetManager::VRecv(QByteArray data) {

}