#include "base.h"
//处理棋盘
extern helper::BordPoint Bord[16][16];
extern CMachine machine;
extern helper::GAME_TURN g_turn;
extern helper::ORDER_PUT g_order;

UINT Cbase::m_chessbordsize = 14;
UINT Cbase::m_gap = 30;
HDC Cbase::m_hdc = NULL;
HWND Cbase::m_hwnd = NULL;
HPEN Cbase::m_hpen = NULL;
std::vector<HBRUSH> Cbase::m_hbrush{0,0,0};
UINT Cbase::m_winheight = 600;
UINT Cbase::m_winwedth = 600;
helper::MyPoint Cbase::m_pot;
helper::GAME_MODULE Cbase::m_module = helper::PVM;
bool Cbase::m_black = true;

Cbase::Cbase() {
}

Cbase::~Cbase(){}

HRESULT Cbase::Createobject(HWND hwnd) {
	if (!(m_hpen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0))))
	{
		MessageBox(NULL, TEXT("创建画笔失败"), TEXT("error"), MB_OK);
		return S_FALSE;
	}//创建黑色画笔
	if (!(m_hbrush[0] = CreateSolidBrush(RGB(140, 110, 50))))
	{
		MessageBox(NULL, TEXT("创建画刷失败"), TEXT("error"), MB_OK);
		return S_FALSE;
	}//创建黄色画刷
	if (!(m_hbrush[1] = CreateSolidBrush(RGB(0, 0, 0))))
	{
		MessageBox(NULL, TEXT("创建画刷失败"), TEXT("error"), MB_OK);
		return S_FALSE;
	}//创建黑色画刷
	return S_OK;
}

VOID Cbase::Clean(HWND hwnd) {
	if (m_hpen)
	{
		DeleteObject(m_hpen);
	}
	for (int i = 0; i < 3; i++)
	{
		if (m_hbrush[i])
			DeleteObject(m_hbrush[i]);
	}
}

HRESULT Cbase::DrawChessbord(HWND hwnd) {
	m_hdc = GetDC(hwnd);
	if (m_hbrush[0])
	{
		SelectObject(m_hdc, m_hbrush[0]);
	}
	else
		return S_FALSE;
	Rectangle(m_hdc, 0, 0, m_winwedth, m_winheight);
	if (m_hpen)
	{
		SelectObject(m_hdc, m_hpen);
	}
	else
		return S_FALSE;
	int x = 90;
	int y = 90;
	//画竖线
	for (UINT i = 0; i <= m_chessbordsize; i++) {
		MoveToEx(m_hdc, x, 90, NULL);
		LineTo(m_hdc, x, 510);
		x += m_gap;
	}
	//画横线
	for (UINT i = 0; i <= m_chessbordsize; i++) {
		MoveToEx(m_hdc, 90, y, NULL);
		LineTo(m_hdc, 510, y);
		y += m_gap;
	}
	//画特殊点（172，172，188，188）（412，172，428，188）（172，412，188，428）（412，412，428，428）,中点(293,293,307,307)
	if (m_hbrush[1])
	{
		SelectObject(m_hdc, m_hbrush[1]);
	}
	else
		return S_FALSE;
	int cx = 172; int cy = 188; int cz = 412; int ck = 428; int cl = 293; int cc = 307;
	Ellipse(m_hdc, cx, cx, cy, cy);
	Ellipse(m_hdc, cz, cx, ck, cy);
	Ellipse(m_hdc, cx, cz, cy, ck);
	Ellipse(m_hdc, cz, cz, ck, ck);
	Ellipse(m_hdc, cl, cl, cc, cc);

	if (m_hdc)
		ReleaseDC(hwnd, m_hdc);
	return S_OK;
}

//创建大小不可变得窗口，使用WS_OVERLAPPENDWINDOW & ~WS_THICKFRAME
HRESULT Cbase::CreateChase(HINSTANCE hInstance,WNDPROC lpfnwndproc) {
	WNDCLASSEX Chessbord = { 0 };
	Chessbord.cbSize = sizeof(Chessbord);
	Chessbord.hbrBackground = m_hbrush[0];
	Chessbord.hCursor = LoadCursor(NULL, IDC_ARROW);
	Chessbord.hInstance = hInstance;
	Chessbord.lpfnWndProc = lpfnwndproc;
	Chessbord.lpszClassName = TEXT("Fiveclass");
	if (!RegisterClassEx(&Chessbord))
	{
		MessageBox(NULL, TEXT("窗口类注册失败"), TEXT("error"), MB_OK);
		return S_FALSE;
	}

	if (!(Cbase::m_hwnd = CreateWindow(Chessbord.lpszClassName, TEXT("五子棋"),
		WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME, 0, 0, m_winwedth, m_winheight, NULL, NULL, hInstance, NULL)))
	{
		MessageBox(NULL, TEXT("创建窗口失败"), TEXT("error"), MB_OK);
		return S_FALSE;
	}
	UnregisterClass(Chessbord.lpszClassName, hInstance);
	return S_OK;
}

LRESULT CALLBACK Cbase::Wndproc(HWND hwnd, UINT umsg, WPARAM wParam, LPARAM lParam) {
	switch (umsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:
		if (m_module == helper::PVP)
		{
			if (!IsValiablePoint(m_hwnd, m_pot))
			{
				break;
			}
			helper::Drawpoint(hwnd, m_hdc, m_hbrush[2], m_pot, m_black);//绘制并处理棋盘
			machine.HandlePerEffect(m_pot);
			m_black = !m_black;//切换棋子颜色
			Judge();
			break;
		}
		else
		{
			//用户回合
			if (g_turn == helper::TURN_OF_PERSON)
			{
				//把颜色转换成用户的棋子色
				if (g_order == helper::BEFORE)
				{
					helper::MyPoint::col = RGB(255, 255, 255);
					m_black = false;
				}
				else
				{
					helper::MyPoint::col = RGB(0, 0, 0);
					m_black = true;
				}
				if (!IsValiablePoint(m_hwnd, m_pot))
				{
					g_turn = helper::TURN_OF_PERSON;
					break;
				}
				helper::Drawpoint(hwnd, m_hdc, m_hbrush[2], m_pot, m_black);//绘制并处理棋盘
				machine.HandlePerEffect(m_pot);
				Judge();
				g_turn = helper::TURN_OF_MACHINE;//切换到机器回合
				break;

			}
			else
				break;
		}
	}
	return DefWindowProc(hwnd, umsg, wParam, lParam);
}

extern Cbase Chess;

//函数定义
bool BlackIsVector(bool flag) {
	if (flag)
	{
		MessageBox(NULL, TEXT("恭喜！黑棋胜!"), TEXT("胜利之窗"), MB_OK);
		return true;
	}
	else
		return false;
}

bool WhiteIsVector(bool flag) {
	if (flag)
	{
		MessageBox(NULL, TEXT("恭喜！白棋胜!"), TEXT("胜利之窗"), MB_OK);
		return true;
	}
	else
		return false;
}

bool IsBalance(bool flag) {
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
			if (Bord[i][j].piece == helper::FNULL)
				return false;
	}
	if (!flag)
		return true;
	else
		return false;
}

void Judge() {
	if (Cbase::m_module == helper::PVP)
	{
		if (BlackIsVector(helper::BlackIsFive(Cbase::m_pot, Bord)) ||
			WhiteIsVector(helper::WhiteIsFive(Cbase::m_pot, Bord)))//判断黑棋是否赢
		{
			Cbase::DrawChessbord(Cbase::m_hwnd);//重绘棋盘
			helper::CleanBord();//重置处理棋盘
			Cbase::m_black = true;//重置下一颗棋子颜色
		}
	}
	else
	{
		if (BlackIsVector(helper::BlackIsFive(Cbase::m_pot, Bord)) ||
			WhiteIsVector(helper::WhiteIsFive(CMachine::m_nextpoint, Bord)))//判断黑棋是否赢
		{
			Cbase::DrawChessbord(Cbase::m_hwnd);//重绘棋盘
			helper::CleanBord();//重置处理棋盘
			machine.m_first = true;
			machine.m_isbuild = false;
			machine.m_build_count = 0;
			machine.m_act = ACT_NULL;
			machine.build_x = -1;
			machine.build_y = -1;
			machine.m_x = 0;
			machine.m_y = 0;
		}
	}
}