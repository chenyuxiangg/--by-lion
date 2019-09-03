#pragma once
#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

enum direction {NO, DOWN, LEFT, UP, RIGHT };

class Stack;
class Coordinate
{
public:
	friend class Stack;
	Coordinate();
	Coordinate(int x, int y);
	//Coordinate(int x, int y,direction di);
	~Coordinate();
	void setdir(direction elem);
	int getX();
	int getY();
	int getdirec();
private:
	int X;
	int Y;
	direction d;
};

class Stack
{
public:
	friend ostream& operator<<(ostream& out, Coordinate c);
	Stack();
	~Stack();
	bool Push(Coordinate c);
	Coordinate Pop(Coordinate& c);
	bool Isempty();
	bool Isfull();
	Coordinate& getTop();
	void traverse();
private:
	int Top;
	Coordinate* coor;

};

#endif