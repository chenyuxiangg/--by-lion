#include "Myqeueu.h"
#include <iostream>
using namespace std;

Myqeueu :: Myqeueu(int capcity)
{
	Mycapcity = capcity;
	clear();
	myqeueu = new int[capcity];
}

Myqeueu :: ~Myqeueu()
{
	delete myqeueu;
	myqeueu = NULL;
}

void Myqeueu :: getmylength()
{
	cout << Mylength << endl;
}

void Myqeueu :: clear()
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

bool Myqeueu :: Delete(int& element)
{
	if(qeueuempty())
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

bool Myqeueu::input(int element)
{
	if(qeueufull())
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

void Myqeueu :: traverse()
{
	for (int i = qhead;i < Mylength + qhead;i++)
	{
		cout << myqeueu[i % Mycapcity] << endl;
	}
	cout << endl;
}