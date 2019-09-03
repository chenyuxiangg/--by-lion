#include "Circle.h"
#include <iostream>
#include <string>
using namespace std;

Circle :: Circle(string x ,int y)
{
	my_name = x;
	my_age = y;
}

Circle :: ~Circle()
{}

void Circle :: Printf() const
{
	cout << "Ãû×Ö:" << my_name << endl;
	cout << "ÄêÁä:" << my_age << endl;
	cout << endl;
}