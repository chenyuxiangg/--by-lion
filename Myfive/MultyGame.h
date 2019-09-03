#pragma once
#ifndef MULTYGAME_H
#define MULTYGAME_H

#include "Game.h"

class CMultyGame :public CGame {
private:
	CMultyGame();
	CMultyGame(const CMultyGame&);
	CMultyGame& operator=(const CMultyGame&);

public:
	static CMultyGame* GetInstance();
	virtual ~CMultyGame();
	virtual void Judge();

private:
	static CMultyGame* m_instance;

public:
	//一些需要用到的方法以及成员变量
};

#endif