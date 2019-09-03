#pragma once
#include <iostream>
using namespace std;

class Complex
{public:
	Complex(double r);
	Complex(double r , double i);
	Complex();
	Complex(Complex& c);
	~Complex();
	friend Complex operator+(Complex a, Complex b);
	friend Complex operator-(Complex a, Complex b);
	friend Complex operator*(Complex a, Complex b);
	friend Complex operator/(Complex a, Complex b);
	friend ostream& operator<<(ostream& out, Complex& c);

private:
	double real;
	double imag;
};

ostream& operator<<(ostream& out, Complex& c);

Complex ::Complex(Complex& c)
{
	real = c.real;
	imag = c.imag;
}

Complex :: Complex()
{
	real = 0;
	imag = 0;
}

Complex :: Complex(double r)
{
	real = r;
	imag = 0;
}

Complex :: Complex(double r,double i)
{
	real = r;
	imag = i;
}

Complex :: ~Complex()
{}

Complex operator+(Complex a,Complex b)
{
	Complex t;
	t.real = b.real + a.real;
	t.imag = b.imag + a.imag;
	return t;
}

Complex operator-(Complex a, Complex b)
{
	return Complex(a.real - b.real, a.imag - b.imag);
}

Complex operator*(Complex a, Complex b)
{
	double x = (a.real * b.real) - (a.imag * b.imag);
	double y = (a.imag * b.real) + (a.real * b.imag);
	return Complex(x, y);
}

Complex operator/(Complex a, Complex b)
{
	double x = (a.real * b.real) + (a.imag * b.imag);
	double m = (b.real * b.real) + (b.imag * b.imag);
	double xm = x / m;

	double w = (a.imag * b.real) - (a.real * b.imag);
	double n = (b.real * b.real) + (b.imag * b.imag);
	double wn = w / n;

	return Complex(xm, wn);
}

ostream& operator<<(ostream& out, Complex& c)
{
	out << "(" << c.real << "," << c.imag << "i)";
	return out;
}