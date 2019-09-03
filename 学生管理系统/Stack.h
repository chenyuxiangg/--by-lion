#pragma once
#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

template <typename T>
class Mystack
{
public:
	Mystack(int capcity);
	~Mystack();
	void getlength();
	bool stackfull();
	bool stackempty();
	bool input(T element);
	void outstack(T &element);
	void clear();

private:
	int i_Mycapcity;
	int i_Top;
	T *i_pointer;
};

template <typename T>
Mystack<T>::Mystack(int capcity)
{
	i_pointer = new T[capcity];
	i_Mycapcity = capcity;
	i_Top = 0;
}

template <typename T>
Mystack<T> :: ~Mystack()
{
	delete[] i_pointer;
	i_pointer = NULL;
}

template <typename T>
void Mystack<T>::getlength()
{
	cout << i_Top << endl;
}

template <typename T>
bool Mystack<T>::stackfull()
{
	if (i_Top == i_Mycapcity)
		return true;
	else
		return false;
}

template <typename T>
bool Mystack<T>::stackempty()
{
	if (0 == i_Top)
		return true;
	else
		return false;
}

template <typename T>
bool Mystack<T>::input(T element)
{
	if (stackfull())
	{
		cout << "Õ»Âú¡£" << endl;
		return false;
	}
	else
	{
		i_pointer[i_Top] = element;
		i_Top++;
		return true;
	}
}

template <typename T>
void Mystack<T>::outstack(T &element)
{
	if (!stackempty())
	{
		i_Top--;
		element = i_pointer[i_Top];
		//return element;
	}
}

template <typename T>
void Mystack<T>::clear()
{
	i_Top = 0;
}


#endif