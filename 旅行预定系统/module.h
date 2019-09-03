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
#define BUTTONSTALY (BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE)
#define EDITSTALY (WS_CHILD | WS_VISIBLE | ES_LEFT | WS_BORDER)

//按钮及编辑框结构体
typedef struct BESTRUCT {
	UINT x;//x坐标
	UINT y;//y坐标
	UINT wedth;
	UINT height;
	_TCHAR* identy = NULL;
}BSTRUCTARR[3],ESTRUCTARR[8];

//模块标志
enum MOUDLEFLAG {
	NOTHING,LOG,MAIN,RECORD,QUERY,FLIGHT,BUS,HOTEL,CUSTOMER,TRAIVEL
};

class CModule {
public:
	CModule(UINT bcount, UINT ecount);
	~CModule(){}
	BOOL MyCreateBotton(HWND hwnd,HINSTANCE hInstance,BSTRUCTARR barr, WPARAM wParam, LPARAM lParam);//hwnd父窗口，hInstance当前实例
	BOOL MyCreateEdit(HWND hwnd,HINSTANCE hInstance,ESTRUCTARR earr, WPARAM wParam, LPARAM lParam, DWORD dStaly = WS_CHILD);//dStaly用于特殊编辑框风格的，如密码框
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