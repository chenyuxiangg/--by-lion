#pragma once
#include <iostream>
using namespace std;

template <class T>
class Queue
{
public:
	Queue(int capcity = 10);
	~Queue();
	bool isEmpty();
	bool isFull();
	bool Push(T element);
	bool Pop(T& element);
	bool Front();
	bool Real();

private:
	T* queue;
	int front;
	int real;
	int Mycapcity;
};

template <class T>
Queue<T> ::Queue(int capcity)
{
	queue = new T[capcity];
	Mycapcity = capcity;
	front = real = 0;
}

template <class T>
Queue<T> :: ~Queue()
{
	delete[] queue;
	queue = NULL;
}

template <class T>
bool Queue<T> ::isEmpty()
{
	return (front == real);
}

template <class T>
bool Queue<T> ::isFull()
{
	return ((real - front) == (Mycapcity-1) || (real - front) + Mycapcity == (Mycapcity-1));
}

template <class T>
bool Queue<T> ::Push(T element)
{
	if (isFull())
	{
		cout << "队列满" << endl;
		return false;
	}
	real++;
	queue[(real) % Mycapcity] = element;
	return true;
}

template <class T>
bool Queue<T> ::Pop(T& element)
{
	if(isEmpty())
{
	cout << "队列空" << endl;
	return false;
}
	element = queue[(front + 1) % Mycapcity];
	front++;
	return true;
}

template <class T>
bool Queue<T> ::Front()
{
	if (isEmpty())
	{
		cout << "队列空" << endl;
		return false;
	}
	cout << queue[(front + 1) % Mycapcity] << endl;
	return true;
}

template <class T>
bool Queue<T> ::Real()
{
	if (isEmpty())
	{
		cout << "队列空" << endl;
		return false;
	}
	cout << queue[real % Mycapcity] << endl;
	return true;
}