#include "UI.h"
#include <cmath>

UI* UI::m_instance = nullptr;

UI* UI::Getinstance(){
	if(m_instance == nullptr){
		m_instance = new UI();
	}
	return m_instance;
}

void UI::Init(HIINSTANCE hInstance){
	m_hwnd = nullptr;
	m_hpen = nullptr;
	m_hbrush = nullptr;
	const wchar_t* CLASS_NAME = TEXT("myclass");
	const wchar_t* WINDOW_NAME = TEXT("Ïè¸ç»æÍ¼");
	
	WNDCLASS myClass;
	myClass.style = CS_HREDRAW || CS_VREDRAW;
	myClass.lpfnWndProc = WindowProc;
	myClass.cbClsExtra = 0;
	myClass.cbWndExtra = 0;
	myClass.hIcon = LoadIcon(NULL,IDI_APPLICATION);
	myClass.hCursor = LoadCursor(NULL,IDC_ARROW);
	myClass.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH));
	myClass.hInstance = hInstance;
	myClass.lpszClassName = CLASS_NAME;
	
	RegisterClass(&myClass);
	
	m_hwnd = CreateWindowEx(NULL,myClass.lpszClassName,WINDOW_NAME,WS_OVERLAPPEDWINDOW,
	CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
	NULL,NULL,hInstance,NULL);
	
	if(m_hwnd == nullptr){
		return;
	}else{
		UnregisterClass(&myClass);
		return;
	}
}

LRESULT CALLBACK UI::WindowProc(HWND hwnd,UINT umsg,WPARAM wParam,LPARAM lParam){
	switch(umsg){
		case WM_DESTORY:
			PostQuitMessage(0);
			return 0;
		default:
			return DefWindowProc(hwnd,umsg,wParam,lParam);
	}
}

void UI::DrawPixel(unsigned long x,unsigned long y){
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(m_hwnd,&ps);
	SetPixel(hdc,x,y,m_color);
	EndPaint(m_hwnd,&ps); 
}


void UI::DrawLoop(double start,double end,double step,ExprNode* x_nptr,ExprNode* y_nptr){
	extern double g_parameter;
	extern Cyuyi* g_yuyi;
	for(g_parameter = start;g_parameter <= end;g_parameter)+=step{
		g_yuyi->CalcCoord(x_nptr,y_nptr);
		Point point = g_yuyi->GetCurrentPoint();
		DrawPixel((unsigned long)point.x,(unsigned long)point.y);
	}
}

void UI::SetColor(COLORREF col){
	m_color = col;
}
