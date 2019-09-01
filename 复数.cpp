#include <iostream>
using namespace std;

class Ccomplex {
public:
	Ccomplex(double r = 0.0, double v = 0.0):rval(r),vval(v){}
	~Ccomplex(){}
	Ccomplex& operator +=(const Ccomplex& c);//成员函数的所有东西都可以访问私有成员，也就是说，成员函数中的该类的对象作为参数时，同样可以直接访问类的私有成员
	Ccomplex& operator -=(const Ccomplex& c);
	Ccomplex& operator *=(const Ccomplex& c);
	Ccomplex& operator /=(const Ccomplex& c);
	friend ostream& operator <<(ostream& out, const Ccomplex& c);

private:
	double rval, vval;
};
Ccomplex& Ccomplex::operator +=(const Ccomplex& c) {
	rval += c.rval;
	vval += c.vval;
	return *this;
}

Ccomplex& Ccomplex::operator -=(const Ccomplex& c) {
	rval -= c.rval;
	vval -= c.vval;
	return *this;
}

Ccomplex& Ccomplex::operator *=(const Ccomplex& c) {
	rval = rval*c.rval - vval*c.vval;
	vval = vval*c.rval + rval*c.vval;
	return *this;
}

Ccomplex& Ccomplex::operator /=(const Ccomplex& c) {
	if (fabs(c.rval) > 0.0 && fabs(c.vval) > 0.0)
	{
		rval = (rval*c.rval + vval*c.vval) / (c.rval*c.rval + c.vval*c.vval);
		vval = (vval*c.rval - rval*c.vval) / (c.rval*c.rval + c.vval*c.vval);
	}
	else
	{
		cout << "除数不能为0" << endl;
	}
	return *this;
}

ostream& operator <<(ostream& out, const Ccomplex& c) {
	out << "(" << c.rval << "," << c.vval << ")";
	return out;
}

int main(int argc, char* argv[])
{
	double r1, v1;
	double r2, v2;
	cin >> r1 >> v1 >> r2 >> v2;
	Ccomplex c1(r1, v1);
	Ccomplex c2(r2, v2);
	Ccomplex c3;
	c3 += c1;
	c3 += c2;
	cout << c3 << endl;

	c3 = Ccomplex(0.0, 0.0);
	c3 += c1;
	c3 -= c2;
	cout << c3 << endl;

	c3 = Ccomplex(0.0, 0.0);
	c3 += c1;
	c3 *= c2;
	cout << c3 << endl;

	c3 = Ccomplex(0.0, 0.0);
	c3 += c1;
	c3 /= c2;
	cout << c3 << endl;

	system("pause");
	return 0;
}