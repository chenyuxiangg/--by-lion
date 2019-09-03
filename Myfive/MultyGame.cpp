#include "MultyGame.h"

CMultyGame* CMultyGame::m_instance = NULL;
CMultyGame::CMultyGame() :CGame()
{
	m_instance = new CMultyGame();
}

CMultyGame::~CMultyGame()
{
	delete m_instance;
	m_instance = NULL;
}

CMultyGame* CMultyGame::GetInstance()
{
	return m_instance;
}

CMultyGame& CMultyGame::operator=(const CMultyGame&) {}

void CMultyGame::Judge()
{
	if (IsVector(IsFive(m_step, m_curcol)))
	{
		CleanBord();//���ô�������
		m_redraw = true;
		if (m_youcol == BLACK)
			m_turn = TURN_OF_YOU;
		else
			m_turn = TURN_OF_OTHER;
		//������·�����浽�����ļ�
		//
		//�����һ�ֵ�����·��
		m_list[0].erase(m_list[0].begin(), m_list[0].end());
		m_list[1].erase(m_list[1].begin(), m_list[1].end());
	}
}