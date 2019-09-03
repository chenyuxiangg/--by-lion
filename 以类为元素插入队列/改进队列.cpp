#include "改进队列.h"
#include <iostream>
#include "Circle.h"
using namespace std;

Myqeueu::Myqeueu(int capcity)
{
	Mycapcity = capcity;
	clear();
	myqeueu = new Circle[capcity];
}

Myqeueu :: ~Myqeueu()
{
	delete []myqeueu;
	myqeueu = NULL;
}

void Myqeueu::getmylength()
{
	cout << Mylength << endl;
}

void Myqeueu::clear()
{
	Mylength = 0;
	qhead = 0;
	qtail = 0;
}

bool Myqeueu::qeueuempty()
{
	if (Mylength == 0)
		return true;
	else
		return false;
}

bool Myqeueu::qeueufull()
{
	if (Mylength == Mycapcity)
		return true;
	else
		return false;
}

bool Myqeueu::Delete(Circle& element)
{
	if (qeueuempty())
	{
		return false;
	}
	else
	{
		element = myqeueu[qhead%Mycapcity];
		qhead++;
		Mylength--;
		return true;
	}
}

bool Myqeueu::input(Circle element)
{
	if (qeueufull())
	{
		return false;
	}
	else
	{
		myqeueu[qtail%Mycapcity] = element;
		qtail++;
		Mylength++;
		return true;
	}
}

void Myqeueu::traverse()
{
	for (int i = qhead; i < Mylength + qhead; i++)
	{
		myqeueu[i%Mycapcity].Printf();
	}
	cout << endl;
}