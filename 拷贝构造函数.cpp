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
	cout << "�������������Ĺ��캯��" << endl;
}

complex :: complex(complex &c)
{
	cout << "���ÿ������캯��" << endl;
	real = c.real;
	imag = c.imag;
}

void complex :: output()
{
	cout << "(" << real << "," << imag << ")" << endl;
}

complex complex::add(complex c)
{
	complex y(real + c.real, imag + c.imag);  //�˴����ù��캯������һ������ y 
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
	f(b);  //������Ϊ��������ʱ��ͨ�����ݣ������ÿ������캯��
	c = a.add(b);
	c.output();

	return 0;
}