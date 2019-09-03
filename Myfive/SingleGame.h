#pragma once
#ifndef SINGLEGAME_H
#define SINGLEGAME_H

#include "Game.h"
//���ļ��ڵ����ݾ������ݴ����ʽ�Ĵ�С��

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
	void FindBasepoint();//Ѱ�һ���������
	void HandlePerEffect(const STEP& step,const PIECE_COLOR& col);
	void FindBuildnext();//Ѱ�һ�������һ����
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
	bool IsActiveThree(int* connarr,const PIECE_COLOR& col);//�ԣ�i��j����������Ϊ�����ж������б�ķ��Ƿ��л���
	bool IschongThree(int* connarr, const PIECE_COLOR& col);
	bool IsActiveTwo(int * connarr, const PIECE_COLOR& col);
	bool IschongTwo(int* connarr, const PIECE_COLOR& col);
	int GetTwobit(const int& ch, int direct);//��helper.h�ж���һ��
	void SetTwobitwithcol(BordPoint& p, int direct, int count, const PIECE_COLOR& curcol);
	void SetTwobit(char& ch, int direct, int count);//��helper.h�ж���һ��
	bool Haveone(PIECE_COLOR col);
	void SetCurTurn();//���õ�ǰ�Ļغϣ�ͬʱ�ı�m_curcol��ֵ

	//void MHandle(HWND hwnd, HDC hdc, HBRUSH hbrush);//��Ҫ������û�б�Ҫʹ��
	//void SetOne(char& c, int i);//��c�ĵ�iλ����Ϊ1,��helper.h�ж���һ��
	//int GetBit(const int& c, int i);//ȡC�ĵ�iλ,��helper.h�ж���һ��
	//int GetLastOne(const int& c);//��ȡ�����������һ��1��λ��,��helper.h�ж���һ��
	//bool Isborder(int x, int y);
	//bool IsBestPoint(int x, int y, int direct);//���û��������Ĵ���
	//bool IsActiveFour(int* connarr,const PIECE_COLOR& col);//��helper.h�ж���һ��,ԭ����Judgethrough,ֻ���жϻ���
	//bool IsCRFour(int* connarr, const PIECE_COLOR& col);//�����ģ�Ҳ�������Ӻ��Ϊ���ĵ���
	//bool IsCFour(int* connarr, const PIECE_COLOR& col);

public:
	STEP m_nextpoint;//��¼��һ������Ӧ����������,����Ϊ��̨�������̵ĸ�ʽ
	int m_x;
	int m_y;//m_x��m_y���ڼ�¼��Ӱ���һ�˵����꣬����Ϊ��̨�������̵ĸ�ʽ
	int build_x;
	int build_y;//�������������,����Ϊ��̨�������̸�ʽ
	PIECE_COLOR m_col;//��¼������������ɫ
	bool m_first;//��¼�Ƿ����µ�һ������
	int m_build_count;//��������Ĵ������������
	bool m_isbuild;//�Ƿ��ǽ��л����
	MACHINE_ACT m_act;//��ǰ��������Ϊ
	CURRENT_CONNECT m_connect;//��¼��ǰ���������������жϻ�����һ��������
	/*
	������������Ѱ����Χ���������ٵļ���������Ϊ��������д
	*/
};

#endif