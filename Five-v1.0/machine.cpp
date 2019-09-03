#include "machine.h"
int CMachine::m_x = -1;
int CMachine::m_y = -1;
int CMachine::build_x = -1;
int CMachine::build_y = -1;
int CMachine::m_build_count = 0;
helper::DEGREE_DIFFICULT CMachine::m_degree = helper::FDIFFICULT;//静态私有成员可在.cpp文件中初始化
helper::MyPoint CMachine::m_nextpoint;
COLORREF CMachine::m_col;
bool CMachine::m_first = true;
bool CMachine::m_isbuild = false;
MACHINE_ACT CMachine::m_act = ACT_NULL;

extern helper::GAME_TURN g_turn;
extern helper::CURRENT_CONNECT g_connect;
extern helper::ORDER_PUT g_order;

CMachine::CMachine() {
	m_nextpoint.x = 7;
	m_nextpoint.y = 7;
	if (g_order == helper::BEFORE)
		m_col = RGB(0, 0, 0);
	else
		m_col = RGB(255, 255, 255);
}

CMachine::~CMachine(){}

//重新处理.......
//修改数据结构，同时设置四个方向时考虑边界情况
//每下一颗棋子，处理四个方向被它影响的空格的连接标志,传递的参数必须是规范化的
//处理棋盘每一个格子总包含一个白棋连珠与一个黑棋连珠情况，且都是char类型，规定：char的四个位
//从右往左依次标记为1 to 4，esay级别的处理
void CMachine::HandlePerEffect(const helper::MyPoint& pot) //pot为当前所下的棋子
{
	if (m_degree == helper::FEASY)
	{
		bool have_empty = false;
		bool no_empty = false;
		int bordpoint_x = (pot.x - 90) / 30;
		int bordpoint_y = (pot.y - 90) / 30;
		int fc = -1;
		//处理黑棋的连珠情况
		if (pot.col == RGB(0, 0, 0))
		{
			//横向
			//先往右遍历
			for (int i = bordpoint_x; i < 15 && i < bordpoint_x + 5; ++i)
			{
				if (IsSameColor(Bord[i][bordpoint_y].piece, pot.col))
				{
					fc++;
				}
				else if (Bord[i][bordpoint_y].piece == helper::FNULL)
				{
					if (i + 1 < 15 && IsSameColor(Bord[i + 1][bordpoint_y].piece, pot.col))
					{
						have_empty = true;
						m_x = i; m_y = bordpoint_y;
					}
					else if (have_empty)
					{
						helper::SetOne(Bord[i][bordpoint_y].black_connect, i - m_x - 1);
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
				if (IsSameColor(Bord[i][bordpoint_y].piece, pot.col))
				{
					fc++;
				}
				else if (Bord[i][bordpoint_y].piece == helper::FNULL)
				{
					if (have_empty)
					{
						helper::SetOne(Bord[i][bordpoint_y].black_connect, m_x - i - 1);
						helper::SetOne(Bord[m_x][m_y].black_connect, fc);
						fc = -1;
						have_empty = false;
						no_empty = false;
						break;
					}
					else if (i - 1 >= 0 && IsSameColor(Bord[i - 1][bordpoint_y].piece, pot.col))
					{
						have_empty = true;
						if (no_empty)
						{
							helper::SetOne(Bord[m_x][m_y].black_connect, m_x - i - 1);
						}
						m_x = i; m_y = bordpoint_y;
					}
					else
					{
						if (no_empty)
						{
							helper::SetOne(Bord[m_x][m_y].black_connect, fc);
							helper::SetOne(Bord[i][bordpoint_y].black_connect, m_x - i - 1);
						}
						else
						{
							helper::SetOne(Bord[i][bordpoint_y].black_connect, fc);
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
						helper::SetOne(Bord[m_x][m_y].black_connect, fc);
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
				if (IsSameColor(Bord[bordpoint_x][i].piece, pot.col))
				{
					fc++;
				}
				else if (Bord[bordpoint_x][i].piece == helper::FNULL)
				{
					if (i - 1 >= 0 && IsSameColor(Bord[bordpoint_x][i - 1].piece, pot.col))
					{
						have_empty = true;
						m_x = bordpoint_x; m_y = i;
					}
					else if (have_empty)
					{
						helper::SetOne(Bord[bordpoint_x][i].black_connect, m_y - i - 1);
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
				if (IsSameColor(Bord[bordpoint_x][i].piece, pot.col))
				{
					fc++;
				}
				else if (Bord[bordpoint_x][i].piece == helper::FNULL)
				{
					if (have_empty)
					{
						helper::SetOne(Bord[bordpoint_x][i].black_connect, i - m_y - 1);
						helper::SetOne(Bord[m_x][m_y].black_connect, fc);
						fc = -1;
						have_empty = false;
						no_empty = false;
						break;
					}
					else if (i + 1 < 15 && IsSameColor(Bord[bordpoint_x][i + 1].piece, pot.col))
					{
						have_empty = true;
						if (no_empty)
						{
							helper::SetOne(Bord[m_x][m_y].black_connect, i - m_y - 1);
						}
						m_x = bordpoint_x; m_y = i;
					}
					else
					{
						if (no_empty)
						{
							helper::SetOne(Bord[bordpoint_x][i].black_connect, i - m_y - 1);
							helper::SetOne(Bord[m_x][m_y].black_connect, fc);
						}
						else
						{
							helper::SetOne(Bord[bordpoint_x][i].black_connect, fc);
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
						helper::SetOne(Bord[m_x][m_y].black_connect, fc);
					}
					have_empty = false;
					no_empty = false;
					fc = -1;
					break;
				}
			}

			//左斜
			int i = bordpoint_x;
			int j = bordpoint_y;
			while ((i >= 0 && i > bordpoint_x - 5) && (j >= 0 && j > bordpoint_y - 5))
			{
				if (IsSameColor(Bord[i][j].piece, pot.col))
				{
					fc++;
					--i;
					--j;
				}
				else if (Bord[i][j].piece == helper::FNULL)
				{
					if ((i - 1 >= 0) && (j - 1 >= 0) && IsSameColor(Bord[i - 1][j - 1].piece, pot.col))
					{
						have_empty = true;
						m_x = i; m_y = j;
					}
					else if (have_empty)
					{
						helper::SetOne(Bord[i][j].black_connect, m_x - i - 1);
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
				if (IsSameColor(Bord[i][j].piece, pot.col))
				{
					fc++;
					i++;
					j++;
				}
				else if (Bord[i][j].piece == helper::FNULL)
				{
					if (have_empty)
					{
						helper::SetOne(Bord[i][j].black_connect, i - m_x - 1);
						helper::SetOne(Bord[m_x][m_y].black_connect, fc);
						fc = -1;
						have_empty = false;
						no_empty = false;
						i = bordpoint_x;
						j = bordpoint_y;
						break;
					}
					else if ((i + 1 < 15) && (j + 1 < 15) && IsSameColor(Bord[i + 1][j - 1].piece, pot.col))
					{
						have_empty = true;
						if (no_empty)
						{
							helper::SetOne(Bord[m_x][m_y].black_connect, i - m_x - 1);
							m_x = i; m_y = j;
						}
					}
					else
					{
						if (no_empty)
						{
							helper::SetOne(Bord[i][j].black_connect, i - m_x - 1);
							helper::SetOne(Bord[m_x][m_y].black_connect, fc);
						}
						else
						{
							helper::SetOne(Bord[i][j].black_connect, fc);
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
						helper::SetOne(Bord[m_x][m_y].black_connect, fc);
					}
					have_empty = false;
					no_empty = false;
					fc = -1;
					i = bordpoint_x;
					j = bordpoint_y;
					break;
				}
			}

			//右斜
			while ((i >= 0 && i > bordpoint_x - 5) && (j < 15 && j < bordpoint_y + 5))
			{
				if (IsSameColor(Bord[i][j].piece, pot.col))
				{
					fc++;
					i--;
					j++;
				}
				else if (Bord[i][j].piece == helper::FNULL)
				{
					if ((i - 1 >= 0) && (j + 1 < 15) && IsSameColor(Bord[i - 1][j + 1].piece, pot.col))
					{
						have_empty = true;
						m_x = i; m_y = j;
					}
					else if (have_empty)
					{
						helper::SetOne(Bord[i][j].black_connect, m_x - i - 1);
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
				if (IsSameColor(Bord[i][j].piece, pot.col))
				{
					fc++;
					i++;
					j--;
				}
				else if (Bord[i][j].piece == helper::FNULL)
				{
					if (have_empty)
					{
						helper::SetOne(Bord[i][j].black_connect, i - m_x - 1);
						helper::SetOne(Bord[m_x][m_y].black_connect, fc);
						fc = -1;
						have_empty = false;
						no_empty = false;
						i = bordpoint_x;
						j = bordpoint_y;
						break;
					}
					else if ((i + 1 < 15) && (j - 1 >= 0) && IsSameColor(Bord[i + 1][j - 1].piece, pot.col))
					{
						have_empty = true;
						if (no_empty)
						{
							helper::SetOne(Bord[m_x][m_y].black_connect, i - m_x - 1);
							m_x = i; m_y = j;
						}
					}
					else
					{
						if (no_empty)
						{
							helper::SetOne(Bord[i][j].black_connect, i - m_x - 1);
							helper::SetOne(Bord[m_x][m_y].black_connect, fc);
						}
						else
						{
							helper::SetOne(Bord[i][j].black_connect, fc);
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
						helper::SetOne(Bord[m_x][m_y].black_connect, fc);
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
		//处理白棋的连珠情况
		else
		{
			//横向
			//先往右遍历
			for (int i = bordpoint_x; i < 15 && i < bordpoint_x + 5; ++i)
			{
				if (IsSameColor(Bord[i][bordpoint_y].piece, pot.col))
				{
					fc++;
				}
				else if (Bord[i][bordpoint_y].piece == helper::FNULL)
				{
					if (i + 1 < 15 && IsSameColor(Bord[i + 1][bordpoint_y].piece, pot.col))
					{
						have_empty = true;
						m_x = i; m_y = bordpoint_y;
					}
					else if (have_empty)
					{
						helper::SetOne(Bord[i][bordpoint_y].white_connect, i - m_x - 1);
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
				if (IsSameColor(Bord[i][bordpoint_y].piece, pot.col))
				{
					fc++;
				}
				else if (Bord[i][bordpoint_y].piece == helper::FNULL)
				{
					if (have_empty)
					{
						helper::SetOne(Bord[i][bordpoint_y].white_connect, m_x - i - 1);
						helper::SetOne(Bord[m_x][m_y].white_connect, fc);
						fc = -1;
						have_empty = false;
						no_empty = false;
						break;
					}
					else if (i - 1 >= 0 && IsSameColor(Bord[i - 1][bordpoint_y].piece, pot.col))
					{
						have_empty = true;
						if (no_empty)
						{
							helper::SetOne(Bord[m_x][m_y].white_connect, m_x - i - 1);
						}
						m_x = i; m_y = bordpoint_y;
					}
					else
					{
						if (no_empty)
						{
							helper::SetOne(Bord[m_x][m_y].white_connect, fc);
							helper::SetOne(Bord[i][bordpoint_y].white_connect, m_x - i - 1);
						}
						else
						{
							helper::SetOne(Bord[i][bordpoint_y].white_connect, fc);
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
						helper::SetOne(Bord[m_x][m_y].white_connect, fc);
					}
					have_empty = false;
					no_empty = false;
					fc = -1;
					break;
				}
			}
			//
			have_empty = false;
			no_empty = false;
			fc = -1;

			//竖向
			//先遍历上
			for (int i = bordpoint_y; i >= 0 && i > bordpoint_y - 5; --i)
			{
				if (IsSameColor(Bord[bordpoint_x][i].piece, pot.col))
				{
					fc++;
				}
				else if (Bord[bordpoint_x][i].piece == helper::FNULL)
				{
					if (i - 1 >= 0 && IsSameColor(Bord[bordpoint_x][i - 1].piece, pot.col))
					{
						have_empty = true;
						m_x = bordpoint_x; m_y = i;
					}
					else if (have_empty)
					{
						helper::SetOne(Bord[bordpoint_x][i].white_connect, m_y - i - 1);
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
				if (IsSameColor(Bord[bordpoint_x][i].piece, pot.col))
				{
					fc++;
				}
				else if (Bord[bordpoint_x][i].piece == helper::FNULL)
				{
					if (have_empty)
					{
						helper::SetOne(Bord[bordpoint_x][i].white_connect, i - m_y - 1);
						helper::SetOne(Bord[m_x][m_y].white_connect, fc);
						fc = -1;
						have_empty = false;
						no_empty = false;
						break;
					}
					else if (i + 1 < 15 && IsSameColor(Bord[bordpoint_x][i + 1].piece, pot.col))
					{
						have_empty = true;
						if (no_empty)
						{
							helper::SetOne(Bord[m_x][m_y].white_connect, i - m_y - 1);
						}
						m_x = bordpoint_x; m_y = i;
					}
					else
					{
						if (no_empty)
						{
							helper::SetOne(Bord[bordpoint_x][i].white_connect, i - m_y - 1);
							helper::SetOne(Bord[m_x][m_y].white_connect, fc);
						}
						else
						{
							helper::SetOne(Bord[bordpoint_x][i].white_connect, fc);
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
						helper::SetOne(Bord[m_x][m_y].white_connect, fc);
					}
					have_empty = false;
					no_empty = false;
					fc = -1;
					break;
				}
			}
			//
			have_empty = false;
			no_empty = false;
			fc = -1;
			//左斜
			int i = bordpoint_x;
			int j = bordpoint_y;
			while ((i >= 0 && i > bordpoint_x - 5) && (j >= 0 && j > bordpoint_y - 5))
			{
				if (IsSameColor(Bord[i][j].piece, pot.col))
				{
					fc++;
					--i;
					--j;
				}
				else if (Bord[i][j].piece == helper::FNULL)
				{
					if ((i - 1 >= 0) && (j - 1 >= 0) && IsSameColor(Bord[i - 1][j - 1].piece, pot.col))
					{
						have_empty = true;
						m_x = i; m_y = j;
					}
					else if (have_empty)
					{
						helper::SetOne(Bord[i][j].white_connect, m_x - i - 1);
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
				if (IsSameColor(Bord[i][j].piece, pot.col))
				{
					fc++;
					i++;
					j++;
				}
				else if (Bord[i][j].piece == helper::FNULL)
				{
					if (have_empty)
					{
						helper::SetOne(Bord[i][j].white_connect, i - m_x - 1);
						helper::SetOne(Bord[m_x][m_y].white_connect, fc);
						fc = -1;
						have_empty = false;
						no_empty = false;
						i = bordpoint_x;
						j = bordpoint_y;
						break;
					}
					else if ((i + 1 < 15) && (j + 1 < 15) && IsSameColor(Bord[i + 1][j - 1].piece, pot.col))
					{
						have_empty = true;
						if (no_empty)
						{
							helper::SetOne(Bord[m_x][m_y].white_connect, i - m_x - 1);
							m_x = i; m_y = j;
						}
					}
					else
					{
						if (no_empty)
						{
							helper::SetOne(Bord[i][j].white_connect, i - m_x - 1);
							helper::SetOne(Bord[m_x][m_y].white_connect, fc);
						}
						else
						{
							helper::SetOne(Bord[i][j].white_connect, fc);
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
						helper::SetOne(Bord[m_x][m_y].white_connect, fc);
					}
					have_empty = false;
					no_empty = false;
					fc = -1;
					i = bordpoint_x;
					j = bordpoint_y;
					break;
				}
			}
			//
			have_empty = false;
			no_empty = false;
			fc = -1;
			i = bordpoint_x;
			j = bordpoint_y;
			//右斜
			while ((i >= 0 && i > bordpoint_x - 5) && (j < 15 && j < bordpoint_y + 5))
			{
				if (IsSameColor(Bord[i][j].piece, pot.col))
				{
					fc++;
					i--;
					j++;
				}
				else if (Bord[i][j].piece == helper::FNULL)
				{
					if ((i - 1 >= 0) && (j + 1 < 15) && IsSameColor(Bord[i - 1][j + 1].piece, pot.col))
					{
						have_empty = true;
						m_x = i; m_y = j;
					}
					else if (have_empty)
					{
						helper::SetOne(Bord[i][j].white_connect, m_x - i - 1);
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
				if (IsSameColor(Bord[i][j].piece, pot.col))
				{
					fc++;
					i++;
					j--;
				}
				else if (Bord[i][j].piece == helper::FNULL)
				{
					if (have_empty)
					{
						helper::SetOne(Bord[i][j].white_connect, i - m_x - 1);
						helper::SetOne(Bord[m_x][m_y].white_connect, fc);
						fc = -1;
						have_empty = false;
						no_empty = false;
						i = bordpoint_x;
						j = bordpoint_y;
						break;
					}
					else if ((i + 1 < 15) && (j - 1 >= 0) && IsSameColor(Bord[i + 1][j - 1].piece, pot.col))
					{
						have_empty = true;
						if (no_empty)
						{
							helper::SetOne(Bord[m_x][m_y].white_connect, i - m_x - 1);
							m_x = i; m_y = j;
						}
					}
					else
					{
						if (no_empty)
						{
							helper::SetOne(Bord[i][j].white_connect, i - m_x - 1);
							helper::SetOne(Bord[m_x][m_y].white_connect, fc);
						}
						else
						{
							helper::SetOne(Bord[i][j].white_connect, fc);
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
						helper::SetOne(Bord[m_x][m_y].white_connect, fc);
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
	}
	else if (m_degree == helper::FDIFFICULT)
	{
		bool have_empty = false;
		bool no_empty = false;
		int bordpoint_x = (pot.x - 90) / 30;
		int bordpoint_y = (pot.y - 90) / 30;
		int fc = -1;
		//处理黑棋的连珠情况
		//方向：0-横，1-竖，2-右斜，3-左斜
		if (pot.col == RGB(0, 0, 0))
		{
			//横向
			//先往右遍历
			for (int i = bordpoint_x; i < 15 && i < bordpoint_x + 5; ++i)
			{
				if (IsSameColor(Bord[i][bordpoint_y].piece, pot.col))
				{
					fc++;
				}
				else if (Bord[i][bordpoint_y].piece == helper::FNULL)
				{
					if (i + 1 < 15 && IsSameColor(Bord[i + 1][bordpoint_y].piece, pot.col))
					{
						have_empty = true;
						m_x = i; m_y = bordpoint_y;
					}
					else if (have_empty)
					{
						helper::SetTwobit(Bord[i][bordpoint_y].black_connect,0, i - m_x - 1);
						Bord[i][bordpoint_y].beffect = true;
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
				if (IsSameColor(Bord[i][bordpoint_y].piece, pot.col))
				{
					fc++;
				}
				else if (Bord[i][bordpoint_y].piece == helper::FNULL)
				{
					if (have_empty)
					{
						helper::SetTwobit(Bord[i][bordpoint_y].black_connect, 0,m_x - i - 1);
						helper::SetTwobit(Bord[m_x][m_y].black_connect,0, fc);
						Bord[i][bordpoint_y].beffect = true;
						Bord[m_x][m_y].beffect = true;
						fc = -1;
						have_empty = false;
						no_empty = false;
						break;
					}
					else if (i - 1 >= 0 && IsSameColor(Bord[i - 1][bordpoint_y].piece, pot.col))
					{
						have_empty = true;
						if (no_empty)
						{
							helper::SetTwobit(Bord[m_x][m_y].black_connect,0, m_x - i - 1);
							Bord[m_x][m_y].beffect = true;
						}
						m_x = i; m_y = bordpoint_y;
					}
					else
					{
						if (no_empty)
						{
							helper::SetTwobit(Bord[m_x][m_y].black_connect,0, fc);
							helper::SetTwobit(Bord[i][bordpoint_y].black_connect,0, m_x - i - 1);
							Bord[m_x][m_y].beffect = true;
							Bord[i][bordpoint_y].beffect = true;
						}
						else
						{
							helper::SetTwobit(Bord[i][bordpoint_y].black_connect,0, fc);
							Bord[i][bordpoint_y].beffect = true;
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
						helper::SetTwobit(Bord[m_x][m_y].black_connect,0, fc);
						Bord[m_x][m_y].beffect = true;
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
				if (IsSameColor(Bord[bordpoint_x][i].piece, pot.col))
				{
					fc++;
				}
				else if (Bord[bordpoint_x][i].piece == helper::FNULL)
				{
					if (i - 1 >= 0 && IsSameColor(Bord[bordpoint_x][i - 1].piece, pot.col))
					{
						have_empty = true;
						m_x = bordpoint_x; m_y = i;
					}
					else if (have_empty)
					{
						helper::SetTwobit(Bord[bordpoint_x][i].black_connect,1, m_y - i - 1);
						Bord[bordpoint_x][i].beffect = true;
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
				if (IsSameColor(Bord[bordpoint_x][i].piece, pot.col))
				{
					fc++;
				}
				else if (Bord[bordpoint_x][i].piece == helper::FNULL)
				{
					if (have_empty)
					{
						helper::SetTwobit(Bord[bordpoint_x][i].black_connect,1, i - m_y - 1);
						helper::SetTwobit(Bord[m_x][m_y].black_connect,1, fc);
						Bord[bordpoint_x][i].beffect = true;
						Bord[m_x][m_y].beffect = true;
						fc = -1;
						have_empty = false;
						no_empty = false;
						break;
					}
					else if (i + 1 < 15 && IsSameColor(Bord[bordpoint_x][i + 1].piece, pot.col))
					{
						have_empty = true;
						if (no_empty)
						{
							helper::SetTwobit(Bord[m_x][m_y].black_connect,1, i - m_y - 1);
							Bord[m_x][m_y].beffect = true;
						}
						m_x = bordpoint_x; m_y = i;
					}
					else
					{
						if (no_empty)
						{
							helper::SetTwobit(Bord[bordpoint_x][i].black_connect,1, i - m_y - 1);
							helper::SetTwobit(Bord[m_x][m_y].black_connect,1, fc);
							Bord[bordpoint_x][i].beffect = true;
							Bord[m_x][m_y].beffect = true;
						}
						else
						{
							helper::SetTwobit(Bord[bordpoint_x][i].black_connect,1, fc);
							Bord[bordpoint_x][i].beffect = true;
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
						helper::SetTwobit(Bord[m_x][m_y].black_connect,1, fc);
						Bord[m_x][m_y].beffect = true;
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
				if (IsSameColor(Bord[i][j].piece, pot.col))
				{
					fc++;
					--i;
					--j;
				}
				else if (Bord[i][j].piece == helper::FNULL)
				{
					if ((i - 1 >= 0) && (j - 1 >= 0) && IsSameColor(Bord[i - 1][j - 1].piece, pot.col))
					{
						have_empty = true;
						m_x = i; m_y = j;
					}
					else if (have_empty)
					{
						helper::SetTwobit(Bord[i][j].black_connect,2, m_x - i - 1);
						Bord[i][j].beffect = true;
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
				if (IsSameColor(Bord[i][j].piece, pot.col))
				{
					fc++;
					i++;
					j++;
				}
				else if (Bord[i][j].piece == helper::FNULL)
				{
					if (have_empty)
					{
						helper::SetTwobit(Bord[i][j].black_connect,2, i - m_x - 1);
						Bord[i][j].beffect = true;
						helper::SetTwobit(Bord[m_x][m_y].black_connect,2, fc);
						Bord[m_x][m_y].beffect = true;
						fc = -1;
						have_empty = false;
						no_empty = false;
						i = bordpoint_x;
						j = bordpoint_y;
						break;
					}
					else if ((i + 1 < 15) && (j + 1 < 15) && IsSameColor(Bord[i + 1][j + 1].piece, pot.col))
					{
						have_empty = true;
						if (no_empty)
						{
							helper::SetTwobit(Bord[m_x][m_y].black_connect,2, i - m_x - 1);
							Bord[m_x][m_y].beffect = true;//意思是受到黑棋影响
							m_x = i; m_y = j;
							i++;
							j++;
						}
					}
					else
					{
						if (no_empty)
						{
							helper::SetTwobit(Bord[i][j].black_connect,2, i - m_x - 1);
							helper::SetTwobit(Bord[m_x][m_y].black_connect,2, fc);
							Bord[i][j].beffect = true;
							Bord[m_x][m_y].beffect = true;
						}
						else
						{
							helper::SetTwobit(Bord[i][j].black_connect,2, fc);
							Bord[i][j].beffect = true;
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
						helper::SetTwobit(Bord[m_x][m_y].black_connect,2, fc);
						Bord[m_x][m_y].beffect = true;
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
				if (IsSameColor(Bord[i][j].piece, pot.col))
				{
					fc++;
					i--;
					j++;
				}
				else if (Bord[i][j].piece == helper::FNULL)
				{
					if ((i - 1 >= 0) && (j + 1 < 15) && IsSameColor(Bord[i - 1][j + 1].piece, pot.col))
					{
						have_empty = true;
						m_x = i; m_y = j;
					}
					else if (have_empty)
					{
						helper::SetTwobit(Bord[i][j].black_connect,3, m_x - i - 1);
						Bord[i][j].beffect = true;
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
				if (IsSameColor(Bord[i][j].piece, pot.col))
				{
					fc++;
					i++;
					j--;
				}
				else if (Bord[i][j].piece == helper::FNULL)
				{
					if (have_empty)
					{
						helper::SetTwobit(Bord[i][j].black_connect,3, i - m_x - 1);
						helper::SetTwobit(Bord[m_x][m_y].black_connect,3, fc);
						Bord[i][j].beffect = true;
						Bord[m_x][m_y].beffect = true;
						fc = -1;
						have_empty = false;
						no_empty = false;
						i = bordpoint_x;
						j = bordpoint_y;
						break;
					}
					else if ((i + 1 < 15) && (j - 1 >= 0) && IsSameColor(Bord[i + 1][j - 1].piece, pot.col))
					{
						have_empty = true;
						if (no_empty)
						{
							helper::SetTwobit(Bord[m_x][m_y].black_connect,3, i - m_x - 1);
							Bord[m_x][m_y].beffect = true;
							m_x = i; m_y = j;
							i++;
							j--;
						}
					}
					else
					{
						if (no_empty)
						{
							helper::SetTwobit(Bord[i][j].black_connect,3, i - m_x - 1);
							helper::SetTwobit(Bord[m_x][m_y].black_connect,3, fc);
							Bord[i][j].beffect = true;
							Bord[m_x][m_y].beffect = true;
						}
						else
						{
							helper::SetTwobit(Bord[i][j].black_connect,3, fc);
							Bord[i][j].beffect = true;
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
						helper::SetTwobit(Bord[m_x][m_y].black_connect,3, fc);
						Bord[m_x][m_y].beffect = true;
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
		//处理白棋的连珠情况
		else
		{
			//横向
			//先往右遍历
			for (int i = bordpoint_x; i < 15 && i < bordpoint_x + 5; ++i)
			{
				if (IsSameColor(Bord[i][bordpoint_y].piece, pot.col))
				{
					fc++;
				}
				else if (Bord[i][bordpoint_y].piece == helper::FNULL)
				{
					if (i + 1 < 15 && IsSameColor(Bord[i + 1][bordpoint_y].piece, pot.col))
					{
						have_empty = true;
						m_x = i; m_y = bordpoint_y;
					}
					else if (have_empty)
					{
						helper::SetTwobit(Bord[i][bordpoint_y].white_connect,0, i - m_x - 1);
						Bord[i][bordpoint_y].weffect = true;
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
				if (IsSameColor(Bord[i][bordpoint_y].piece, pot.col))
				{
					fc++;
				}
				else if (Bord[i][bordpoint_y].piece == helper::FNULL)
				{
					if (have_empty)
					{
						helper::SetTwobit(Bord[i][bordpoint_y].white_connect,0, m_x - i - 1);
						helper::SetTwobit(Bord[m_x][m_y].white_connect,0, fc);
						Bord[i][bordpoint_y].weffect = true;
						Bord[m_x][m_y].weffect = true;
						fc = -1;
						have_empty = false;
						no_empty = false;
						break;
					}
					else if (i - 1 >= 0 && IsSameColor(Bord[i - 1][bordpoint_y].piece, pot.col))
					{
						have_empty = true;
						if (no_empty)
						{
							helper::SetTwobit(Bord[m_x][m_y].white_connect,0, m_x - i - 1);
							Bord[m_x][m_y].weffect = true;
						}
						m_x = i; m_y = bordpoint_y;
					}
					else
					{
						if (no_empty)
						{
							helper::SetTwobit(Bord[m_x][m_y].white_connect,0, fc);
							helper::SetTwobit(Bord[i][bordpoint_y].white_connect,0, m_x - i - 1);
							Bord[m_x][m_y].weffect = true;
							Bord[i][bordpoint_y].weffect = true;
						}
						else
						{
							helper::SetTwobit(Bord[i][bordpoint_y].white_connect,0, fc);
							Bord[i][bordpoint_y].weffect = true;
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
						helper::SetTwobit(Bord[m_x][m_y].white_connect,0, fc);
						Bord[m_x][m_y].weffect = true;
					}
					have_empty = false;
					no_empty = false;
					fc = -1;
					break;
				}
			}
			//
			have_empty = false;
			no_empty = false;
			fc = -1;

			//竖向
			//先遍历上
			for (int i = bordpoint_y; i >= 0 && i > bordpoint_y - 5; --i)
			{
				if (IsSameColor(Bord[bordpoint_x][i].piece, pot.col))
				{
					fc++;
				}
				else if (Bord[bordpoint_x][i].piece == helper::FNULL)
				{
					if (i - 1 >= 0 && IsSameColor(Bord[bordpoint_x][i - 1].piece, pot.col))
					{
						have_empty = true;
						m_x = bordpoint_x; m_y = i;
					}
					else if (have_empty)
					{
						helper::SetTwobit(Bord[bordpoint_x][i].white_connect,1, m_y - i - 1);
						Bord[bordpoint_x][i].weffect = true;
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
				if (IsSameColor(Bord[bordpoint_x][i].piece, pot.col))
				{
					fc++;
				}
				else if (Bord[bordpoint_x][i].piece == helper::FNULL)
				{
					if (have_empty)
					{
						helper::SetTwobit(Bord[bordpoint_x][i].white_connect,1, i - m_y - 1);
						helper::SetTwobit(Bord[m_x][m_y].white_connect,1, fc);
						Bord[bordpoint_x][i].weffect = true;
						Bord[m_x][m_y].weffect = true;
						fc = -1;
						have_empty = false;
						no_empty = false;
						break;
					}
					else if (i + 1 < 15 && IsSameColor(Bord[bordpoint_x][i + 1].piece, pot.col))
					{
						have_empty = true;
						if (no_empty)
						{
							helper::SetTwobit(Bord[m_x][m_y].white_connect,1, i - m_y - 1);
							Bord[m_x][m_y].weffect = true;
						}
						m_x = bordpoint_x; m_y = i;
					}
					else
					{
						if (no_empty)
						{
							helper::SetTwobit(Bord[bordpoint_x][i].white_connect,1, i - m_y - 1);
							helper::SetTwobit(Bord[m_x][m_y].white_connect,1, fc);
							Bord[bordpoint_x][i].weffect = true;
							Bord[m_x][m_y].weffect = true;
						}
						else
						{
							helper::SetTwobit(Bord[bordpoint_x][i].white_connect,1, fc);
							Bord[bordpoint_x][i].weffect = true;
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
						helper::SetTwobit(Bord[m_x][m_y].white_connect,1, fc);
						Bord[m_x][m_y].weffect = true;
					}
					have_empty = false;
					no_empty = false;
					fc = -1;
					break;
				}
			}
			//
			have_empty = false;
			no_empty = false;
			fc = -1;
			//右斜
			int i = bordpoint_x;
			int j = bordpoint_y;
			while ((i >= 0 && i > bordpoint_x - 5) && (j >= 0 && j > bordpoint_y - 5))
			{
				if (IsSameColor(Bord[i][j].piece, pot.col))
				{
					fc++;
					--i;
					--j;
				}
				else if (Bord[i][j].piece == helper::FNULL)
				{
					if ((i - 1 >= 0) && (j - 1 >= 0) && IsSameColor(Bord[i - 1][j - 1].piece, pot.col))
					{
						have_empty = true;
						m_x = i; m_y = j;
					}
					else if (have_empty)
					{
						helper::SetTwobit(Bord[i][j].white_connect,2, m_x - i - 1);
						Bord[i][j].weffect = true;
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
				if (IsSameColor(Bord[i][j].piece, pot.col))
				{
					fc++;
					i++;
					j++;
				}
				else if (Bord[i][j].piece == helper::FNULL)
				{
					if (have_empty)
					{
						helper::SetTwobit(Bord[i][j].white_connect,2, i - m_x - 1);
						helper::SetTwobit(Bord[m_x][m_y].white_connect,2, fc);
						Bord[i][j].weffect = true;
						Bord[m_x][m_y].weffect = true;
						fc = -1;
						have_empty = false;
						no_empty = false;
						i = bordpoint_x;
						j = bordpoint_y;
						break;
					}
					else if ((i + 1 < 15) && (j + 1 < 15) && IsSameColor(Bord[i + 1][j + 1].piece, pot.col))
					{
						have_empty = true;
						if (no_empty)
						{
							helper::SetTwobit(Bord[m_x][m_y].white_connect,2, i - m_x - 1);
							Bord[m_x][m_y].weffect = true;
							m_x = i; m_y = j;
							i++;
							j++;
						}
					}
					else
					{
						if (no_empty)
						{
							helper::SetTwobit(Bord[i][j].white_connect,2, i - m_x - 1);
							helper::SetTwobit(Bord[m_x][m_y].white_connect,2, fc);
							Bord[i][j].weffect = true;
							Bord[m_x][m_y].weffect = true;
						}
						else
						{
							helper::SetTwobit(Bord[i][j].white_connect,2, fc);
							Bord[i][j].weffect = true;
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
						helper::SetTwobit(Bord[m_x][m_y].white_connect,2, fc);
						Bord[m_x][m_y].weffect = true;
					}
					have_empty = false;
					no_empty = false;
					fc = -1;
					i = bordpoint_x;
					j = bordpoint_y;
					break;
				}
			}
			//
			have_empty = false;
			no_empty = false;
			fc = -1;
			i = bordpoint_x;
			j = bordpoint_y;
			//左斜
			while ((i >= 0 && i > bordpoint_x - 5) && (j < 15 && j < bordpoint_y + 5))
			{
				if (IsSameColor(Bord[i][j].piece, pot.col))
				{
					fc++;
					i--;
					j++;
				}
				else if (Bord[i][j].piece == helper::FNULL)
				{
					if ((i - 1 >= 0) && (j + 1 < 15) && IsSameColor(Bord[i - 1][j + 1].piece, pot.col))
					{
						have_empty = true;
						m_x = i; m_y = j;
					}
					else if (have_empty)
					{
						helper::SetTwobit(Bord[i][j].white_connect,3, m_x - i - 1);
						Bord[i][j].weffect = true;
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
				if (IsSameColor(Bord[i][j].piece, pot.col))
				{
					fc++;
					i++;
					j--;
				}
				else if (Bord[i][j].piece == helper::FNULL)
				{
					if (have_empty)
					{
						helper::SetTwobit(Bord[i][j].white_connect,3, i - m_x - 1);
						helper::SetTwobit(Bord[m_x][m_y].white_connect,3, fc);
						Bord[i][j].weffect = true;
						Bord[m_x][m_y].weffect = true;
						fc = -1;
						have_empty = false;
						no_empty = false;
						i = bordpoint_x;
						j = bordpoint_y;
						break;
					}
					else if ((i + 1 < 15) && (j - 1 >= 0) && IsSameColor(Bord[i + 1][j - 1].piece, pot.col))
					{
						have_empty = true;
						if (no_empty)
						{
							helper::SetTwobit(Bord[m_x][m_y].white_connect,3, i - m_x - 1);
							Bord[m_x][m_y].weffect = true;
							m_x = i; m_y = j;
							i++;
							j--;
						}
					}
					else
					{
						if (no_empty)
						{
							helper::SetTwobit(Bord[i][j].white_connect,3, i - m_x - 1);
							helper::SetTwobit(Bord[m_x][m_y].white_connect,3, fc);
							Bord[i][j].weffect = true;
							Bord[m_x][m_y].weffect = true;
						}
						else
						{
							helper::SetTwobit(Bord[i][j].white_connect,3, fc);
							Bord[i][j].weffect = true;
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
						helper::SetTwobit(Bord[m_x][m_y].white_connect,3, fc);
						Bord[m_x][m_y].weffect = true;
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
	}
}

//修改m_nextpoint
void CMachine::FindNextDown() 
{
	m_nextpoint.x = 0;
	m_nextpoint.y = 0;
	m_nextpoint.col = m_col;
	int mydirect = -1;
	bool have_find = false;
	if (CMachine::m_degree == helper::FEASY)
	{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				if (Bord[i][j].piece != helper::FNULL)
					continue;
				else
				{
					int ibc = helper::GetLastOne(Bord[i][j].black_connect);
					int iwc = helper::GetLastOne(Bord[i][j].white_connect);
					int mbc = helper::GetLastOne(Bord[m_nextpoint.x][m_nextpoint.y].black_connect);
					int mwc = helper::GetLastOne(Bord[m_nextpoint.x][m_nextpoint.y].white_connect);
					if (g_order == helper::BEHAND)
					{
						if (iwc == 4)
						{
							Setnext(i, j);
							have_find = true;
							break;
						}
						else if (ibc == 4)
						{
							Setnext(i, j);
							continue;
						}
						else if (mbc < 4 && iwc == 3)
						{
							Setnext(i, j);
							continue;
						}
						else if (ibc == 3 && mbc != 4 && mwc < 3)
						{
							Setnext(i, j);
							continue;
						}
						else if (mbc < 3 && mwc < iwc)
						{
							Setnext(i, j);
							continue;
						}
						else if (mwc == 0 && mbc == 0 && (ibc != 0 || ibc != 0))
						{
							Setnext(i, j);
							continue;
						}
						else
						{
							continue;
						}
					}
					else
					{
						//先手
					}

				}
			}
			if (have_find)
				break;
		}
	}
	else if (CMachine::m_degree == helper::FDIFFICULT)
	{
		int barr[5] = { 0 };
		int warr[5] = { 0 };
		for (int i = 0; i < 15; ++i)
		{
			for (int j = 0; j < 15; ++j)
			{
				barr[0] = helper::GetTwobit(Bord[i][j].black_connect, 0) + 1;//bh
				barr[1] = helper::GetTwobit(Bord[i][j].black_connect, 1) + 1;//bv
				barr[2] = helper::GetTwobit(Bord[i][j].black_connect, 2) + 1;//by
				barr[3] = helper::GetTwobit(Bord[i][j].black_connect, 3) + 1;//bz

				warr[0] = helper::GetTwobit(Bord[i][j].white_connect, 0) + 1;//wh
				warr[1] = helper::GetTwobit(Bord[i][j].white_connect, 1) + 1;//wv
				warr[2] = helper::GetTwobit(Bord[i][j].white_connect, 2) + 1;//wy
				warr[3] = helper::GetTwobit(Bord[i][j].white_connect, 3) + 1;//wz

				if(Bord[i][j].piece != helper::FNULL)
					continue;
				if (g_order == helper::BEFORE)
				{
					if (Willfive(barr,mydirect))
					{
						Setnext(i, j);
						have_find = true;
						break;
					}
					else if (Willfive(warr,mydirect))
					{
						Setnext(i, j);
						g_connect = helper::WILL_5;
						continue;
					}
					else if (Willfoandthr(barr,mydirect))
					{
						if (g_connect != helper::WILL_5)
						{
							Setnext(i, j);
							g_connect = helper::WILL_3_4;
						}
						continue;
					}
					else if (Willfour(barr,mydirect))
					{
						if ((int)g_connect < (int)helper::WILL_4)
						{
							Setnext(i, j);
							g_connect = helper::WILL_4;
						}
						continue;
					}
					else if (Willfour(warr, mydirect) && helper::Judgethrough(i, j, mydirect))
					{
						if ((int)g_connect < (int)helper::O_WILL_4)
						{
							Setnext(i, j);
							g_connect = helper::O_WILL_4;
						}
						continue;
					}
					else if (Willthrandthr(barr, mydirect))
					{
						if ((int)g_connect < helper::WILL_3_3)
						{
							Setnext(i, j);
							g_connect = helper::WILL_3_3;
						}
						continue;
					}
					else if (Willthree(barr, mydirect))
					{
						if ((int)g_connect < helper::WILL_3)
						{
							Setnext(i, j);
							g_connect = helper::WILL_3;
						}
						continue;
					}
					else if(WillTow(barr,mydirect))
					{
						if ((int)g_connect < helper::WILL_2)
						{
							Setnext(i, j);
							g_connect = helper::WILL_2;
						}
						continue;
					}
					else
					{
						continue;
					}
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
						if (g_connect != helper::WILL_5)
						{
							Setnext(i, j);
							g_connect = helper::WILL_5;
							m_act = ACT_DEFENSE;
						}
						continue;
					}
					else if (!Isborder(i,j) && Willfoandthr(warr, mydirect))
					{
						if ((int)g_connect < (int)helper::WILL_3_4)
						{
							Setnext(i, j);
							g_connect = helper::WILL_3_4;
							m_act = ACT_ATTACK;
						}
						continue;
					}
					else if (Willfour(warr, mydirect) && IsBestPoint(i,j,mydirect))
					{
						if ((int)g_connect < (int)helper::WILL_4)
						{
							Setnext(i, j);
							g_connect = helper::WILL_4;
							m_act = ACT_ATTACK;
						}
						continue;
					}
					else if (!Isborder(i,j) && Willfour(barr, mydirect) && helper::Judgethrough(i, j, mydirect))
					{
						if ((int)g_connect < (int)helper::O_WILL_4)
						{
							Setnext(i, j);
							g_connect = helper::O_WILL_4;
							m_act = ACT_DEFENSE;
						}
						continue;
					}
					else if (!Isborder(i,j) && Willthrandthr(warr, mydirect))
					{
						if ((int)g_connect < helper::WILL_3_3)
						{
							Setnext(i, j);
							g_connect = helper::WILL_3_3;
							m_act = ACT_ATTACK;
						}
						continue;
					}
					else if (!Isborder(i,j) && m_build_count == 0 && Willthree(warr, mydirect) && IsBestPoint(i,j,mydirect))
					{
						if ((int)g_connect < helper::WILL_3)
						{
							Setnext(i, j);
							g_connect = helper::WILL_3;
							m_act = ACT_ATTACK;
						}
						continue;
					}
					else if(!Isborder(i,j) && Bord[i][j].weffect && WillTow(warr,mydirect))
					{
						if ((int)g_connect < helper::WILL_2)
						{
							g_connect = helper::WILL_2;
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
		g_connect = helper::NONE;
	}
	
}

void CMachine::MHandle(HWND hwnd,HDC hdc,HBRUSH hbrush)
{
	if (g_order == helper::BEHAND)
	{
		if (m_first)
		{
			if (helper::Haveone(helper::BLACK))
			{
				if (Bord[7][7].piece == helper::FNULL)
				{
					m_nextpoint.x = 7; m_nextpoint.y = 7;
					build_x = 7; build_y = 7;
					m_act = ACT_BUILD;
					m_isbuild = true;
				}
				else
				{
					build_x = 7;
					build_y = 7;
					m_act = ACT_BUILD;
					m_isbuild = true;
					FindBuildnext();
				}
				g_turn = helper::TURN_OF_PERSON;
				m_first = false;
			}
			else
			{
				g_turn = helper::TURN_OF_PERSON;
				return;
			}

			m_nextpoint.col = m_col;
			m_nextpoint.x = m_nextpoint.x * 30 + 90;
			m_nextpoint.y = m_nextpoint.y * 30 + 90;
			helper::Drawpoint(hwnd, hdc, hbrush, m_nextpoint, (m_nextpoint.col == RGB(0, 0, 0)));
		}
		else
		{
			FindNextDown();
			if (m_act != ACT_BUILD && m_act != ACT_NULL)
			{
				m_nextpoint.col = m_col;
				m_nextpoint.x = m_nextpoint.x * 30 + 90;
				m_nextpoint.y = m_nextpoint.y * 30 + 90;
				helper::Drawpoint(hwnd, hdc, hbrush, m_nextpoint, (m_nextpoint.col == RGB(0, 0, 0)));
				if (m_isbuild)
				{
					m_act = ACT_BUILD;
				}
				g_turn = helper::TURN_OF_PERSON;
			}
			else if (m_act == ACT_BUILD)
			{
				FindBuildnext();
				m_nextpoint.col = m_col;
				m_nextpoint.x = m_nextpoint.x * 30 + 90;
				m_nextpoint.y = m_nextpoint.y * 30 + 90;
				helper::Drawpoint(hwnd, hdc, hbrush, m_nextpoint, (m_nextpoint.col == RGB(0, 0, 0)));
				g_turn = helper::TURN_OF_PERSON;
			}
		}
	}
	else//先手
	{

	}
}

bool CMachine::IsSameColor(const helper::PIECE_COLOR& pcol, const COLORREF& col) 
{
	if (pcol == helper::BLACK && col == RGB(0, 0, 0))
		return true;
	else if (pcol == helper::WHITE && col == RGB(255, 255, 255))
		return true;
	else
		return false;
}

void CMachine::SetDegree(const helper::DEGREE_DIFFICULT& deg)
{
	CMachine::m_degree = deg;
}

void CMachine::SetOrder(const helper::ORDER_PUT& ord)
{
	g_order = ord;
}

void CMachine::Setnext(const int a, const int b)
{
	m_nextpoint.x = a;
	m_nextpoint.y = b;
}

bool CMachine::Willfive(int* b, int& direct)
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

bool CMachine::Willfoandthr(int* b, int& direct)
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
			direct = i;
		}
	}
	if (thr >= 1 && four >= 1)
		return true;
	return false;
}

bool CMachine::Willfour(int* b, int& direct)
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

bool CMachine::Willthrandthr(int* b, int& direct)
{
	int count = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (b[i] == 2)
		{
			count++;
			direct = i;
		}
	}
	if (count >= 2)
		return true;
	return false;
}

bool CMachine::Willthree(int* b, int& direct)
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

bool CMachine::WillTow(int* b,int& direct)
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

bool CMachine::Build(int x, int y, helper::GAME_DIRECTION dir)
{
	int t_x;
	int t_y;
	switch (dir)
	{
	case helper::DIRECT_UP:
		t_x = x;
		t_y = y-1;
		break;
	case helper::DIRECT_LEFT:
		t_x = x-1;
		t_y = y;
		break;
	case helper::DIRECT_DOWN:
		t_x = x;
		t_y = y+1;
		break;
	case helper::DIRECT_RIGHT:
		t_x = x+1;
		t_y = y;
		break;
	case helper::DIRECT_LEFT_UP:
		t_x = x-1;
		t_y = y-1;
		break;
	case helper::DIRECT_RIGHT_UP:
		t_x = x+1;
		t_y = y-1;
		break;
	case helper::DIRECT_LEFT_DOWN:
		t_x = x-1;
		t_y = y+1;
		break;
	case helper::DIRECT_RIGHT_DOWN:
		t_x = x+1;
		t_y = y+1;
		break;
	}
	if (Bord[t_x][t_y].piece == helper::FNULL)
	{
		m_nextpoint.x = t_x;
		m_nextpoint.y = t_y;
		return true;
	}
	return false;
}

void CMachine::FindBasepoint()
{
	helper::GAME_DIRECTION dir = helper::DIRECT_RIGHT;
	int bor_count = 0;
	int res_count = 8;
	for (int i = 0; i <= 7; ++i)
	{
		int border = 2 * i + 1;
		int x = 7 - i;
		int y = 7 - i;
		while (1)
		{
			if(dir == helper::DIRECT_RIGHT)
			{
				bor_count++;
				if (IsSameColor(Bord[x][y].piece,m_col))
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
					dir = helper::DIRECT_DOWN;
					bor_count = 0;
				}
				else
				{
					x++;
				}
			}
			else if (dir == helper::DIRECT_DOWN)
			{
				bor_count++;
				if (IsSameColor(Bord[x][y].piece, m_col))
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
					dir = helper::DIRECT_LEFT;
					bor_count = 0;
				}
				else
				{
					y++;
				}
			}
			else if (dir == helper::DIRECT_LEFT)
			{
				bor_count++;
				if (IsSameColor(Bord[x][y].piece, m_col))
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
					dir = helper::DIRECT_UP;
					border = 0;
				}
				else
				{
					x--;
				}
			}
			else if (dir == helper::DIRECT_UP)
			{
				bor_count++;
				if (IsSameColor(Bord[x][y].piece, m_col))
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
					dir = helper::DIRECT_RIGHT;
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

int CMachine::CountForPoint(int x, int y)
{
	int count = 0;
	if (Bord[x - 1][y - 1].piece != helper::FNULL && Bord[x - 1][y - 1].piece != m_col)
	{
		count++;
	}
	if (Bord[x][y - 1].piece != helper::FNULL && Bord[x][y - 1].piece != m_col)
	{
		count++;
	}
	if (Bord[x + 1][y - 1].piece != helper::FNULL && Bord[x + 1][y - 1].piece != m_col)
	{
		count++;
	}
	if (Bord[x + 1][y].piece != helper::FNULL && Bord[x + 1][y].piece != m_col)
	{
		count++;
	}
	if (Bord[x + 1][y + 1].piece != helper::FNULL && Bord[x + 1][y + 1].piece != m_col)
	{
		count++;
	}
	if (Bord[x][y + 1].piece != helper::FNULL && Bord[x][y + 1].piece != m_col)
	{
		count++;
	}
	if (Bord[x - 1][y + 1].piece != helper::FNULL && Bord[x - 1][y + 1].piece != m_col)
	{
		count++;
	}
	if (Bord[x - 1][y].piece != helper::FNULL && Bord[x - 1][y].piece != m_col)
	{
		count++;
	}
	return count;
}

void CMachine::FindBuildnext()
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
			isfind = Build(build_x, build_y, (helper::GAME_DIRECTION)(rand() % 8 + 1));
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

bool CMachine::Isborder(int x, int y)
{
	if (x == 0 || x == 14 || y == 0 || y == 14)
		return true;
	else
		return false;
}

bool CMachine::IsBestPoint(int x, int y,int direct)
{
	if (direct == -1)
		return false;
	switch (direct)
	{
	case 0://横向
	{
		if ((Bord[x - 1][y].piece != helper::FNULL && !IsSameColor(Bord[x-1][y].piece,m_col)) || 
			(Bord[x + 1][y].piece != helper::FNULL && !IsSameColor(Bord[x + 1][y].piece, m_col)))
			return false;
		return true;
	}
	case 1://竖向
	{
		if ((Bord[x][y - 1].piece != helper::FNULL && !IsSameColor(Bord[x][y-1].piece, m_col)) || 
			(Bord[x][y + 1].piece != helper::FNULL && !IsSameColor(Bord[x][y + 1].piece, m_col)))
			return false;
		return true;
	}
	case 2://右斜
	{
		if ((Bord[x - 1][y - 1].piece != helper::FNULL && !IsSameColor(Bord[x - 1][y-1].piece, m_col)) ||
			(Bord[x + 1][y + 1].piece != helper::FNULL && !IsSameColor(Bord[x + 1][y + 1].piece, m_col)))
			return false;
		return true;
	}
	case 3://左斜
	{
		if ((Bord[x - 1][y + 1].piece != helper::FNULL && !IsSameColor(Bord[x - 1][y+1].piece, m_col)) || 
			(Bord[x + 1][y - 1].piece != helper::FNULL && !IsSameColor(Bord[x + 1][y - 1].piece, m_col)))
			return false;
		return true;
	}

	}

	return false;
}

extern CMachine machine;