#include <iostream>
using namespace std;
int add(int a, int b);
double add(double a, double b);
int main(int argc,char * argv[])
{
	int x = 1;
	int j = 2;
	double c = 5.0;
	double d = 6.1;

	int g = add(x, j);
	add(c, d);
	//cout << "x + j = " << g << endl;
	//cout << "c + d = " << h << endl;

	return 0;
}

int add(int a,int b)
{
	return a + b;
}

double add(double a,double b)//此定义会发生错误
{
	double h = add(a, b);
	cout << "c + d = " << h << endl;
	return a + b;
}