#pragma once
#ifndef CYX_DATA_BUFFER_H
#define CYX_DATA_BUFFER_H

#include <QByteArray>

namespace cyx {
#define DEFAULT_SIZE 1024
	class cyx_DataBuffer {
	private:
		QByteArray m_pbuffer;

	public:
		cyx_DataBuffer();
		~cyx_DataBuffer();
		int GetDataSize();
		QByteArray& GetBuffer();
		bool AddMsg(QByteArray msg,int len);
		void Poll(int pos, int len);
	};
}

#endif