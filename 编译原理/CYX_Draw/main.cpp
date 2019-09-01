#include <iostream>
#include "CYufa.h"
#include "Cyuyi.h"
#include "UI.h" 
using namespace std; 

extern Token tokentable[];
extern Cyuyi* g_yuyi = new Cyuyi();
extern double& g_parameter = tokentable[2].value;
extern CYufa* g_yufa = new CYufa();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	
	UI::Getinstance()->myInit(hInstance);
	HWND hwnd = UI::Getinstance()->Gethwnd();
	ShowWindow(hwnd,nCmdShow);
	
	MSG msg={};
	while(true){
		if(PeekMessage(&msg,NULL,NULL,NULL,PM_REMOVE)){
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	if(g_yuyi != nullptr){
		delete g_yuyi;
		g_yuyi = nullptr;
	}
	if(g_yufa != nullptr){
		delete g_yufa;
		g_yufa = nullptr;
	}
	return 0;
}


