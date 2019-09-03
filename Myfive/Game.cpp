#include "Game.h"
CGame::CGame()
{
	m_step = { 0,0 };
	m_model = MUDEL_NONE;
	CleanBord();
	m_turn = TURN_NONE;
	m_order = ORDER_NONE;
	m_youcol = FNULL;
	m_curcol = FNULL;
	m_redraw = false;
}

bool CGame::IsVector(bool flag)
{
	if (flag)
	{
		return true;
	}
	else
		return false;
}

bool CGame::IsBalance(bool flag)
{
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
			if (m_bord[i][j].piece == FNULL)
				return false;
	}
	if (!flag)
		return true;
	else
		return false;
}

void CGame::SetBord(const STEP& step, PIECE_COLOR col)
{
	m_bord[step.x][step.y].piece = col;
}

void CGame::CleanBord()
{
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			m_bord[i][j].black_connect = 0;
			m_bord[i][j].white_connect = 0;
			m_bord[i][j].beffect = false;
			m_bord[i][j].weffect = false;
			m_bord[i][j].piece = FNULL;
		}
	}
}

bool CGame::IsThree(const STEP& step,const PIECE_COLOR& col)
{
	int xr = step.x;
	int yr = step.y;

	/* 从四个方向判断是否成 三 */
	if ((m_bord[xr - 1][yr].piece == col && m_bord[xr + 1][yr].piece == col) ||
		(m_bord[xr + 1][yr].piece == col && m_bord[xr + 2][yr].piece == col) ||
		(m_bord[xr - 1][yr].piece == col && m_bord[xr - 2][yr].piece == col))//横向
		return true;
	else if ((m_bord[xr][yr - 1].piece == col && m_bord[xr][yr + 1].piece == col) ||
		(m_bord[xr][yr - 1].piece == col && m_bord[xr][yr - 2].piece == col) ||
		(m_bord[xr][yr + 1].piece == col && m_bord[xr][yr + 2].piece == col))//竖向
		return true;
	else if ((m_bord[xr - 1][yr - 1].piece == col && m_bord[xr + 1][yr + 1].piece == col) ||
		(m_bord[xr - 1][yr - 1].piece == col && m_bord[xr - 2][yr - 2].piece == col) ||
		(m_bord[xr + 1][yr + 1].piece == col && m_bord[xr + 2][yr + 2].piece == col))//右斜
		return true;
	else if (m_bord[xr + 1][yr - 1].piece == col && m_bord[xr - 1][yr + 1].piece == col ||
		(m_bord[xr - 1][yr + 1].piece == col && m_bord[xr - 2][yr + 2].piece == col) ||
		(m_bord[xr + 1][yr - 1].piece == col && m_bord[xr + 2][yr - 2].piece == col))//左斜
		return true;
	else
		return false;
}

bool CGame::IsFour(const STEP& step, const PIECE_COLOR& col)
{
	int count = -1;
	int xr = step.x;
	int yr = step.y;

	/* 从四个方向判断是否满四 */
	//横向
	for (int i = xr; i >= 0; --i)
	{
		if (m_bord[i][yr].piece == col)
			count++;
		else
			break;
	}
	for (int i = xr; i < 15; ++i)
	{
		if (m_bord[i][yr].piece == col)
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
		if (m_bord[xr][i].piece == col)
			count++;
		else
			break;
	}
	for (int i = yr; i < 15; ++i)
	{
		if (m_bord[xr][i].piece == col)
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
		if (m_bord[i][j].piece == col)
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
		if (m_bord[i][j].piece == col)
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
		if (m_bord[i][j].piece == col)
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
	i = xr; j = yr;
	while (i >= 0 && j < 15)
	{
		if (m_bord[i][j].piece == col)
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

bool CGame::IsFive(const STEP& step, const PIECE_COLOR& col)
{
	int count = -1;
	int xr = step.x;
	int yr = step.y;

	/* 从四个方向判断是否满五 */
	//横向
	for (int i = xr; i >= 0; --i)
	{
		if (m_bord[i][yr].piece == col)
			count++;
		else
			break;
	}
	for (int i = xr; i < 15; ++i)
	{
		if (m_bord[i][yr].piece == col)
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
		if (m_bord[xr][i].piece == col)
			count++;
		else
			break;
	}
	for (int i = yr; i < 15; ++i)
	{
		if (m_bord[xr][i].piece == col)
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
		if (m_bord[i][j].piece == col)
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
		if (m_bord[i][j].piece == col)
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
		if (m_bord[i][j].piece == col)
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
		if (m_bord[i][j].piece == col)
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

