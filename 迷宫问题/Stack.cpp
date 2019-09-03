#include <iostream>
#include "Stack.h"
using namespace std;

Coordinate :: Coordinate()
{
	X = 0;
	Y = 0;
	d = DOWN;
}

Coordinate :: Coordinate(int x,int y)
{
	X = x;
	Y = y;
	d = DOWN;
}

Coordinate :: ~Coordinate()
{}

Stack :: Stack()
{
	Top = 0;
	coor = new Coordinate[100];
}

Stack :: ~Stack()
{
	delete[] coor;
	coor = NULL;
}

void Coordinate :: setdir(direction elem)
{
	d = elem;
}

int Coordinate :: getX()
{
	return X;
}

int Coordinate :: getY()
{
	return Y;
}

int Coordinate :: getdirec()
{
	return d;
}

bool Stack::Push(Coordinate c)
{
	if (Isfull())
		return false;
	coor[Top] = c;
	Top++;
	return true;
}

Coordinate Stack::Pop(Coordinate& c)
{
	Top--;
	c = coor[Top];
	return c;
}

bool Stack::Isempty()
{
	if (Top == 0)
		return true;
	return false;
}

bool Stack::Isfull()
{
	if (Top == 100)
		return true;
	return false;
}

Coordinate& Stack :: getTop()
{
	return coor[Top - 1];
}

ostream& operator<<(ostream& out, Coordinate c)
{
	out << "(" << c.getX() << "," << c.getY() << "," << c.getdirec() << ")";
	return out;
}

void Stack :: traverse()
{
	int top = Top;
	while(top != 0)
	{
		top--;
		cout << coor[top] << endl;
	}
}