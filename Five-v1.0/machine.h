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
	static void FindBasepoint();//Ѱ�һ���������
	static void HandlePerEffect(const helper::MyPoint& pot);
	static void MHandle(HWND hwnd, HDC hdc, HBRUSH hbrush);
	static void FindBuildnext();//Ѱ�һ�������һ����
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
	static bool Build(int x, int y, helper::GAME_DIRECTION dir);//x,y����ʵ�����̵�λ�ã����Ǻ�̨�������̵�λ��
	static bool Isborder(int x, int y);//����Ϊ��̨�������̵ĸ�ʽ
	static int CountForPoint(int x,int y);//x,y�Ǻ�̨�������̵�λ��
	static bool IsBestPoint(int x, int y,int direct);


public:
	static helper::MyPoint m_nextpoint;//��¼��һ������Ӧ����������,����Ϊ��̨�������̵ĸ�ʽ
	static int m_x;
	static int m_y;//m_x��m_y���ڼ�¼��Ӱ���һ�˵����꣬����Ϊ��̨�������̵ĸ�ʽ
	static int build_x;
	static int build_y;//�������������,����Ϊ��̨�������̸�ʽ
	static COLORREF m_col;
	static bool m_first;
	static int m_build_count;//��������Ĵ������������
	static bool m_isbuild;
	static MACHINE_ACT m_act;
	/*
	������������Ѱ����Χ���������ٵļ���������Ϊ��������д
	*/
private:
	static helper::DEGREE_DIFFICULT m_degree;
};

#endif