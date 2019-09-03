#include "cyx_log.h"
#include <iostream>

void run(const char* msg);
void ccc(const char* msg);

int main(int argc, char* argv[]) {
	run("hello,CLog!");
	ccc("hello,³ÂÓîÏè!");
	
	system("pause");
	return 0;
}

void run(const char* msg) {

	CLOG_REGISTER;
	cyx::CLog* mylog = cyx::CLog::GetInstance("./test.txt");
	mylog->OutputError(msg);
	std::cout << "successful!" << std::endl;
}

void ccc(const char* msg) {
	CLOG_REGISTER;
	cyx::CLog* mylog = cyx::CLog::GetInstance("./test.txt");
	mylog->OutputError(msg);
}