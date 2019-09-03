#include "SingleGame.h"
#include <ctime>

CSingleGame* CSingleGame::m_instance = new CSingleGame();

CSingleGame::CSingleGame() :CGame()
{
	m_nextpoint = { 0,0 };
	m_x = -1;
	m_y = -1;
	build_x = -1;
	build_y = -1;
	m_col = FNULL;
	m_first = true;
	m_build_count = 0;
	m_isbuild = false;
	m_act = ACT_NULL;
	m_connect = NONE;
}

CSingleGame::~CSingleGame()
{
	if (m_instance != NULL)
	{
		delete m_instance;
		m_instance = NULL;
	}
}

void CSingleGame::Judge()
{
	if (IsVector(IsFive(m_step, m_curcol)))//判断黑棋是否赢
	{
		m_redraw = true;
		CleanBord();//重置处理棋盘
		m_first = true;
		m_isbuild = false;
		m_build_count = 0;
		m_act = ACT_NULL;
		build_x = -1;
		build_y = -1;
		m_x = 0;
		m_y = 0;

		if (m_youcol == BLACK)
			m_turn = TURN_OF_YOU;
		else
			m_turn = TURN_OF_OTHER;
		m_curcol = FNULL;

		//将当前对局写入文件
		//

		m_list[0].erase(m_list[0].begin(), m_list[0].end());
		m_list[1].erase(m_list[1].begin(), m_list[1].end());
	}
}

CSingleGame* CSingleGame::GetInstance()
{
	return m_instance;
}

void CSingleGame::FindNextDown()
{
	m_nextpoint.x = 0;
	m_nextpoint.y = 0;
	int mydirect = -1;
	bool have_find = false;
	
	int barr[5] = { 0 };
	int warr[5] = { 0 };

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			barr[0] = GetTwobit(m_bord[i][j].black_connect, 0) + 1;//bh
			barr[1] = GetTwobit(m_bord[i][j].black_connect, 1) + 1;//bv
			barr[2] = GetTwobit(m_bord[i][j].black_connect, 2) + 1;//by
			barr[3] = GetTwobit(m_bord[i][j].black_connect, 3) + 1;//bz

			warr[0] = GetTwobit(m_bord[i][j].white_connect, 0) + 1;//wh
			warr[1] = GetTwobit(m_bord[i][j].white_connect, 1) + 1;//wv
			warr[2] = GetTwobit(m_bord[i][j].white_connect, 2) + 1;//wy
			warr[3] = GetTwobit(m_bord[i][j].white_connect, 3) + 1;//wz

			if (m_bord[i][j].piece != FNULL)
				continue;
			if (m_order == BEFORE)
			{
				if (Willfive(barr, mydirect))
				{
					Setnext(i, j);
					have_find = true;
					m_act = ACT_ATTACK;
					break;
				}
				else if (Willfive(warr, mydirect))
				{
					if (m_connect != WILL_5)
					{
						Setnext(i, j);
						m_connect = WILL_5;
						m_act = ACT_DEFENSE;
					}
					continue;
				}
				else if (IsActiveThree(barr, BLACK))
				{
					if ((int)m_connect < (int)M_ACTIVE_3)
					{
						Setnext(i, j);
						m_connect = M_ACTIVE_3;
						m_act = ACT_ATTACK;
					}
					continue;
				}
				else if (IsActiveThree(warr, WHITE))
				{
					if ((int)m_connect < (int)O_AVTIVE_3)
					{
						Setnext(i, j);
						m_connect = O_AVTIVE_3;
						m_act = ACT_DEFENSE;
					}
					continue;
				}
				else if (m_build_count == 0 && IsActiveTwo(barr, BLACK))
				{
					if ((int)m_connect < M_ACTIVE_2)
					{
						Setnext(i, j);
						m_connect = M_ACTIVE_2;
						m_act = ACT_ATTACK;
					}
					continue;
				}
				else if (m_bord[i][j].beffect && WillTow(barr, mydirect))
				{
					if ((int)m_connect < WILL_2)
					{
						m_connect = WILL_2;
						m_act = ACT_BUILD;
					}
					continue;
				}
				else
					continue;
			}
			else
			{
				if (Willfive(warr, mydirect))
				{
					Setnext(i, j);
					have_find = true;
					m_act = ACT_ATTACK;
					break;
				}
				else if (Willfive(barr, mydirect))
				{
					if (m_connect != WILL_5)
					{
						Setnext(i, j);
						m_connect = WILL_5;
						m_act = ACT_DEFENSE;
					}
					continue;
				}
				else if (IsActiveThree(warr,WHITE))
				{
					if ((int)m_connect < (int)M_ACTIVE_3)
					{
						Setnext(i, j);
						m_connect = M_ACTIVE_3;
						m_act = ACT_ATTACK;
					}
					continue;
				}
				else if (IsActiveThree(barr,BLACK))
				{
					if ((int)m_connect < (int)O_AVTIVE_3)
					{
						Setnext(i, j);
						m_connect = O_AVTIVE_3;
						m_act = ACT_DEFENSE;
					}
					continue;
				}
				else if (m_build_count == 0 && IsActiveTwo(warr,WHITE))
				{
					if ((int)m_connect < M_ACTIVE_2)
					{
						Setnext(i, j);
						m_connect = M_ACTIVE_2;
						m_act = ACT_ATTACK;
					}
					continue;
				}
				else if (m_bord[i][j].beffect && WillTow(warr, mydirect))
				{
					if ((int)m_connect < WILL_2)
					{
						m_connect = WILL_2;
						m_act = ACT_BUILD;
					}
					continue;
				}
				else
					continue;
			}
		}
		if (have_find)
		{
			break;
		}
	}
	m_connect = NONE;
}

void CSingleGame::FindBasepoint()
{
	GAME_DIRECTION dir = DIRECT_RIGHT;
	int bor_count = 0;
	int res_count = 8;
	for (int i = 0; i <= 7; ++i)
	{
		int border = 2 * i + 1;
		int x = 7 - i;
		int y = 7 - i;
		while (1)
		{
			if (dir == DIRECT_RIGHT)
			{
				bor_count++;
				if (m_bord[x][y].piece == m_col)
				{
					if (CountForPoint(x, y) < res_count)
					{
						build_x = x;
						build_y = y;
						res_count = CountForPoint(x, y);
					}
				}
				if (bor_count >= border)
				{
					dir = DIRECT_DOWN;
					bor_count = 0;
				}
				else
				{
					x++;
				}
			}
			else if (dir == DIRECT_DOWN)
			{
				bor_count++;
				if (m_bord[x][y].piece == m_col)
				{
					if (CountForPoint(x, y) < res_count)
					{
						build_x = x;
						build_y = y;
						res_count = CountForPoint(x, y);
					}
				}
				if (bor_count >= border)
				{
					dir = DIRECT_LEFT;
					bor_count = 0;
				}
				else
				{
					y++;
				}
			}
			else if (dir == DIRECT_LEFT)
			{
				bor_count++;
				if (m_bord[x][y].piece == m_col)
				{
					if (CountForPoint(x, y) < res_count)
					{
						build_x = x;
						build_y = y;
						res_count = CountForPoint(x, y);
					}
				}
				if (bor_count >= border)
				{
					dir = DIRECT_UP;
					border = 0;
				}
				else
				{
					x--;
				}
			}
			else if (dir == DIRECT_UP)
			{
				bor_count++;
				if (m_bord[x][y].piece == m_col)
				{
					if (CountForPoint(x, y) < res_count)
					{
						build_x = x;
						build_y = y;
						res_count = CountForPoint(x, y);
					}
				}
				if (bor_count >= border)
				{
					dir = DIRECT_RIGHT;
					break;
				}
				else
				{
					y--;
				}
			}
		}
	}
}

void CSingleGame::HandlePerEffect(const STEP& step,const PIECE_COLOR& col)
{
	bool have_empty = false;
	bool no_empty = false;
	int bordpoint_x = step.x;
	int bordpoint_y = step.y;
	int fc = -1;
	//处理黑棋的连珠情况
	//方向：0-横，1-竖，2-右斜，3-左斜
	//横向
	//先往右遍历
	for (int i = bordpoint_x; i < 15 && i < bordpoint_x + 5; ++i)
	{
		if (m_bord[i][bordpoint_y].piece == col)
		{
			fc++;
		}
		else if (m_bord[i][bordpoint_y].piece == FNULL)
		{
			if (i + 1 < 15 && m_bord[i + 1][bordpoint_y].piece == col)
			{
				have_empty = true;
				m_x = i; m_y = bordpoint_y;
			}
			else if (have_empty)
			{
				SetTwobitwithcol(m_bord[i][bordpoint_y], 0, i - m_x - 1,col);
				break;
			}
			else
			{
				no_empty = true;
				m_x = i; m_y = bordpoint_y;
				break;
			}
		}
		else
		{
			break;
		}
	}
	//在往左遍历
	for (int i = bordpoint_x; i >= 0 && i > bordpoint_x - 5; --i)
	{
		if (m_bord[i][bordpoint_y].piece == col)
		{
			fc++;
		}
		else if (m_bord[i][bordpoint_y].piece == FNULL)
		{
			if (have_empty)
			{
				SetTwobitwithcol(m_bord[i][bordpoint_y], 0, m_x - i - 1,col);
				SetTwobitwithcol(m_bord[m_x][m_y], 0, fc,col);
				fc = -1;
				have_empty = false;
				no_empty = false;
				break;
			}
			else if (i - 1 >= 0 && m_bord[i - 1][bordpoint_y].piece == col)
			{
				have_empty = true;
				if (no_empty)
				{
					SetTwobitwithcol(m_bord[m_x][m_y], 0, m_x - i - 1,col);
				}
				m_x = i; m_y = bordpoint_y;
			}
			else
			{
				if (no_empty)
				{
					SetTwobitwithcol(m_bord[m_x][m_y], 0, fc,col);
					SetTwobitwithcol(m_bord[i][bordpoint_y], 0, m_x - i - 1,col);
				}
				else
				{
					SetTwobitwithcol(m_bord[i][bordpoint_y], 0, fc,col);
				}
				//横向遍历结束，重置标志
				have_empty = false;
				no_empty = false;
				fc = -1;
				break;
			}
		}
		else
		{
			if (have_empty || no_empty)
			{
				SetTwobitwithcol(m_bord[m_x][m_y], 0, fc,col);
			}
			have_empty = false;
			no_empty = false;
			fc = -1;
			break;
		}
	}

	//竖向
	//先遍历上
	for (int i = bordpoint_y; i >= 0 && i > bordpoint_y - 5; --i)
	{
		if (m_bord[bordpoint_x][i].piece == col)
		{
			fc++;
		}
		else if (m_bord[bordpoint_x][i].piece == FNULL)
		{
			if (i - 1 >= 0 && m_bord[bordpoint_x][i - 1].piece == col)
			{
				have_empty = true;
				m_x = bordpoint_x; m_y = i;
			}
			else if (have_empty)
			{
				SetTwobitwithcol(m_bord[bordpoint_x][i], 1, m_y - i - 1,col);
				break;
			}
			else
			{
				no_empty = true;
				m_x = bordpoint_x; m_y = i;
				break;
			}
		}
		else
		{
			break;
		}
	}
	//再遍历下
	for (int i = bordpoint_y; i < 15 && i < bordpoint_y + 5; ++i)
	{
		if (m_bord[bordpoint_x][i].piece == col)
		{
			fc++;
		}
		else if (m_bord[bordpoint_x][i].piece == FNULL)
		{
			if (have_empty)
			{
				SetTwobitwithcol(m_bord[bordpoint_x][i], 1, i - m_y - 1,col);
				SetTwobitwithcol(m_bord[m_x][m_y], 1, fc,col);
				fc = -1;
				have_empty = false;
				no_empty = false;
				break;
			}
			else if (i + 1 < 15 && m_bord[bordpoint_x][i + 1].piece == col)
			{
				have_empty = true;
				if (no_empty)
				{
					SetTwobitwithcol(m_bord[m_x][m_y], 1, i - m_y - 1,col);
				}
				m_x = bordpoint_x; m_y = i;
			}
			else
			{
				if (no_empty)
				{
					SetTwobitwithcol(m_bord[bordpoint_x][i], 1, i - m_y - 1,col);
					SetTwobitwithcol(m_bord[m_x][m_y], 1, fc,col);
				}
				else
				{
					SetTwobitwithcol(m_bord[bordpoint_x][i], 1, fc,col);
				}
				have_empty = false;
				no_empty = false;
				fc = -1;
				break;
			}
		}
		else
		{
			if (have_empty || no_empty)
			{
				SetTwobitwithcol(m_bord[m_x][m_y], 1, fc,col);
			}
			have_empty = false;
			no_empty = false;
			fc = -1;
			break;
		}
	}

	//右斜
	int i = bordpoint_x;
	int j = bordpoint_y;
	while ((i >= 0 && i > bordpoint_x - 5) && (j >= 0 && j > bordpoint_y - 5))
	{
		if (m_bord[i][j].piece == col)
		{
			fc++;
			--i;
			--j;
		}
		else if (m_bord[i][j].piece == FNULL)
		{
			if ((i - 1 >= 0) && (j - 1 >= 0) && m_bord[i - 1][j - 1].piece == col)
			{
				have_empty = true;
				m_x = i; m_y = j;
			}
			else if (have_empty)
			{
				SetTwobitwithcol(m_bord[i][j], 2, m_x - i - 1,col);
				i = bordpoint_x;
				j = bordpoint_y;
				break;
			}
			else
			{
				no_empty = true;
				m_x = i; m_y = j;
				i = bordpoint_x;
				j = bordpoint_y;
				break;
			}
			--i;
			--j;
		}
		else
		{
			i = bordpoint_x;
			j = bordpoint_y;
			break;
		}
	}
	while ((i < 15 && i < bordpoint_x + 5) && (j < 15 && j < bordpoint_y + 5))
	{
		if (m_bord[i][j].piece == col)
		{
			fc++;
			i++;
			j++;
		}
		else if (m_bord[i][j].piece == FNULL)
		{
			if (have_empty)
			{
				SetTwobitwithcol(m_bord[i][j], 2, i - m_x - 1,col);
				SetTwobitwithcol(m_bord[m_x][m_y], 2, fc,col);
				fc = -1;
				have_empty = false;
				no_empty = false;
				i = bordpoint_x;
				j = bordpoint_y;
				break;
			}
			else if ((i + 1 < 15) && (j + 1 < 15) && m_bord[i + 1][j + 1].piece == col)
			{
				have_empty = true;
				if (no_empty)
				{
					SetTwobitwithcol(m_bord[m_x][m_y], 2, i - m_x - 1,col);
					m_x = i; m_y = j;
					i++;
					j++;
				}
			}
			else
			{
				if (no_empty)
				{
					SetTwobitwithcol(m_bord[i][j], 2, i - m_x - 1,col);
					SetTwobitwithcol(m_bord[m_x][m_y], 2, fc,col);
				}
				else
				{
					SetTwobitwithcol(m_bord[i][j], 2, fc,col);
				}
				have_empty = false;
				no_empty = false;
				fc = -1;
				i = bordpoint_x;
				j = bordpoint_y;
				break;
			}
		}
		else
		{
			if (have_empty || no_empty)
			{
				SetTwobitwithcol(m_bord[m_x][m_y], 2, fc,col);
			}
			have_empty = false;
			no_empty = false;
			fc = -1;
			i = bordpoint_x;
			j = bordpoint_y;
			break;
		}
	}

	//左斜
	while ((i >= 0 && i > bordpoint_x - 5) && (j < 15 && j < bordpoint_y + 5))
	{
		if (m_bord[i][j].piece == col)
		{
			fc++;
			i--;
			j++;
		}
		else if (m_bord[i][j].piece == FNULL)
		{
			if ((i - 1 >= 0) && (j + 1 < 15) && m_bord[i - 1][j + 1].piece == col)
			{
				have_empty = true;
				m_x = i; m_y = j;
			}
			else if (have_empty)
			{
				SetTwobitwithcol(m_bord[i][j], 3, m_x - i - 1,col);
				i = bordpoint_x;
				j = bordpoint_y;
				break;
			}
			else
			{
				no_empty = true;
				m_x = i; m_y = j;
				i = bordpoint_x;
				j = bordpoint_y;
				break;
			}
			i--;
			j++;
		}
		else
		{
			i = bordpoint_x;
			j = bordpoint_y;
			break;
		}
	}
	while ((i < 15 && i < bordpoint_x + 5) && (j >= 0 && j > bordpoint_y - 5))
	{
		if (m_bord[i][j].piece == col)
		{
			fc++;
			i++;
			j--;
		}
		else if (m_bord[i][j].piece == FNULL)
		{
			if (have_empty)
			{
				SetTwobitwithcol(m_bord[i][j], 3, i - m_x - 1,col);
				SetTwobitwithcol(m_bord[m_x][m_y], 3, fc,col);
				fc = -1;
				have_empty = false;
				no_empty = false;
				i = bordpoint_x;
				j = bordpoint_y;
				break;
			}
			else if ((i + 1 < 15) && (j - 1 >= 0) && m_bord[i + 1][j - 1].piece == col)
			{
				have_empty = true;
				if (no_empty)
				{
					SetTwobitwithcol(m_bord[m_x][m_y], 3, i - m_x - 1,col);
					m_x = i; m_y = j;
					i++;
					j--;
				}
			}
			else
			{
				if (no_empty)
				{
					SetTwobitwithcol(m_bord[i][j], 3, i - m_x - 1,col);
					SetTwobitwithcol(m_bord[m_x][m_y], 3, fc,col);
				}
				else
				{
					SetTwobitwithcol(m_bord[i][j], 3, fc,col);
				}
				have_empty = false;
				no_empty = false;
				fc = -1;
				i = bordpoint_x;
				j = bordpoint_y;
				break;
			}
		}
		else
		{
			if (have_empty || no_empty)
			{
				SetTwobitwithcol(m_bord[m_x][m_y], 3, fc,col);
			}
			have_empty = false;
			no_empty = false;
			fc = -1;
			i = bordpoint_x;
			j = bordpoint_y;
			break;
		}
	}
}

void CSingleGame::SetTwobitwithcol(BordPoint& p, int direct, int count, const PIECE_COLOR& curcol)
{
	if (curcol == BLACK)
	{
		SetTwobit(p.black_connect, direct, count);
		p.beffect = true;
	}
	else if (curcol == WHITE)
	{
		SetTwobit(p.white_connect, direct, count);
		p.weffect = true;
	}
	else
	{
		return;
	}
	return;
}

void CSingleGame::FindBuildnext()
{
	if (m_act == ACT_BUILD && m_build_count < 3)
	{
		if (!m_isbuild)
		{
			FindBasepoint();
			m_isbuild = true;
		}
		bool isfind = false;
		srand(time(0));
		while (!isfind)
		{
			isfind = Build(build_x, build_y, (GAME_DIRECTION)(rand() % 8 + 1));
		}
		m_build_count++;
	}
	if (m_build_count >= 3)
	{
		m_build_count = 0;
		m_isbuild = false;
		m_act = ACT_NULL;
	}
}

void CSingleGame::SetOrder(const ORDER_PUT& ord)
{
	m_order = ord;
	if (ord == BEFORE)
	{
		m_youcol = BLACK;
		m_col = WHITE;
	}
	else if (ord == BEHAND)
	{
		m_youcol = WHITE;
		m_col = BLACK;
	}
}

void CSingleGame::Setnext(const int a, const int b)
{
	m_nextpoint.x = a;
	m_nextpoint.y = b;
}

bool CSingleGame::Willfive(int* b, int& direct)
{
	for (int i = 0; i < 4; ++i)
	{
		if (b[i] == 4)
		{
			direct = i;
			return true;
		}
	}
	return false;
}

bool CSingleGame::Willfoandthr(int* b)
{
	int thr = 0;
	int four = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (b[i] == 2)
			thr++;
		else if (b[i] == 3)
		{
			four++;
		}
	}
	if (thr >= 1 && four >= 1)
		return true;
	return false;
}

bool CSingleGame::Willfour(int* b, int& direct)
{
	for (int i = 0; i < 4; ++i)
	{
		if (b[i] == 3)
		{
			direct = i;
			return true;
		}
	}
	return false;
}

bool CSingleGame::Willthrandthr(int* b)
{
	int count = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (b[i] == 2)
		{
			count++;
		}
	}
	if (count >= 2)
		return true;
	return false;
}

bool CSingleGame::Willthree(int* b, int& direct)
{
	for (int i = 0; i < 4; ++i)
	{
		if (b[i] == 2)
		{
			direct = i;
			return true;
		}
	}
	return false;
}

bool CSingleGame::WillTow(int* b, int& direct)
{

	for (int i = 0; i < 4; ++i)
	{
		if (b[i] == 1)
		{
			direct = i;
			return true;
		}
	}
	return false;
}

bool CSingleGame::Build(int x, int y, GAME_DIRECTION dir)
{
	int t_x;
	int t_y;
	switch (dir)
	{
	case DIRECT_UP:
		t_x = x;
		t_y = y - 1;
		break;
	case DIRECT_LEFT:
		t_x = x - 1;
		t_y = y;
		break;
	case DIRECT_DOWN:
		t_x = x;
		t_y = y + 1;
		break;
	case DIRECT_RIGHT:
		t_x = x + 1;
		t_y = y;
		break;
	case DIRECT_LEFT_UP:
		t_x = x - 1;
		t_y = y - 1;
		break;
	case DIRECT_RIGHT_UP:
		t_x = x + 1;
		t_y = y - 1;
		break;
	case DIRECT_LEFT_DOWN:
		t_x = x - 1;
		t_y = y + 1;
		break;
	case DIRECT_RIGHT_DOWN:
		t_x = x + 1;
		t_y = y + 1;
		break;
	}
	if (m_bord[t_x][t_y].piece == FNULL)
	{
		m_nextpoint.x = t_x;
		m_nextpoint.y = t_y;
		return true;
	}
	return false;
}

int CSingleGame::CountForPoint(int x, int y)
{
	int count = 0;
	if (m_bord[x - 1][y - 1].piece != FNULL && m_bord[x - 1][y - 1].piece != m_col)
	{
		count++;
	}
	if (m_bord[x][y - 1].piece != FNULL && m_bord[x][y - 1].piece != m_col)
	{
		count++;
	}
	if (m_bord[x + 1][y - 1].piece != FNULL && m_bord[x + 1][y - 1].piece != m_col)
	{
		count++;
	}
	if (m_bord[x + 1][y].piece != FNULL && m_bord[x + 1][y].piece != m_col)
	{
		count++;
	}
	if (m_bord[x + 1][y + 1].piece != FNULL && m_bord[x + 1][y + 1].piece != m_col)
	{
		count++;
	}
	if (m_bord[x][y + 1].piece != FNULL && m_bord[x][y + 1].piece != m_col)
	{
		count++;
	}
	if (m_bord[x - 1][y + 1].piece != FNULL && m_bord[x - 1][y + 1].piece != m_col)
	{
		count++;
	}
	if (m_bord[x - 1][y].piece != FNULL && m_bord[x - 1][y].piece != m_col)
	{
		count++;
	}
	return count;
}

int CSingleGame::GetTwobit(const int& ch, int direct)
{
	int res = (ch >> (direct * 2)) & 3;
	return res;
}

void CSingleGame::SetTwobit(char& ch, int direct, int count)
{
	//先判断当前方向上原有的值是否需要改变
	int tmp = GetTwobit(ch, direct);
	if (tmp > count - 1)
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

bool CSingleGame::Haveone(PIECE_COLOR col)
{
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			if (m_bord[i][j].piece == col)
				return true;
		}
	}
	return false;
}

bool CSingleGame::IsActiveThree(int* connarr, const PIECE_COLOR& col)
{
	int direct = -1;
	if (!Willfour(connarr, direct))
		return false;
	if (direct < 0)
		return false;
	switch (direct)
	{
	case 0://横向
	{
		int count = -1;
		for (int i = m_x; i < m_x + 5 && i < 15; ++i)
		{
			if (m_bord[i][m_y].piece == FNULL)
			{
				if (m_bord[i + 1][m_y].piece == FNULL)
				{
					count++;
					break;
				}
				else if (m_bord[i + 1][m_y].piece == col)
				{
					count++;
				}
				else
					return false;
			}
			else if (m_bord[i][m_y].piece == col)
				continue;
			else
				return false;
		}
		for (int i = m_x; i > 0 && i > m_x - 5; --i)
		{
			if (m_bord[i][m_y].piece == FNULL)
			{
				if (m_bord[i - 1][m_y].piece == FNULL)
				{
					count++;
					break;
				}
				else if (m_bord[i - 1][m_y].piece == col)
				{
					count++;
				}
				else
					return false;
			}
			else if (m_bord[i][m_y].piece == col)
				continue;
			else
				return false;
		}
		if (count >= 2)
			return true;
		return false;
	}

	case 1://竖向
	{
		int count = -1;
		for (int i = m_y; i < m_y + 5 && i < 15; ++i)
		{
			if (m_bord[m_x][i].piece == FNULL)
			{
				if (m_bord[m_x][i+1].piece == FNULL)
				{
					count++;
					break;
				}
				else if (m_bord[m_x][i+1].piece == col)
				{
					count++;
				}
				else
					return false;
			}
			else if (m_bord[m_x][i].piece == col)
				continue;
			else
				return false;
		}
		for (int i = m_y; i > 0 && i > m_y - 5; --i)
		{
			if (m_bord[m_x][i].piece == FNULL)
			{
				if (m_bord[m_x][i-1].piece == FNULL)
				{
					count++;
					break;
				}
				else if (m_bord[m_x][i-1].piece == col)
				{
					count++;
				}
				else
					return false;
			}
			else if (m_bord[m_x][i].piece == col)
				continue;
			else
				return false;
		}
		if (count >= 2)
			return true;
		return false;
	}

	case 2://右斜
	{
		int i = m_x;
		int j = m_y;
		int count = -1;
		while (i > 0 && i > i - 5 && j > 0 && j > j - 5)
		{
			if (m_bord[i][j].piece == FNULL)
			{
				if (m_bord[i - 1][j - 1].piece == FNULL)
				{
					count++;
					break;
				}
				else if (m_bord[i - 1][j - 1].piece == col)
				{
					count++;
					--i;
					--j;
				}
				else
					return false;
			}
			else if (m_bord[i][j].piece == col)
			{
				++i;
				++j;
				continue;
			}
			else
				return false;
		}
		i = m_x;
		j = m_y;
		while (i < i + 5 && i < 15 && j < j + 5 && j < 15)
		{
			if (m_bord[i][j].piece == FNULL)
			{
				if (m_bord[i + 1][j + 1].piece == FNULL)
				{
					count++;
					break;
				}
				else if (m_bord[i + 1][j + 1].piece == col)
				{
					count++;
					++i;
					++j;
				}
				else
					return false;
			}
			else if (m_bord[i][j].piece == col)
			{
				++i;
				++j;
				continue;
			}
			else
				return false;
		}

		if (count >= 2)
			return true;
		return false;
	}

	case 3:
	{
		int i = m_x;
		int j = m_y;
		int count = -1;
		while (i < 15 && i < i + 5 && j > 0 && j > j - 5)
		{
			if (m_bord[i][j].piece == FNULL)
			{
				if (m_bord[i + 1][j - 1].piece == FNULL)
				{
					count++;
					break;
				}
				else if (m_bord[i + 1][j - 1].piece == col)
				{
					count++;
					++i;
					--j;
				}
				else
					return false;
			}
			else if (m_bord[i][j].piece == col)
			{
				++i;
				--j;
				continue;
			}
			else
				return false;
		}

		i = m_x;
		j = m_y;
		while (i > 0 && i > i - 5 && j < 15 && j < j + 5)
		{
			if (m_bord[i][j].piece == FNULL)
			{
				if (m_bord[i - 1][j + 1].piece == FNULL)
				{
					count++;
					break;
				}
				else if (m_bord[i - 1][j + 1].piece == col)
				{
					count++;
					--i;
					++j;
				}
				else
					return false;
			}
			else if (m_bord[i][j].piece == col)
			{
				--i;
				++j;
				continue;
			}
			else
				return false;
		}

		if (count >= 2)
			return true;
		return false;
	}

	default:
		return false;
	}//end swtch
	return false;
}

bool CSingleGame::IschongThree(int* connarr, const PIECE_COLOR& col)
{
	int direct = -1;
	if (Willfour(connarr, direct) && !IsActiveThree(connarr, col))
		return true;
	return false;
}

bool CSingleGame::IsActiveTwo(int * connarr, const PIECE_COLOR& col)
{
	int direct = -1;
	if (!Willthree(connarr, direct))
		return false;
	if (direct < 0)
		return false;
	switch (direct)
	{
	case 0://横向
	{
		int count = -1;
		for (int i = m_x; i < m_x + 4 && i < 15; ++i)
		{
			if (m_bord[i][m_y].piece == FNULL)
			{
				if (m_bord[i + 1][m_y].piece == FNULL)
				{
					count++;
					break;
				}
				else if (m_bord[i + 1][m_y].piece == col)
				{
					count++;
				}
				else
					return false;
			}
			else if (m_bord[i][m_y].piece == col)
				continue;
			else
				return false;
		}
		for (int i = m_x; i > 0 && i > m_x - 4; --i)
		{
			if (m_bord[i][m_y].piece == FNULL)
			{
				if (m_bord[i - 1][m_y].piece == FNULL)
				{
					count++;
					break;
				}
				else if (m_bord[i - 1][m_y].piece == col)
				{
					count++;
				}
				else
					return false;
			}
			else if (m_bord[i][m_y].piece == col)
				continue;
			else
				return false;
		}
		if (count >= 2)
			return true;
		return false;
	}

	case 1://竖向
	{
		int count = -1;
		for (int i = m_y; i < m_y + 4 && i < 15; ++i)
		{
			if (m_bord[m_x][i].piece == FNULL)
			{
				if (m_bord[m_x][i + 1].piece == FNULL)
				{
					count++;
					break;
				}
				else if (m_bord[m_x][i + 1].piece == col)
				{
					count++;
				}
				else
					return false;
			}
			else if (m_bord[m_x][i].piece == col)
				continue;
			else
				return false;
		}
		for (int i = m_y; i > 0 && i > m_y - 4; --i)
		{
			if (m_bord[m_x][i].piece == FNULL)
			{
				if (m_bord[m_x][i - 1].piece == FNULL)
				{
					count++;
					break;
				}
				else if (m_bord[m_x][i - 1].piece == col)
				{
					count++;
				}
				else
					return false;
			}
			else if (m_bord[m_x][i].piece == col)
				continue;
			else
				return false;
		}
		if (count >= 2)
			return true;
		return false;
	}

	case 2://右斜
	{
		int i = m_x;
		int j = m_y;
		int count = -1;
		while (i > 0 && i > i - 4 && j > 0 && j > j - 4)
		{
			if (m_bord[i][j].piece == FNULL)
			{
				if (m_bord[i - 1][j - 1].piece == FNULL)
				{
					count++;
					break;
				}
				else if (m_bord[i - 1][j - 1].piece == col)
				{
					count++;
					--i;
					--j;
				}
				else
					return false;
			}
			else if (m_bord[i][j].piece == col)
			{
				++i;
				++j;
				continue;
			}
			else
				return false;
		}
		i = m_x;
		j = m_y;
		while (i < i + 4 && i < 15 && j < j + 4 && j < 15)
		{
			if (m_bord[i][j].piece == FNULL)
			{
				if (m_bord[i + 1][j + 1].piece == FNULL)
				{
					count++;
					break;
				}
				else if (m_bord[i + 1][j + 1].piece == col)
				{
					count++;
					++i;
					++j;
				}
				else
					return false;
			}
			else if (m_bord[i][j].piece == col)
			{
				++i;
				++j;
				continue;
			}
			else
				return false;
		}

		if (count >= 2)
			return true;
		return false;
	}

	case 3:
	{
		int i = m_x;
		int j = m_y;
		int count = -1;
		while (i < 15 && i < i + 4 && j > 0 && j > j - 4)
		{
			if (m_bord[i][j].piece == FNULL)
			{
				if (m_bord[i + 1][j - 1].piece == FNULL)
				{
					count++;
					break;
				}
				else if (m_bord[i + 1][j - 1].piece == col)
				{
					count++;
					++i;
					--j;
				}
				else
					return false;
			}
			else if (m_bord[i][j].piece == col)
			{
				++i;
				--j;
				continue;
			}
			else
				return false;
		}

		i = m_x;
		j = m_y;
		while (i > 0 && i > i - 4 && j < 15 && j < j + 4)
		{
			if (m_bord[i][j].piece == FNULL)
			{
				if (m_bord[i - 1][j + 1].piece == FNULL)
				{
					count++;
					break;
				}
				else if (m_bord[i - 1][j + 1].piece == col)
				{
					count++;
					--i;
					++j;
				}
				else
					return false;
			}
			else if (m_bord[i][j].piece == col)
			{
				--i;
				++j;
				continue;
			}
			else
				return false;
		}

		if (count >= 2)
			return true;
		return false;
	}

	default:
		return false;
	}//end swtch
	return false;
}

bool CSingleGame::IschongTwo(int* connarr, const PIECE_COLOR& col)
{
	int direct = -1;
	if (Willthree(connarr, direct) && !IsActiveTwo(connarr, col))
		return true;
	return false;
}

void CSingleGame::SetCurTurn()
{
	if (m_turn == TURN_OF_YOU)
	{
		m_turn = TURN_OF_OTHER;
		m_curcol = m_col;
	}
	else if (m_turn == TURN_OF_OTHER)
	{
		m_turn = TURN_OF_YOU;
		m_curcol = m_youcol;
	}
	else
		return;
}