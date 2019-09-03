/*
写出能检查可能的上溢和下溢的plus() minus() multiply() divide().让他们在出现这种情况时抛出异常。
*/

#include <iostream>
#include <limits>
#include <string>
#include <cmath>
using namespace std;

//plus
double mplus(double a,double b);

//minus
double mminus(double a,double b);

//multiply
double mutiply(double a,double b);

//divide
double divide(double a,double b);

//驱动函数
int main(int argc,char* argv[])
{
	double x,y;
	try{
		while(true)
		{
			cin >> x >> y;
			cout << "����:";
			char ch;
			cin >> ch;
			
			switch(ch)
			{
				case '+':
					cout << mplus(x,y);
					break;
				case '-':
					cout << mminus(x,y);
					break;
				case '*':
					cout << mutiply(x,y);
					break;
				case '/':
					cout << divide(x,y);
					break;
					
				default:
					throw "error input!";
					break;
			}
		}
	}
	catch(const char* s)
	{
		cerr << s;
		return -1;
	}
	
	system("pause");
	return 0;
}

//plus
double mplus(double a,double b)
{
	if((b > 0.0 && a > numeric_limits<double>::max() - b)
	|| (b < 0.0 && a > numeric_limits<double>::min() - b))
	{
		throw "plus overflow";
	}
	else if(a != -b && a+b == 0)
	{
		throw "a";
	}
	else
	{
		return a+b;
	}
}

//minus
double mminus(double a,double b)
{
	return mplus(a,-b);
}

//multiply
double mutiply(double a,double b)
{
	if(fabs(b) > 1.0 && fabs(a) > numeric_limits<double>::max()/fabs(b))
	{
		throw "mutiply overflow";
	}
	double re = b*a;
	if(b != 0 && a != 0 && re == 0)
		throw "mutiply underflow";
	else
		return a*b;
}

//divide
double divide(double a,double b)
{
	if(fabs(b) < 1.0 && fabs(a) > numeric_limits<double>::max()*fabs(b))
		throw "divide overflow";
	double re = a/b;
	if(b == 0)
		throw "error input";
	else if(a != 0 && re == 0)
		throw "divide underflow";
	else
		return a/b;
}
