#pragma once
#ifndef MY_BASE_H
#define MY_BASE_H
//需要包含异常处理

#ifndef MY_WINDOWS_H
#define MY_WINDOWS_H
#include <windows.h>
#include <windowsx.h>
#endif

#include "machine.h"
#include <vector>

class Cbase {
public:
	Cbase();
	~Cbase();
	static HRESULT Createobject(HWND hwnd);
	static HRESULT CreateChase(HINSTANCE hInstance, WNDPROC lpfnwndproc);
	static HRESULT DrawChessbord(HWND hwnd);           //使用m_gap与m_chessbordsize画出棋盘
	static LRESULT CALLBACK Wndproc(HWND hwnd,UINT umsg,WPARAM wParam,LPARAM lParam); //typedef LRESULT (CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
	static VOID Clean(HWND hwnd);

public:
	static bool m_black;
	static HWND m_hwnd;
	static HPEN m_hpen;
	static std::vector<HBRUSH> m_hbrush;
	static HDC m_hdc;
	static UINT m_gap;
	static UINT m_chessbordsize;
	static UINT m_winwedth;
	static UINT m_winheight;
	static helper::MyPoint m_pot;
	static helper::GAME_MODULE m_module;
};

//函数声明
bool BlackIsVector(bool flag);
bool WhiteIsVector(bool flag);
bool IsBalance(bool flag); //flag表示黑棋白棋满五
void Judge();
#endif