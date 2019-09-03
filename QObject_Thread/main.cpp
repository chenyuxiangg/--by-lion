#include <QtCore/QCoreApplication>
#include "Controller.h"

/*
使用QObject创建线程总结：
1、随便写一个类继承自QObject
2、定义一个工作函数，将耗时的过程写在里边
3、写一个线程管理类，该类至少包含一个QThread和一个你自定义的工作类成员变量
4、在管理类的构造函数中将自定义工作类的对象使用moveToThread()函数移动到QThread对象中，此时该对象的所有东西都是线程对象的了
5、没必要重写run函数，只要在控制类中自定义一个工作信号，并将该工作信号于你自定义的工作函数连接起来，每当发出工作信号，工作函数就开始执行
6、必须在发出工作信号之前执行线程对象的start()函数，否则工作函数无法执行
7、当工作函数中存在while循环时，如果你想手动终止线程中的while循环，那么一定不能使用属于线程的槽函数，因为此时消息队列被线程中的while‘饿死’了。
*/

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Controller control;
	control.Start();

	return a.exec();
}
