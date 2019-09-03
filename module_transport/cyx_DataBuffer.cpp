#include "cyx_DataBuffer.h"
#include <memory>
#include <QException>
using namespace cyx;

cyx_DataBuffer::cyx_DataBuffer(){
	
}

cyx_DataBuffer::~cyx_DataBuffer() {
}

QByteArray& cyx_DataBuffer::GetBuffer() {
	return m_pbuffer;
}

int cyx_DataBuffer::GetDataSize() {
	return m_pbuffer.size();
}

bool cyx_DataBuffer::AddMsg(QByteArray msg, int len) {
	try {
		m_pbuffer.append(msg);
	}
	catch (QException e) {
		return false;
	}
	return true;
}

void cyx_DataBuffer::Poll(int pos, int len) {
	m_pbuffer.remove(pos, len);
}