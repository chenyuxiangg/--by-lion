#include "Graph.h"

bool visited[MaxVnum];

//基于邻接矩阵构造图
GraphM CreatGraph()
{
	GraphM maxtrix;
	cout << "请输入图的顶点数：";
	int n_vexnum;
	int n_arcnum = 0;
	cin >> n_vexnum;
	getchar();
	for(int i = 0;i < n_vexnum;i++)
	{
		maxtrix.vex[i] = i;
	}

	maxtrix.vexnum = n_vexnum;

	cout << "构造邻接矩阵" << endl;
	maxtrix.arcs[n_vexnum][n_vexnum] = { 0 };
	int line, cow;
	char ch = 'y';
	while (ch == 'y')
	{
		cout << "哪两个结点之间有关系：";
		cin >> line >> cow;

		maxtrix.arcs[line][cow] = 1;
		maxtrix.arcs[cow][line] = 1;
		n_arcnum += 2;

		cout << "结点间还有关系么？";
		getchar();
		cin >> ch;
	}
	maxtrix.arcnum = n_arcnum;
	for (int i = 0; i < maxtrix.vexnum; i++)
		visited[i] = false;

	return maxtrix;
}


//深度优先遍历图
void MDepth_First_Search(GraphM g,int k)
{
	if(!visited[k])
	{
		cout << g.vex[k] << " ";
		visited[k] = true;
	}
	for (int i = 0; i < g.vexnum; i++)//遍历顶点
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