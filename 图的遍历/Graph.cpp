#include "Graph.h"

bool visited[MaxVnum];

//�����ڽӾ�����ͼ
GraphM CreatGraph()
{
	GraphM maxtrix;
	cout << "������ͼ�Ķ�������";
	int n_vexnum;
	int n_arcnum = 0;
	cin >> n_vexnum;
	getchar();
	for(int i = 0;i < n_vexnum;i++)
	{
		maxtrix.vex[i] = i;
	}

	maxtrix.vexnum = n_vexnum;

	cout << "�����ڽӾ���" << endl;
	maxtrix.arcs[n_vexnum][n_vexnum] = { 0 };
	int line, cow;
	char ch = 'y';
	while (ch == 'y')
	{
		cout << "���������֮���й�ϵ��";
		cin >> line >> cow;

		maxtrix.arcs[line][cow] = 1;
		maxtrix.arcs[cow][line] = 1;
		n_arcnum += 2;

		cout << "���仹�й�ϵô��";
		getchar();
		cin >> ch;
	}
	maxtrix.arcnum = n_arcnum;
	for (int i = 0; i < maxtrix.vexnum; i++)
		visited[i] = false;

	return maxtrix;
}


//������ȱ���ͼ
void MDepth_First_Search(GraphM g,int k)
{
	if(!visited[k])
	{
		cout << g.vex[k] << " ";
		visited[k] = true;
	}
	for (int i = 0; i < g.vexnum; i++)//��������
	{
		if(!visited[i] && g.arcs[k][i] == 1)
		{
			MDepth_First_Search(g, i);
		}
	}
}

void MTraverse(GraphM g)
{
	for (int i = 0; i < g.vexnum; i++)
		MDepth_First_Search(g, i);
}