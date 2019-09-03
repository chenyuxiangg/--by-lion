#include "GraphL.h"
#define _CRT_SECURE_NO_DEPRECATE
int main()
{
	Graph G;
	create(G);// printf("输出邻接矩阵:\n");
	//output(G);
	printf("深度优先遍历(递归):\n");
	dfs(G, 0);
	printf("\n广度优先遍历(递归):\n");
	bfs(G, 0);
	printf("\n广度优先遍历(非递归):\n");
	bfs_1(G, 0);

	getchar();
	getchar();
	return 0;
}