#pragma once
#include <string>
using namespace std;
class Circle
{public:
	Circle(string x = " ",int y = 0);
	~Circle();
	void Printf()const;

private:
	string my_name;
	int my_age;

};