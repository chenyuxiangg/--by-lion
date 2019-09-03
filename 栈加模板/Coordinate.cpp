#include "Coordinate.h"
#include <iostream>
using namespace std;

Coordinate :: Coordinate(int x ,int y)
{
	cout << "调用Coordinate（）" << endl;
	i_x = x;
	i_y = y;
}

Coordinate :: ~Coordinate()
{
	cout << "调用~Coordinate（）" << endl;
}

int Coordinate :: getx()
{
	return i_x;
}

int Coordinate :: gety()
{
	return i_y;
}

ostream& operator<<(ostream &out, Coordinate &coor)
{
	out << "(" << coor.getx() << "," << coor.gety() << ")" << endl;
	return out;
}