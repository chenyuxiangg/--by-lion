#include "helper.h"
//helper.h中用到base.h，但是base.h中也用到helper.h,怎么办？？
/*
二维数组作为参数传递：
void Func(int array[3][10]);

void Func(int array[][10]);

二者都是合法而且等价，但是不能把第二维或者更高维的大小省略，如下面的定义是不合法的：

void Func(int array[][]);

以引用方式传递二维数组：

问题：
单击一次鼠标后，在此次鼠标作用生效前想要再次取得鼠标单击位置应该如何做？
如何让机器判别已经有异子放置在连珠的一端？

*/

COLORREF helper::MyPoint::col = RGB(0, 0, 0);
helper::MyPoint::MyPoint(int cx, int cy) {
	x = cx;
	y = cy;
}

extern helper::BordPoint Bord[16][16] = {0};
extern helper::GAME_TURN g_turn = helper::TURN_OF_PERSON;
extern helper::CURRENT_CONNECT g_connect = helper::NONE;
extern helper::ORDER_PUT g_order = helper::BEHAND;

bool helper::Normalize(MyPoint& pot) {
	if (pot.x == 0 && pot.y == 0)
		return false;

	int xr, xp;//x坐标与m_gap的商和余数
	int yr, yp;//y坐标与m_gap的商和余数
	xr = pot.x / 30; xp = pot.x % 30;
	yr = pot.y / 30; yp = pot.y % 30;

	if (xp >= 15)
		xr += 1;
	if (yp >= 15)
		yr += 1;
	pot.x = xr * 30;
	pot.y = yr * 30;
	return true;
}

void helper::Drawpoint(HWND hwnd,HDC hdc,HBRUSH hbrush, MyPoint& pot,bool flag) {
	if (hwnd)
	{
		hdc = GetDC(hwnd);
	}
	else
	{
		MessageBox(NULL, TEXT("绘制失败"), TEXT("error"), MB_OK);
		return;
	}
	if (!flag)
	{
		SetColor(RGB(255, 255, 255));
	}
	else
		SetColor(RGB(0, 0, 0));
	if ((hbrush = CreateSolidBrush(pot.col)))
	{
		SelectObject(hdc, hbrush);
	}
	else
	{
		MessageBox(NULL, TEXT("画刷2创建失败"), TEXT("error"), MB_OK);
		return;
	}
	if (Normalize(pot))
	{
		if(pot.x < 90 || pot.y < 90 || pot.x > 510 || pot.y > 510)
		{
			//重新获取鼠标位置
			return;
		}
		Ellipse(hdc, pot.x - 15, pot.y - 15, pot.x + 15, pot.y + 15);
	}
	if (hdc)
		ReleaseDC(hwnd, hdc);

	SetBord(pot, flag);
}

void helper::SetColor(COLORREF color) {
	helper::MyPoint::col = color;
}

void helper::SetBord(const MyPoint& pot,bool flag) {
	if (pot.x == 0 && pot.y == 0)
		return;

	int xr, xp;//x坐标与m_gap的商和余数
	int yr, yp;//y坐标与m_gap的商和余数
	xr = (pot.x-90) / 30; xp = (pot.x-90) % 30;
	yr = (pot.y-90) / 30; yp = (pot.y-90) % 30;

	if (xp >= 15)
		xr += 1;
	if (yp >= 15)
		yr += 1;
	
	if (flag)//若是黑棋，则写入1
		Bord[xr][yr].piece = BLACK;
	else
		Bord[xr][yr].piece = WHITE;
}

void helper::CleanBord() {
	for (int i = 0; i < 15; ++i) 
	{
		for (int j = 0; j < 15; ++j) 
		{
			Bord[i][j].black_connect = 0;
			Bord[i][j].white_connect = 0;
			Bord[i][j].beffect = false;
			Bord[i][j].weffect = false;
			Bord[i][j].piece = FNULL;
		}
	}
}

bool helper::BlackIsThree(const MyPoint& pot,helper::BordPoint bord[][16]) {
	if (pot.x == 0 && pot.y == 0)
		return false;
	if (pot.col != RGB(0, 0, 0))
		return false;

	int xr = (pot.x-90) / 30; int yr = (pot.y-90) / 30;
	int xp = (pot.x-90) % 30; int yp = (pot.y-90) % 30;

	if (xp >= 15)
		xr += 1;
	if (yp >= 15)
		yr += 1;

	/* 从四个方向判断是否成 三 */
	if ((bord[xr - 1][yr].piece == BLACK && bord[xr + 1][yr].piece == BLACK) ||
		(bord[xr + 1][yr].piece == BLACK && bord[xr + 2][yr].piece == BLACK) ||
		(bord[xr - 1][yr].piece == BLACK && bord[xr - 2][yr].piece == BLACK))//横向
		return true;
	else if ((bord[xr][yr - 1].piece == BLACK && bord[xr][yr + 1].piece == BLACK) ||
		(bord[xr][yr - 1].piece == BLACK && bord[xr][yr - 2].piece == BLACK) ||
		(bord[xr][yr + 1].piece == BLACK && bord[xr][yr + 2].piece == BLACK))//竖向
		return true;
	else if ((bord[xr - 1][yr - 1].piece == BLACK && bord[xr + 1][yr + 1].piece == BLACK) ||
		(bord[xr - 1][yr - 1].piece == BLACK && bord[xr - 2][yr - 2].piece == BLACK) ||
		(bord[xr + 1][yr + 1].piece == BLACK && bord[xr + 2][yr + 2].piece == BLACK))//右斜
		return true;
	else if (bord[xr + 1][yr - 1].piece == BLACK && bord[xr - 1][yr + 1].piece == BLACK ||
		(bord[xr - 1][yr + 1].piece == BLACK && bord[xr - 2][yr + 2].piece == BLACK) ||
		(bord[xr + 1][yr - 1].piece == BLACK && bord[xr + 2][yr - 2].piece == BLACK))//左斜
		return true;
	else
		return false;
}

bool helper::BlackIsFour(const MyPoint& pot, helper::BordPoint bord[][16]) {
	if ((pot.x == 0 && pot.y == 0) || !BlackIsThree(pot, bord))
		return false;

	int count = -1;
	int xr = (pot.x-90) / 30; int xp = (pot.x-90) % 30;
	int yr = (pot.y-90) / 30; int yp = (pot.y-90) % 30;

	if (xp >= 15)
		xr += 1;
	if (yp >= 15)
		yr += 1;
	/* 从四个方向判断是否满四 */
	//横向
	for (int i = xr; i >= 0; --i)
	{
		if (bord[i][yr].piece == BLACK)
			count++;
		else
			break;
	}
	for (int i = xr; i < 15; ++i)
	{
		if (bord[i][yr].piece == BLACK)
			count++;
		else
			break;
	}
	if (count >= 4)
		return true;
	else
		count = -1;
	//竖向
	for (int i = yr; i >= 0; --i)
	{
		if (bord[xr][i].piece == BLACK)
			count++;
		else
			break;
	}
	for (int i = yr; i < 15; ++i)
	{
		if (bord[xr][i].piece == BLACK)
			count++;
		else
			break;
	}
	if (count >= 4)
		return true;
	else
		count = -1;
	//右斜
	int i = xr; int j = yr;
	while (i >= 0 && j >= 0)
	{
		if (bord[i][j].piece == BLACK)
		{
			count++;
			i--;
			j--;
		}
		else
		{
			i = xr;
			j = yr;
			break;
		}
	}
	i = xr; j = yr;
	while (i < 15 && j < 15)
	{
		if (bord[i][j].piece == BLACK)
		{
			count++;
			i++;
			j++;
		}
		else
		{
			i = xr;
			j = yr;
			break;
		}
	}
	if (count >= 4)
		return true;
	else
		count = -1;
	//左斜
	i = xr;j = yr;
	while (i < 15 && j >= 0)
	{
		if (bord[i][j].piece == BLACK)
		{
			count++;
			i++;
			j--;
		}
		else
		{
			i = xr;
			j = yr;
			break;
		}
	}
	i = xr;j = yr;
	while (i >= 0 && j < 15)
	{
		if (bord[i][j].piece == BLACK)
		{
			count++;
			i--;
			j++;
		}
		else
			break;
	}
	if (count >= 4)
		return true;
	else
		return false;
}

bool helper::BlackIsFive(const MyPoint& pot, helper::BordPoint bord[][16]) {
	if ((pot.x == 0 && pot.y == 0) || !BlackIsFour(pot, bord))
		return false;

	int count = -1;
	int xr = (pot.x - 90) / 30; int xp = (pot.x - 90) % 30;
	int yr = (pot.y - 90) / 30; int yp = (pot.y - 90) % 30;

	if (xp >= 15)
		xr += 1;
	if (yp >= 15)
		yr += 1;
	/* 从四个方向判断是否满五 */
	//横向
	for (int i = xr; i >= 0; --i)
	{
		if (bord[i][yr].piece == BLACK)
			count++;
		else
			break;
	}
	for (int i = xr; i < 15; ++i)
	{
		if (bord[i][yr].piece == BLACK)
			count++;
		else
			break;
	}
	if (count >= 5)
		return true;
	else
		count = -1;
	//竖向
	for (int i = yr; i >= 0; --i)
	{
		if (bord[xr][i].piece == BLACK)
			count++;
		else
			break;
	}
	for (int i = yr; i < 15; ++i)
	{
		if (bord[xr][i].piece == BLACK)
			count++;
		else
			break;
	}
	if (count >= 5)
		return true;
	else
		count = -1;
	//右斜
	int i = xr; int j = yr;
	while (i >= 0 && j >= 0)
	{
		if (bord[i][j].piece == BLACK)
		{
			count++;
			i--;
			j--;
		}
		else
		{
			i = xr;
			j = yr;
			break;
		}
	}
	i = xr;
	j = yr;
	while (i < 15 && j < 15)
	{
		if (bord[i][j].piece == BLACK)
		{
			count++;
			i++;
			j++;
		}
		else
		{
			i = xr;
			j = yr;
			break;
		}
	}
	if (count >= 5)
		return true;
	else
		count = -1;
	//左斜
	i = xr;
	j = yr;
	while (i < 15 && j >= 0)
	{
		if (bord[i][j].piece == BLACK)
		{
			count++;
			i++;
			j--;
		}
		else
		{
			i = xr;
			j = yr;
			break;
		}
	}
	i = xr;
	j = yr;
	while (i >= 0 && j < 15)
	{
		if (bord[i][j].piece == BLACK)
		{
			count++;
			i--;
			j++;
		}
		else
			break;
	}
	if (count >= 5)
		return true;
	else
		return false;
}

bool helper::WhiteIsThree(const MyPoint& pot, helper::BordPoint bord[][16]) {
	if (pot.x == 0 && pot.y == 0)
		return false;
	if (pot.col != RGB(255, 255, 255))
		return false;

	int xr = (pot.x - 90) / 30; int yr = (pot.y - 90) / 30;
	int xp = (pot.x - 90) % 30; int yp = (pot.y - 90) % 30;

	if (xp >= 15)
		xr += 1;
	if (yp >= 15)
		yr += 1;

	/* 从四个方向判断是否成 三 */
	if ((bord[xr - 1][yr].piece == WHITE && bord[xr + 1][yr].piece == WHITE) ||
		(bord[xr + 1][yr].piece == WHITE && bord[xr + 2][yr].piece == WHITE) ||
		(bord[xr - 1][yr].piece == WHITE && bord[xr - 2][yr].piece == WHITE))//横向
		return true;
	else if ((bord[xr][yr - 1].piece == WHITE && bord[xr][yr + 1].piece == WHITE) ||
		(bord[xr][yr - 1].piece == WHITE && bord[xr][yr - 2].piece == WHITE) ||
		(bord[xr][yr + 1].piece == WHITE && bord[xr][yr + 2].piece == WHITE))//竖向
		return true;
	else if ((bord[xr - 1][yr - 1].piece == WHITE && bord[xr + 1][yr + 1].piece == WHITE) ||
		(bord[xr - 1][yr - 1].piece == WHITE && bord[xr - 2][yr - 2].piece == WHITE) ||
		(bord[xr + 1][yr + 1].piece == WHITE && bord[xr + 2][yr + 2].piece == WHITE))//右斜
		return true;
	else if (bord[xr + 1][yr - 1].piece == WHITE && bord[xr - 1][yr + 1].piece == WHITE ||
		(bord[xr - 1][yr + 1].piece == WHITE && bord[xr - 2][yr + 2].piece == WHITE) ||
		(bord[xr + 1][yr - 1].piece == WHITE && bord[xr + 2][yr - 2].piece == WHITE))//左斜
		return true;
	else
		return false;
}

bool helper::WhiteIsFour(const MyPoint& pot, helper::BordPoint bord[][16]) {
	if ((pot.x == 0 && pot.y == 0) || !WhiteIsThree(pot, bord))
		return false;

	int count = -1;
	int xr = (pot.x - 90) / 30; int xp = (pot.x - 90) % 30;
	int yr = (pot.y - 90) / 30; int yp = (pot.y - 90) % 30;

	if (xp >= 15)
		xr += 1;
	if (yp >= 15)
		yr += 1;
	/* 从四个方向判断是否满四 */
	//横向
	for (int i = xr; i >= 0; --i)
	{
		if (bord[i][yr].piece == WHITE)
			count++;
		else
			break;
	}
	for (int i = xr; i < 15; ++i)
	{
		if (bord[i][yr].piece == WHITE)
			count++;
		else
			break;
	}
	if (count >= 4)
		return true;
	else
		count = -1;
	//竖向
	for (int i = yr; i >= 0; --i)
	{
		if (bord[xr][i].piece == WHITE)
			count++;
		else
			break;
	}
	for (int i = yr; i < 15; ++i)
	{
		if (bord[xr][i].piece == WHITE)
			count++;
		else
			break;
	}
	if (count >= 4)
		return true;
	else
		count = -1;
	//右斜
	int i = xr; int j = yr;
	while (i >= 0 && j >= 0)
	{
		if (bord[i][j].piece == WHITE)
		{
			count++;
			i--;
			j--;
		}
		else
		{
			i = xr;
			j = yr;
			break;
		}
	}
	i = xr; j = yr;
	while (i < 15 && j < 15)
	{
		if (bord[i][j].piece == WHITE)
		{
			count++;
			i++;
			j++;
		}
		else
		{
			i = xr;
			j = yr;
			break;
		}
	}
	if (count >= 4)
		return true;
	else
		count = -1;
	//左斜
	i = xr; j = yr;
	while (i < 15 && j >= 0)
	{
		if (bord[i][j].piece == WHITE)
		{
			count++;
			i++;
			j--;
		}
		else
		{
			i = xr;
			j = yr;
			break;
		}
	}
	i = xr;j = yr;
	while (i >= 0 && j < 15)
	{
		if (bord[i][j].piece == WHITE)
		{
			count++;
			i--;
			j++;
		}
		else
			break;
	}
	if (count >= 4)
		return true;
	else
		return false;
}

bool helper::WhiteIsFive(const MyPoint& pot, helper::BordPoint bord[][16]) {
	if ((pot.x == 0 && pot.y == 0) || !WhiteIsFour(pot, bord))
		return false;

	int count = -1;
	int xr = (pot.x - 90) / 30; int xp = (pot.x - 90) % 30;
	int yr = (pot.y - 90) / 30; int yp = (pot.y - 90) % 30;

	if (xp >= 15)
		xr += 1;
	if (yp >= 15)
		yr += 1;
	/* 从四个方向判断是否满五 */
	//横向
	for (int i = xr; i >= 0; --i)
	{
		if (bord[i][yr].piece == WHITE)
			count++;
		else
			break;
	}
	for (int i = xr; i < 15; ++i)
	{
		if (bord[i][yr].piece == WHITE)
			count++;
		else
			break;
	}
	if (count >= 5)
		return true;
	else
		count = -1;
	//竖向
	for (int i = yr; i >= 0; --i)
	{
		if (bord[xr][i].piece == WHITE)
			count++;
		else
			break;
	}
	for (int i = yr; i < 15; ++i)
	{
		if (bord[xr][i].piece == WHITE)
			count++;
		else
			break;
	}
	if (count >= 5)
		return true;
	else
		count = -1;
	//右斜
	int i = xr; int j = yr;
	while (i >= 0 && j >= 0)
	{
		if (bord[i][j].piece == WHITE)
		{
			count++;
			i--;
			j--;
		}
		else
		{
			i = xr;
			j = yr;
			break;
		}
	}
	i = xr;
	j = yr;
	while (i < 15 && j < 15)
	{
		if (bord[i][j].piece == WHITE)
		{
			count++;
			i++;
			j++;
		}
		else
		{
			i = xr;
			j = yr;
			break;
		}
	}
	if (count >= 5)
		return true;
	else
		count = -1;
	//左斜
	i = xr;
	j = yr;
	while (i < 15 && j >= 0)
	{
		if (bord[i][j].piece == WHITE)
		{
			count++;
			i++;
			j--;
		}
		else
		{
			i = xr;
			j = yr;
			break;
		}
	}
	i = xr;
	j = yr;
	while (i >= 0 && j < 15)
	{
		if (bord[i][j].piece == WHITE)
		{
			count++;
			i--;
			j++;
		}
		else
			break;
	}
	if (count >= 5)
		return true;
	else
		return false;
}

void helper::SetOne(char& c, int i)
{
	c = c | (1 << (i - 1));
}

int helper::GetBit(const int& c, int i)
{
	int j = (c >> (i - 1)) & 1;
	return j;
}

int helper::GetLastOne(const int& c)
{
	for (int i = 4; i > 0; i--)
	{
		if (GetBit(c, i) == 1)
			return i;
	}
	return 0;
}

helper::BORD_POINT::BORD_POINT(int x) {
	piece = helper::FNULL;
	white_connect = 0;
	black_connect = 0;
}

//增强版函数
int helper::GetTwobit(const int& ch,int direct)
{
	int res = (ch >> (direct * 2)) & 3;
	return res;
}

void helper::SetTwobit(char& ch,int direct, int count)
{
	//先判断当前方向上原有的值是否需要改变
	int tmp = GetTwobit(ch, direct);
	if (tmp > count-1)
		return;
	if (count == 1)
	{
		//当它是一的时候，应该冲二，所以将对应的方向置为00
		ch = ch & (~(3 << (direct * 2)));
	}
	else if (count == 2)
	{
		//将对应方向置为01
		ch = ch | (1 << (direct * 2));
		ch = ch & (~(1 << (direct * 2 + 1)));
	}
	else if (count == 3)
	{
		//将对应方向置为10
		ch = ch | (1 << (direct * 2 + 1));
		ch = ch & (~(1 << (direct * 2)));
	}
	else if (count == 4)
	{
		//将对应方向置为11
		ch = ch | (3 << (direct * 2));
	}
}

bool helper::Judgethrough(const int& x, const int& y, int direct)
{
	if (direct == -1)
		return false;
	switch (direct)
	{
	case 0://横向
	{
		int i;
		if (Bord[x + 1][y].piece == FNULL)
		{
			i = x - 1;
			for (i; i > x - 5 && i >= 0; --i)
			{
				if (Bord[i][y].piece == FNULL)
					return true;
				if (g_order == BEHAND)
				{
					if (Bord[i][y].piece == BLACK)
						continue;
					else
						return false;
				}
				else
				{
					if (Bord[i][y].piece == WHITE)
						continue;
					else
						return false;
				}
			}
		}
		else
		{
			i = x + 1;
			for (i; i < x + 5 && i < 15; ++i)
			{
				if (Bord[i][y].piece == FNULL)
					return true;
				if (g_order == BEHAND)
				{
					if (Bord[i][y].piece == BLACK)
						continue;
					else
						return false;
				}
				else
				{
					if (Bord[i][y].piece == WHITE)
						continue;
					else
						return false;
				}
			}
		}
		return false;
	}

	case 1://竖向
	{
		int i;
		if (Bord[x][y + 1].piece == FNULL)
		{
			i = y - 1;
			for (i; i > y - 5 && i >= 0; --i)
			{
				if (Bord[x][i].piece == FNULL)
					return true;
				if (g_order == BEHAND)
				{
					if (Bord[x][i].piece == BLACK)
						continue;
					else
						return false;
				}
				else
				{
					if (Bord[x][i].piece == WHITE)
						continue;
					else
						return false;
				}
			}
		}
		else
		{
			i = y + 1;
			for (i; i < y + 5 && i < 15; ++i)
			{
				if (Bord[x][i].piece == FNULL)
					return true;
				if (g_order == BEHAND)
				{
					if (Bord[x][i].piece == BLACK)
						continue;
					else
						return false;
				}
				else
				{
					if (Bord[x][i].piece == WHITE)
						continue;
					else
						return false;
				}
			}
		}
		return false;
	}

	case 2://右斜
	{
		int i, j;
		if (Bord[x + 1][y + 1].piece == FNULL)
		{
			i = x - 1;
			j = y - 1;
			while (i > x - 5 && i >= 0 && j > y - 5 && j >= 0)
			{
				if (Bord[i][j].piece == FNULL)
					return true;
				if (g_order == BEHAND)
				{
					if (Bord[i][j].piece == BLACK)
					{
						--i;
						--j;
						continue;
					}
					else
						return false;
				}
				else
				{
					if (Bord[i][j].piece == WHITE)
					{
						--i;
						--j;
						continue;
					}
					else
						return false;
				}
				--i;
				--j;
			}
		}
		else
		{
			i = x + 1;
			j = y + 1;
			while (i < x + 5 && i < 15 && j < y + 5 && j < 15)
			{
				if (Bord[i][j].piece == FNULL)
					return true;
				if (g_order == BEHAND)
				{
					if (Bord[i][j].piece == BLACK)
					{
						++i;
						++j;
						continue;
					}
					else
						return false;
				}
				else
				{
					if (Bord[i][j].piece == WHITE)
					{
						++i;
						++j;
						continue;
					}
					else
						return false;
				}
				++i;
				++j;
			}
		}
		return false;
	}

	case 3:
	{
		int i, j;
		if (Bord[x + 1][y - 1].piece == FNULL)
		{
			i = x - 1;
			j = y + 1;
			while (i > x - 5 && i >= 0 && j < y + 5 && j < 15)
			{
				if (Bord[i][j].piece == FNULL)
					return true;
				if (g_order == BEHAND)
				{
					if (Bord[i][j].piece == BLACK)
					{
						--i;
						++j;
						continue;
					}
					else
						return false;
				}
				else
				{
					if (Bord[i][j].piece == WHITE)
					{
						--i;
						++j;
						continue;
					}
					else
						return false;
				}
				--i;
				++j;
			}
		}
		else
		{
			i = x + 1;
			j = y - 1;
			while (i < x + 5 && i < 15 && j > y - 5 && j >= 0)
			{
				if (Bord[i][j].piece == FNULL)
					return true;
				if (g_order == BEHAND)
				{
					if (Bord[i][j].piece == BLACK)
					{
						++i;
						--j;
						continue;
					}
					else
						return false;
				}
				else
				{
					if (Bord[i][j].piece == WHITE)
					{
						++i;
						--j;
						continue;
					}
					else
						return false;
				}
				++i;
				--j;
			}
		}
		return false;
	}
	}//end swtch
	return false;
}

bool helper::Haveone(helper::PIECE_COLOR col)
{
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			if (Bord[i][j].piece == col)
				return true;
		}
	}
	return false;
}

//辅助函数，解决落子到已有棋子上出现棋子覆盖的情况
bool helper::IsValiablePoint(HWND hwnd,MyPoint& p)
{
	POINT pot;
	GetCursorPos(&pot);//获取鼠标在屏幕上的坐标
	ScreenToClient(hwnd, &pot);//将屏幕坐标转换为窗口坐标

	//将屏幕坐标转换成后台处理坐标
	int xr = (pot.x - 90) % 30;
	int yr = (pot.y - 90) % 30;
	int x = (pot.x - 90) / 30;
	int y = (pot.y - 90) / 30;
	if (xr >= 15)
		x += 1;
	if (yr >= 15)
		y += 1;

	if (x < 0 || x > 14 || y < 0 || y > 14)
		return false;
	if (Bord[x][y].piece != FNULL)
		return false;

	p.x = pot.x;
	p.y = pot.y;
	return true;
}