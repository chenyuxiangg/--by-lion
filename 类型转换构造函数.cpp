#include <iostream>
using namespace std;

class Complex
{public:
	Complex(double a,double b);
	Complex(double r);//类型转换够造函数，将double类型转化成Complex类型
	Complex() { real = 0, imag = 0; }
	~Complex(){}

	friend Complex operator +(Complex c1, Complex c2);
	void display();

private:
	double real;
	double imag;
};

Complex :: Complex(double a,double b)
{
	real = a;
	imag = b;
}

Complex :: Complex(double r)
{
	real = r;
	imag = 0;
}

Complex operator +(Complex c1,Complex c2)
{
	return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

void Complex :: display()
{
	cout << "(" << real << "," << imag << "i)" << endl;
}


int main(int argc,char* argv[])
{
	Complex c1(5.1, 3.9);
	Complex c2,c3;
	c2 = c1 + 2.5;
	c3 = 2.5 + c1;
	cout << "c2:" << endl;
	c2.display();
	cout << "c3:" << endl;
	c3.display();
	system("pause");
	return 0;
}