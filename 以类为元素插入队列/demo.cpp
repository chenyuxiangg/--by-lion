#include "改进队列.h"
#include "Circle.h"
#include <iostream>
using namespace std;

int main(int argc,char * argv[])
{
	Myqeueu * p = new Myqeueu(4);
	Circle c1("zhangsan", 20);
	Circle c2("lisi", 21);
	Circle c3("wangwu", 22);
	Circle c4("wangmazi", 23);

	p->input(c1);
	p->input(c2);
	p->input(c3);
	p->input(c4);

	p->traverse();
	Circle c5;
	p->Delete(c5);
	c5.Printf();
	cout << endl;
	p->traverse();

	Circle c6("chenyuxiang", 20);
	p->input(c6);
	p->traverse();

	delete p;
	p = NULL;

	system("pause");
	return 0;
}