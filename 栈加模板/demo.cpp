#include <iostream>
#include "mystack.h"
#include "Coordinate.h"
using namespace std;

int main(int argc,char * argv[])
{
	Mystack <Coordinate> * p = new Mystack<Coordinate>(5);
	Coordinate coor1(1, 2);
	Coordinate coor2(3, 3);
	Coordinate coor3(7, 5);
	Coordinate coor4(6, 6);
	Coordinate coor5(5, 6);

	p->input(coor1);//调用完成后coor1执行析构函数
	p->input(coor2);
	p->input(coor3);
	p->input(coor4);
	p->getlength();
	p->traverse();

	delete p;
	p = NULL;
	system("pause");
	return 0;
}