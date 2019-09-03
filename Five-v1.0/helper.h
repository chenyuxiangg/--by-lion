#pragma once
#ifndef MY_HELPER_H
#define MY_HELPER_H
//��������
#ifndef MY_WINDOWS_H
#define MY_WINDOWS_H
#include <windows.h>
#include <windowsx.h>
#endif

#include <ctime>

//���Ƶ�
namespace helper {
	//�ṹ
	//��ʾ����������
	class MyPoint {
	public:
		int x;
		int y;

	public:
		static COLORREF col;

		MyPoint(int cx = 0,int cy = 0);
	};

	//���ӵ���ɫ
	enum PIECE_COLOR{FNULL,BLACK,WHITE};

	//�Ѷȼ���
	enum DEGREE_DIFFICULT{FEASY,FORDINARY,FDIFFICULT};

	//�����Ⱥ���
	enum ORDER_PUT{BEFORE,BEHAND};

	//��Ϸģʽ
	enum GAME_MODULE{PVP,PVM};

	//�غ�
	enum GAME_TURN{TURN_OF_MACHINE,TURN_OF_PERSON};

	//��̨���̵�һ����
	typedef struct BORD_POINT {
		PIECE_COLOR piece;
		char black_connect;
		char white_connect;
		bool weffect;
		bool beffect;

		BORD_POINT(int x = 0); //Ĭ�ϲ���xûʲô�ã���Ҫ��Ϊ���ܴﵽʹ��intֵ��ʼ��BORD_POINT
	}BordPoint;

	//��ǰλ�ü���������
	enum CURRENT_CONNECT { NONE,WILL_2, WILL_3,WILL_3_3, O_WILL_4,WILL_4,WILL_3_4, WILL_5 };

	//����
	enum GAME_DIRECTION {
		DIRECT_UP = 1, DIRECT_LEFT, DIRECT_DOWN, DIRECT_RIGHT,
		DIRECT_LEFT_UP,DIRECT_RIGHT_UP,DIRECT_LEFT_DOWN,DIRECT_RIGHT_DOWN
	};

	//����
	void Drawpoint(HWND hwnd, HDC hdc, HBRUSH hbrush, MyPoint& pot, bool flag);
	bool Normalize(MyPoint& pot);
	void SetColor(COLORREF color);
	void SetBord(const MyPoint& pot,bool flag);//ÿ��һ�������Bord�б��һ��
	void CleanBord();
	bool BlackIsThree(const MyPoint& pot, BordPoint bord[][16]);
	bool BlackIsFour(const MyPoint& pot, BordPoint bord[][16]);
	bool BlackIsFive(const MyPoint& pot, BordPoint bord[][16]);
	bool WhiteIsThree(const MyPoint& pot,BordPoint bord[][16]);
	bool WhiteIsFour(const MyPoint& pot, BordPoint bord[][16]);
	bool WhiteIsFive(const MyPoint& pot, BordPoint bord[][16]);
	void SetOne(char& c,int i);//��c�ĵ�iλ����Ϊ1
	int GetBit(const int& c, int i);//ȡC�ĵ�iλ
	int GetLastOne(const int& c);//��ȡ�����������һ��1��λ��
	int GetTwobit(const int& ch,int direct);
	void SetTwobit(char& ch,int direct, int count);
	bool Judgethrough(const int& x, const int& y, int direct);
	bool Haveone(PIECE_COLOR col);
	bool IsValiablePoint(HWND hwnd,MyPoint& p);
}

#endif