#include "iostream"
using namespace std;
class complex
{public:
	complex(double real, double imag);
	complex(complex &c);
	void output();
	complex add(complex c);

private:
	double real;
	double imag;
};

complex :: complex(double real,double imag):real(real),imag(imag)
{
	cout << "调用两个参数的构造函数" << endl;
}

complex :: complex(complex &c)
{
	cout << "调用拷贝构造函数" << endl;
	real = c.real;
	imag = c.imag;
}

void complex :: output()
{
	cout << "(" << real << "," << imag << ")" << endl;
}

complex complex::add(complex c)
{
	complex y(real + c.real, imag + c.imag);  //此处调用构造函数构造一个对象 y 
	return y;
}

void f(complex n)
{
	cout << "n = ";
	n.output();
}

int main(int argc,char* argv[])
{
	complex a(3.0, 4.0), b(5.6, 7.9);
	complex c(a);
	cout << "a =";
	a.output();
	cout << "c =";
	c.output();
	f(b);  //对象作为参数传递时若通过传递，则会调用拷贝构造函数
	c = a.add(b);
	c.output();

	return 0;
}