#include "cyx_log.h"
#include <cstring>

cyx::CLog* cyx::CLog::m_instance = NULL;
const char* cyx::CLog::m_funcn_name = NULL;

cyx::CLog::CLog(const char* path):m_file_name(path) {

}

cyx::CLog* cyx::CLog::GetInstance(const char* path) {
	if (path == "")
		return NULL;
	if (m_instance == NULL)
		m_instance = new cyx::CLog(path);
	return m_instance;
}

int cyx::CLog::OutputError(const char* msg) {
	fopen_s(&m_file, m_file_name, "a+");
	int func_name_length = strlen(m_funcn_name);
	int msg_length = strlen(msg);
	int new_msg_length = func_name_length + msg_length + 5;
	char* buf = new char[new_msg_length];
	sprintf_s(buf, new_msg_length, "%s:%s\n", m_funcn_name, msg);
	int curcount = fprintf_s(m_file, buf);
	delete[] buf;
	buf = NULL;
	fclose(m_file);
	return curcount;
}

cyx::CLog::~CLog() {
	if (m_instance)
		delete m_instance;
	m_instance = NULL;
}