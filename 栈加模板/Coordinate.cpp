#include "Coordinate.h"
#include <iostream>
using namespace std;

Coordinate :: Coordinate(int x ,int y)
{
	cout << "����Coordinate����" << endl;
	i_x = x;
	i_y = y;
}

Coordinate :: ~Coordinate()
{
	cout << "����~Coordinate����" << endl;
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