#include "base.h"
extern Cbase Chess;
extern helper::GAME_TURN g_turn;
extern CMachine machine;//实例化声明
CMachine machine;//实例化定义

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
	if (Chess.CreateChase(hInstance, Cbase::Wndproc) != S_OK)
		return 0;
	Chess.Createobject(Chess.m_hwnd);
	ShowWindow(Chess.m_hwnd, nShowCmd);
	MoveWindow(Chess.m_hwnd, 200, 100, Chess.m_winwedth, Chess.m_winheight, FALSE);
	Chess.DrawChessbord(Chess.m_hwnd);  //绘制放在ShowWindow之前就不能正确绘制
	helper::CleanBord();

	MSG msg = { 0 };
	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			if (g_turn == helper::TURN_OF_MACHINE)
			{
				machine.MHandle(Cbase::m_hwnd, Cbase::m_hdc, Cbase::m_hbrush[2]);
				machine.HandlePerEffect(CMachine::m_nextpoint);
				Judge();
			}
		}
	}
	Chess.Clean(Chess.m_hwnd);
	return 0;
}