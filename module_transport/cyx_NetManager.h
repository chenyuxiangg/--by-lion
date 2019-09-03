#pragma once
#ifndef CYX_NETMANAGER_H
#define CYX_NETMANAGER_H
#include <QTcpSocket>
#include "cyx_DataBuffer.h"

namespace cyx {
#pragma pack(push,1)  //����1�ֽڶ��뷽ʽ
	typedef struct {
		int m_ipacketlen;
	}Header;

	typedef struct {
		Header m_header;
		QByteArray m_pbody;
	}Packet;
#pragma pack(pop)

	class cyx_NetManager{
	public:
		cyx_NetManager();
		~cyx_NetManager();

		void DoPacket(QByteArray data,int len);
		void UnPacket(QByteArray data,int len);
		virtual void VRecv(QByteArray data);

	public:
		QTcpSocket* m_ptcpsocket;			//ͨ���׽���
		cyx::cyx_DataBuffer m_buffer;		//�׽��ֶ�Ӧ�Ļ�����
		int m_bodylen;
		bool m_bfirst;
	};
}

#endif