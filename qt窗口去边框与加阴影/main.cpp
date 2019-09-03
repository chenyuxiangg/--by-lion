#include "Ctmp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Ctmp w;
	w.show();
	return a.exec();
}
