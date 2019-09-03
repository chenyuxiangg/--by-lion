#pragma once
#ifndef MY_HELPER_H
#define MY_HELPER_H
//辅助功能
#ifndef MY_WINDOWS_H
#define MY_WINDOWS_H
#include <windows.h>
#include <windowsx.h>
#endif

#include <ctime>

//绘制点
namespace helper {
	//结构
	//显示出来的棋子
	class MyPoint {
	public:
		int x;
		int y;

	public:
		static COLORREF col;

		MyPoint(int cx = 0,int cy = 0);
	};

	//棋子的颜色
	enum PIECE_COLOR{FNULL,BLACK,WHITE};

	//难度级别
	enum DEGREE_DIFFICULT{FEASY,FORDINARY,FDIFFICULT};

	//机器先后手
	enum ORDER_PUT{BEFORE,BEHAND};

	//游戏模式
	enum GAME_MODULE{PVP,PVM};

	//回合
	enum GAME_TURN{TURN_OF_MACHINE,TURN_OF_PERSON};

	//后台棋盘的一个点
	typedef struct BORD_POINT {
		PIECE_COLOR piece;
		char black_connect;
		char white_connect;
		bool weffect;
		bool beffect;

		BORD_POINT(int x = 0); //默认参数x没什么用，主要是为了能达到使用int值初始化BORD_POINT
	}BordPoint;

	//当前位置即将几连珠
	enum CURRENT_CONNECT { NONE,WILL_2, WILL_3,WILL_3_3, O_WILL_4,WILL_4,WILL_3_4, WILL_5 };

	//方向
	enum GAME_DIRECTION {
		DIRECT_UP = 1, DIRECT_LEFT, DIRECT_DOWN, DIRECT_RIGHT,
		DIRECT_LEFT_UP,DIRECT_RIGHT_UP,DIRECT_LEFT_DOWN,DIRECT_RIGHT_DOWN
	};

	//功能
	void Drawpoint(HWND hwnd, HDC hdc, HBRUSH hbrush, MyPoint& pot, bool flag);
	bool Normalize(MyPoint& pot);
	void SetColor(COLORREF color);
	void SetBord(const MyPoint& pot,bool flag);//每下一颗棋就在Bord中标记一次
	void CleanBord();
	bool BlackIsThree(const MyPoint& pot, BordPoint bord[][16]);
	bool BlackIsFour(const MyPoint& pot, BordPoint bord[][16]);
	bool BlackIsFive(const MyPoint& pot, BordPoint bord[][16]);
	bool WhiteIsThree(const MyPoint& pot,BordPoint bord[][16]);
	bool WhiteIsFour(const MyPoint& pot, BordPoint bord[][16]);
	bool WhiteIsFive(const MyPoint& pot, BordPoint bord[][16]);
	void SetOne(char& c,int i);//将c的第i位设置为1
	int GetBit(const int& c, int i);//取C的第i位
	int GetLastOne(const int& c);//获取从左往右最后一个1的位置
	int GetTwobit(const int& ch,int direct);
	void SetTwobit(char& ch,int direct, int count);
	bool Judgethrough(const int& x, const int& y, int direct);
	bool Haveone(PIECE_COLOR col);
	bool IsValiablePoint(HWND hwnd,MyPoint& p);
}

#endif