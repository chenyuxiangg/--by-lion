#include"iostream"
using namespace std;

struct complex
{
	double real;
	double imag;
};

class overload
{
public:
	int substruc(int x, int y);
	double substruc(double x, double y);
	complex substruc(complex x, complex y);

};
int overload :: substruc(int x,int y)
{
	return x - y;
}

double overload :: substruc(double x,double y)
{
	return x - y;
}

complex overload :: substruc(complex x,complex y)
{
	complex c;
	c.real = x.real - y.real;
	c.imag = x.imag - y.imag;

	return c;
}

int main(int argc,char *argv[])
{
	int m = 1;
	int n = 2;
	double l = 3.1;
	double j = 2.1;
	complex a, b, c;
	a.real = 5.2;
	a.imag = 8;
	b.real = 6.8;
	b.imag = 1;

	overload o;
	cout << "m" << "-" << "n" << "=" << o.substruc(m,n) << endl;
	cout << "l" << "-" << "j" << "=" << o.substruc(l, j) << endl;
	c = o.substruc(a, b);
	cout << "(" << a.real << "+" << a.imag << "i)";
	cout << "-";
	cout << "(" << b.real << "+" << b.imag << "i)";
	cout << "=" << "(" << c.real << "+" << c.imag << "i)";
	cout << endl;

	return 0;
}