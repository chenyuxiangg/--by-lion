#pragma once
#ifndef MY_H
#define MY_H

#include "MFC.h"
class cmywinapp : public cwinapp {
public:
	cmywinapp() {  }
	~cmywinapp() {
		if (m_pmainwnd)
		{
			delete m_pmainwnd;
			m_pmainwnd = NULL;
		}
	}
	virtual BOOL initinstance();
};


class cmyframewnd : public cframewnd {
public:
	cmyframewnd();
	~cmyframewnd() {  }
};

class cmydoc :public cdocument {
public:
	cmydoc(){}
	~cmydoc(){}
};

class cmyview :public cview {
	cmyview(){}
	~cmyview(){}
};

//global function
void printallclasses();
#endif