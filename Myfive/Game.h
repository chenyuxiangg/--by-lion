#pragma once
/*
*作为游戏最基础的东西，他应该包括构建单机和联机游戏所共有的特征，这些特征包括：
*棋盘的定义、基础的操作，同时，他还应该是一个抽象类，包含一些需要子类实现的方法。
*此文件中的棋盘为数据处理棋盘，棋子的坐标以0~14表示
*/
#ifndef GAME_H
#define GAME_H

#include <list>
#include "Game_Struct.h"
using std::list;

class CGame {
public:
	CGame();
	virtual ~CGame() {};

public:
	//注意STEP结构的坐标是数据处理棋盘的坐标
	bool IsVector(bool flag);//与base.h中定义一样,与UI相关
	bool IsBalance(bool flag); //flag表示黑棋白棋满五，//与base.h中定义一样
	void SetBord(const STEP& step, PIECE_COLOR curcol);//每下一颗棋就在Bord中标记一次
	void CleanBord();//与helper.h中定义一样
	bool IsThree(const STEP& step,const PIECE_COLOR& curcol);//因为bord[16][16]是该类的成员，所以不必使用参数传递
	bool IsFour(const STEP& step,const PIECE_COLOR& curcol);
	bool IsFive(const STEP& step,const PIECE_COLOR& curcol);
	virtual void Judge() = 0;
	//bool IsValiablePoint(HWND hwnd, MyPoint& p);//应该放在 MultyGame.h 中

public:
	STEP m_step;//当前一着的位置
	GAME_MODULE m_model;//游戏模式
	BordPoint m_bord[16][16];//游戏数据处理棋盘
	list<STEP> m_list[2];//记录行棋路数,使用emplace_back()在列表末尾插入一个元素
	GAME_TURN m_turn;//记录当前回合
	ORDER_PUT m_order;//记录先后手
	PIECE_COLOR m_youcol;
	PIECE_COLOR m_curcol;//当前落子的颜色,每一回合开始都变为当前角色的颜色，在PVP中无用
	bool m_redraw;//是否需要重绘棋盘
};


#endif