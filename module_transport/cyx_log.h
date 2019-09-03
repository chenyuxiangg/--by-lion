#pragma once
#ifndef CYX_LOG_H
#define CYX_LOG_H
#include <stdio.h>

namespace cyx {

#define CLOG_REGISTER cyx::CLog::m_funcn_name = __FUNCTION__;

	class CLog {
	private:
		CLog(const char* path);
		CLog(const CLog&) = delete;
		CLog operator=(const CLog&) = delete;

	public:
		~CLog();
		int OutputError(const char* msg);
		static CLog* GetInstance(const char* path);

	public:
		static const char* m_funcn_name;

	private:
		static CLog* m_instance;
		const char* m_file_name;
		FILE* m_file;
	};
}

#endif