#ifndef DRAW_H
#define DRAW_H

#include "Struct.h"
#include <windows.h>

class UI{
	private:
		UI():m_color(RGB(0,0,0)){
		};
		UI(const UI&){
		};
		UI& operator=(const UI&){
		};
		
	public:
		void DrawPixel(unsigned long x,unsigned long y);
		void DrawLoop(double start,double end,double step,ExprNode* x_nptr,ExprNode* y_nptr);
		void SetColor(COLORREF col);
		static void myStart();
		~UI(){
			if(m_hwnd != nullptr){
				delete m_hwnd;
				m_hwnd = nullptr;
			}
			if(m_instance != nullptr){
				delete m_instance;
				m_instance = nullptr;
			}
		}
		
		void myInit(HINSTANCE hInstance);
		HWND Gethwnd();
		
		static UI* Getinstance();
		static LRESULT CALLBACK WindowProc(HWND hwnd,UINT umsg,WPARAM wParam,LPARAM lParam);
		
		
	private:
		static UI* m_instance;
		COLORREF m_color;
		HWND m_hwnd;
		HPEN m_hpen;
		HBRUSH m_hbrush;
};

#endif 
