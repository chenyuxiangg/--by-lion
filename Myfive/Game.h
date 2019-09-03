#pragma once
/*
*��Ϊ��Ϸ������Ķ�������Ӧ�ð�������������������Ϸ�����е���������Щ����������
*���̵Ķ��塢�����Ĳ�����ͬʱ������Ӧ����һ�������࣬����һЩ��Ҫ����ʵ�ֵķ�����
*���ļ��е�����Ϊ���ݴ������̣����ӵ�������0~14��ʾ
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
	//ע��STEP�ṹ�����������ݴ������̵�����
	bool IsVector(bool flag);//��base.h�ж���һ��,��UI���
	bool IsBalance(bool flag); //flag��ʾ����������壬//��base.h�ж���һ��
	void SetBord(const STEP& step, PIECE_COLOR curcol);//ÿ��һ�������Bord�б��һ��
	void CleanBord();//��helper.h�ж���һ��
	bool IsThree(const STEP& step,const PIECE_COLOR& curcol);//��Ϊbord[16][16]�Ǹ���ĳ�Ա�����Բ���ʹ�ò�������
	bool IsFour(const STEP& step,const PIECE_COLOR& curcol);
	bool IsFive(const STEP& step,const PIECE_COLOR& curcol);
	virtual void Judge() = 0;
	//bool IsValiablePoint(HWND hwnd, MyPoint& p);//Ӧ�÷��� MultyGame.h ��

public:
	STEP m_step;//��ǰһ�ŵ�λ��
	GAME_MODULE m_model;//��Ϸģʽ
	BordPoint m_bord[16][16];//��Ϸ���ݴ�������
	list<STEP> m_list[2];//��¼����·��,ʹ��emplace_back()���б�ĩβ����һ��Ԫ��
	GAME_TURN m_turn;//��¼��ǰ�غ�
	ORDER_PUT m_order;//��¼�Ⱥ���
	PIECE_COLOR m_youcol;
	PIECE_COLOR m_curcol;//��ǰ���ӵ���ɫ,ÿһ�غϿ�ʼ����Ϊ��ǰ��ɫ����ɫ����PVP������
	bool m_redraw;//�Ƿ���Ҫ�ػ�����
};


#endif