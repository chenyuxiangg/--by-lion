#include "GraphL.h"
#define _CRT_SECURE_NO_DEPRECATE
int main()
{
	Graph G;
	create(G);// printf("����ڽӾ���:\n");
	//output(G);
	printf("������ȱ���(�ݹ�):\n");
	dfs(G, 0);
	printf("\n������ȱ���(�ݹ�):\n");
	bfs(G, 0);
	printf("\n������ȱ���(�ǵݹ�):\n");
	bfs_1(G, 0);

	getchar();
	getchar();
	return 0;
}