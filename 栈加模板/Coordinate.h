#pragma once
#include <ostream>
using namespace std;
class Coordinate
{public:
	Coordinate(int x = 0 , int y = 0);
	~Coordinate();
	friend ostream& operator<<(ostream &out, Coordinate &coor);
	int getx();
	int gety();
private:
	int i_x;
	int i_y;
};