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
#define BUTTONSTALY (BN_PUSHED | WS_CHILD | WS_VISIBLE)
#define EDITSTALY (WS_CHILD | WS_VISIBLE | ES_LEFT)

//��ť���༭��ṹ��
typedef struct BESTRUCT {
	UINT x;//x����
	UINT y;//y����
	UINT wedth;
	UINT height;
}BSTRUCTARR[20],ESTRUCTARR[20];

class CModule {
public:
	CModule(UINT bcount, UINT ecount);
	~CModule(){}
	BOOL MyCreateBotton(HWND hwnd,HINSTANCE hInstance,BSTRUCTARR barr, WPARAM wParam, LPARAM lParam);//hwnd�����ڣ�hInstance��ǰʵ��
	BOOL MyCreateEdit(HWND hwnd,HINSTANCE hInstance,ESTRUCTARR earr, WPARAM wParam, LPARAM lParam, DWORD dStaly);//dStaly��������༭����ģ��������
	BOOL MyDestory();

private:
	UINT Bcount;
	UINT Ecount;
	std :: vector<HWND> BottonArr;
	std :: vector<HWND> EditArr;
};

#endif