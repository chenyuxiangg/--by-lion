#include <QtCore/QCoreApplication>
#include "cyx_Server.h"
#include "test.h"
#include <memory>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	test* t = new test();

	return a.exec();
}
