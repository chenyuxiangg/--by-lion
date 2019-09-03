#pragma once
/*
��˵����
���������ѽ�����ǰ���£����ڴ���һ���򵥵�ֻ���а�ť���ı��༭���ģ�����
*/
#ifndef MODULE_H
#define MODULE_H

#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
#include <vector>

//��
#define BUTTONSTALY (BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE)
#define EDITSTALY (WS_CHILD | WS_VISIBLE | ES_LEFT | WS_BORDER)

//��ť���༭��ṹ��
typedef struct BESTRUCT {
	UINT x;//x����
	UINT y;//y����
	UINT wedth;
	UINT height;
	_TCHAR* identy = NULL;
}BSTRUCTARR[3],ESTRUCTARR[8];

//ģ���־
enum MOUDLEFLAG {
	NOTHING,LOG,MAIN,RECORD,QUERY,FLIGHT,BUS,HOTEL,CUSTOMER,TRAIVEL
};

class CModule {
public:
	CModule(UINT bcount, UINT ecount);
	~CModule(){}
	BOOL MyCreateBotton(HWND hwnd,HINSTANCE hInstance,BSTRUCTARR barr, WPARAM wParam, LPARAM lParam);//hwnd�����ڣ�hInstance��ǰʵ��
	BOOL MyCreateEdit(HWND hwnd,HINSTANCE hInstance,ESTRUCTARR earr, WPARAM wParam, LPARAM lParam, DWORD dStaly = WS_CHILD);//dStaly��������༭����ģ��������
	UINT MyGetconect(HWND hwnd,_TCHAR* content);
	HWND MyGetBA(int i);
	HWND MyGetEA(int i);
	UINT MyGetBcount() const;
	UINT MyGetEcount() const;
	BOOL MyDestory();

private:
	const UINT Bcount;
	const UINT Ecount;
	std :: vector<HWND> BottonArr;
	std :: vector<HWND> EditArr;
};

#endif