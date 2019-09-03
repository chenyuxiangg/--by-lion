#pragma once
/*
*该文件包含通用的数据结构
*/
#ifndef GAME_STRUCT_H
#define GAME_STRUCT_H

//由于我需要用图片代替以GUI直接用图形来绘制棋子，所以这里不需要使用颜色
//原来是 class Mypoint
typedef struct STEP {
	int x;
	int y;
};

//棋子的颜色
enum PIECE_COLOR { FNULL, BLACK, WHITE };

//难度级别
enum DEGREE_DIFFICULT { FEASY, FDIFFICULT };

//先后手
enum ORDER_PUT { ORDER_NONE,BEFORE, BEHAND };

//游戏模式
enum GAME_MODULE { MUDEL_NONE,PVP, PVM };

//回合
enum GAME_TURN { TURN_NONE,TURN_OF_OTHER, TURN_OF_YOU };

//后台棋盘的一个点,！！！这是最重要的地方！！！
typedef struct BORD_POINT {
	PIECE_COLOR piece;
	char black_connect;
	char white_connect;
	bool weffect;
	bool beffect;

	BORD_POINT(int x = 0); //默认参数x没什么用，主要是为了能达到使用int值初始化BORD_POINT
}BordPoint;

//当前位置即将几连珠
enum CURRENT_CONNECT { NONE, WILL_2,O_CHONG_2,M_CHONG_2,O_ACTIVE_2,M_ACTIVE_2,O_CHONG_3,M_CHONG_3,O_AVTIVE_3,M_ACTIVE_3, WILL_5 };

//方向
enum GAME_DIRECTION {
	DIRECT_UP = 1, DIRECT_LEFT, DIRECT_DOWN, DIRECT_RIGHT,
	DIRECT_LEFT_UP, DIRECT_RIGHT_UP, DIRECT_LEFT_DOWN, DIRECT_RIGHT_DOWN
};

//机器的行为
enum MACHINE_ACT { ACT_NULL, ACT_DEFENSE, ACT_ATTACK, ACT_BUILD };

#endif
