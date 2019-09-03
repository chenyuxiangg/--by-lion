#pragma once
/*
类说明：
在主窗口已建立的前提下，用于创建一个简单的只含有按钮和文本编辑框的模板界面
*/
#ifndef MODULE_H
#define MODULE_H

#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
#include <vector>

//宏
#define BUTTONSTALY (BN_PUSHED | WS_CHILD | WS_VISIBLE)
#define EDITSTALY (WS_CHILD | WS_VISIBLE | ES_LEFT)

//按钮及编辑框结构体
typedef struct BESTRUCT {
	UINT x;//x坐标
	UINT y;//y坐标
	UINT wedth;
	UINT height;
}BSTRUCTARR[20],ESTRUCTARR[20];

class CModule {
public:
	CModule(UINT bcount, UINT ecount);
	~CModule(){}
	BOOL MyCreateBotton(HWND hwnd,HINSTANCE hInstance,BSTRUCTARR barr, WPARAM wParam, LPARAM lParam);//hwnd父窗口，hInstance当前实例
	BOOL MyCreateEdit(HWND hwnd,HINSTANCE hInstance,ESTRUCTARR earr, WPARAM wParam, LPARAM lParam, DWORD dStaly);//dStaly用于特殊编辑框风格的，如密码框
	BOOL MyDestory();

private:
	UINT Bcount;
	UINT Ecount;
	std :: vector<HWND> BottonArr;
	std :: vector<HWND> EditArr;
};

#endif