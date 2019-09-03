#pragma once
#ifndef MY_MACHINE_H
#define MY_MACHINE_H

#include "helper.h"
extern helper::BordPoint Bord[16][16];

enum MACHINE_ACT{ACT_NULL,ACT_DEFENSE,ACT_ATTACK,ACT_BUILD};

class CMachine {
public:
	CMachine();
	~CMachine();
	static void FindNextDown();
	static void FindBasepoint();//寻找基建依赖点
	static void HandlePerEffect(const helper::MyPoint& pot);
	static void MHandle(HWND hwnd, HDC hdc, HBRUSH hbrush);
	static void FindBuildnext();//寻找基建的下一个点
	static void SetDegree(const helper::DEGREE_DIFFICULT& deg);
	static void SetOrder(const helper::ORDER_PUT& ord);
	static void Setnext(const int a, const int b);
	static bool IsSameColor(const helper::PIECE_COLOR& pcol, const COLORREF& col);
	static bool Willfive(int* b,int& direct);
	static bool Willfoandthr(int* b, int& direct);
	static bool Willfour(int* b, int& direct);
	static bool Willthrandthr(int* b, int& direct);
	static bool Willthree(int* b, int& direct);
	static bool WillTow(int* b, int& direct);
	static bool Build(int x, int y, helper::GAME_DIRECTION dir);//x,y都是实际棋盘的位置，不是后台处理棋盘的位置
	static bool Isborder(int x, int y);//定义为后台处理棋盘的格式
	static int CountForPoint(int x,int y);//x,y是后台处理棋盘的位置
	static bool IsBestPoint(int x, int y,int direct);


public:
	static helper::MyPoint m_nextpoint;//记录下一步机器应该下在哪里,定义为后台处理棋盘的格式
	static int m_x;
	static int m_y;//m_x与m_y用于记录受影响的一端的坐标，定义为后台处理棋盘的格式
	static int build_x;
	static int build_y;//基础搭建的依赖点,定义为后台处理棋盘格式
	static COLORREF m_col;
	static bool m_first;
	static int m_build_count;//基础建设的次数，最多搭建两次
	static bool m_isbuild;
	static MACHINE_ACT m_act;
	/*
	基础建设搭建规则：寻找周围黑棋数最少的己方棋子作为依靠点进行搭建
	*/
private:
	static helper::DEGREE_DIFFICULT m_degree;
};

#endif