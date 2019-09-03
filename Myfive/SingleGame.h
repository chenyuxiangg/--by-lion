#pragma once
#ifndef SINGLEGAME_H
#define SINGLEGAME_H

#include "Game.h"
//本文件内的数据均是数据处理格式的大小。

class CSingleGame :public CGame {
private:
	CSingleGame();
	CSingleGame(const CSingleGame&);
	CSingleGame& operator=(const CSingleGame&) {}

private:
	static CSingleGame* m_instance;

public:
	static CSingleGame* GetInstance();
	virtual ~CSingleGame();
	virtual void Judge();
	void FindNextDown();
	void FindBasepoint();//寻找基建依赖点
	void HandlePerEffect(const STEP& step,const PIECE_COLOR& col);
	void FindBuildnext();//寻找基建的下一个点
	void SetOrder(const ORDER_PUT& ord);
	void Setnext(const int a, const int b);
	bool Willfive(int* b, int& direct);
	bool Willfoandthr(int* b);
	bool Willfour(int* b, int& direct);
	bool Willthrandthr(int* b);
	bool Willthree(int* b, int& direct);
	bool WillTow(int* b, int& direct);
	bool Build(int x, int y, GAME_DIRECTION dir);
	int CountForPoint(int x, int y);
	bool IsActiveThree(int* connarr,const PIECE_COLOR& col);//以（i，j）处的落子为依，判断其横竖斜四方是否有活三
	bool IschongThree(int* connarr, const PIECE_COLOR& col);
	bool IsActiveTwo(int * connarr, const PIECE_COLOR& col);
	bool IschongTwo(int* connarr, const PIECE_COLOR& col);
	int GetTwobit(const int& ch, int direct);//与helper.h中定义一样
	void SetTwobitwithcol(BordPoint& p, int direct, int count, const PIECE_COLOR& curcol);
	void SetTwobit(char& ch, int direct, int count);//与helper.h中定义一样
	bool Haveone(PIECE_COLOR col);
	void SetCurTurn();//设置当前的回合，同时改变m_curcol的值

	//void MHandle(HWND hwnd, HDC hdc, HBRUSH hbrush);//需要考虑有没有必要使用
	//void SetOne(char& c, int i);//将c的第i位设置为1,与helper.h中定义一样
	//int GetBit(const int& c, int i);//取C的第i位,与helper.h中定义一样
	//int GetLastOne(const int& c);//获取从左往右最后一个1的位置,与helper.h中定义一样
	//bool Isborder(int x, int y);
	//bool IsBestPoint(int x, int y, int direct);//可用活三，活四代替
	//bool IsActiveFour(int* connarr,const PIECE_COLOR& col);//与helper.h中定义一样,原来是Judgethrough,只是判断活四
	//bool IsCRFour(int* connarr, const PIECE_COLOR& col);//冲正四，也就是落子后成为活四的三
	//bool IsCFour(int* connarr, const PIECE_COLOR& col);

public:
	STEP m_nextpoint;//记录下一步机器应该下在哪里,定义为后台处理棋盘的格式
	int m_x;
	int m_y;//m_x与m_y用于记录受影响的一端的坐标，定义为后台处理棋盘的格式
	int build_x;
	int build_y;//基础搭建的依赖点,定义为后台处理棋盘格式
	PIECE_COLOR m_col;//记录机器的棋子颜色
	bool m_first;//记录是否是下第一颗棋子
	int m_build_count;//基础建设的次数，最多搭建两次
	bool m_isbuild;//是否是进行基础搭建
	MACHINE_ACT m_act;//当前机器的行为
	CURRENT_CONNECT m_connect;//记录当前的连珠数，用于判断机器下一步的走向
	/*
	基础建设搭建规则：寻找周围黑棋数最少的己方棋子作为依靠点进行搭建
	*/
};

#endif