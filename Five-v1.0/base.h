#pragma once
#ifndef MY_BASE_H
#define MY_BASE_H
//��Ҫ�����쳣����

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
	static HRESULT DrawChessbord(HWND hwnd);           //ʹ��m_gap��m_chessbordsize��������
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

//��������
bool BlackIsVector(bool flag);
bool WhiteIsVector(bool flag);
bool IsBalance(bool flag); //flag��ʾ�����������
void Judge();
#endif