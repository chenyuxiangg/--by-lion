#ifndef DRAW_H
#define DRAW_H

#include <windows.h>

class UI{
	private:
		UI():m_color(RGB(0,0,0)){
			Init();
		};
		UI& UI(const UI&);
		UI& operator=(const UI&);
		
	public:
		void DrawPixel(unsigned long x,unsigned long y);
		void DrawLoop(double start,double end,double step);
		void SetColor(COLORREF col);
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
		
		void Init();
		LRESULT CALLBACK WindowProc(HWND hwnd,UINT umsg,WPARAM wParam,LPARAM lParam);
		
		static UI* Getinstance();
		
	private:
		static UI* m_instance;
		COLORREF m_color;
		HWND m_hwnd;
		HPEN m_hpen;
		HBRUSH m_hbrush;
};

#endif 
