#pragma once
/**
����ͼ���ڽӱ�洢
������ȱ����ݹ�
������ȱ����ݹ�+�ǵݹ�
*/
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define N 5
#define MAX 50
typedef struct A {
	int adjvex;
	struct A* nextArc;
}Arc;
typedef struct node {
	char data[N];
	Arc* firstArc;
}Node;
typedef struct graph {
	Node vex[MAX];
	int numv;
	int nume;
}Graph;

int getIndex(Graph G, char s[]) {
	for (int i = 0; i < G.numv; i++) {
		if (strcmp(G.vex[i].data, s) == 0)
			return i;
	}
	return -1;
}

void create(Graph& G) {
	printf("���붥��ͻ��ĸ���:\n");
	scanf("%d%d", &G.numv, &G.nume);
	printf("���붥����Ϣ:\n");
	for (int i = 0; i < G.numv; i++)
		scanf("%s", G.vex[i].data);
	///��ʼ����������
	for (int i = 0; i < G.numv; i++)
		G.vex[i].firstArc = NULL;
	printf("����ߵ���Ϣ:\n");
	char s[N], e[N];
	int u, v;
	for (int i = 0; i < G.nume; i++) {
		scanf("%s%s", s, e);
		u = getIndex(G, s);
		v = getIndex(G, e);
		Arc* p = (Arc*)malloc(sizeof(Arc));
		p->adjvex = v;
		p->nextArc = NULL;
		p->nextArc = G.vex[u].firstArc;
		G.vex[u].firstArc = p;
		Arc* t = (Arc*)malloc(sizeof(Arc));
		t->nextArc = NULL;
		t->adjvex = u;
		t->nextArc = G.vex[v].firstArc;
		G.vex[v].firstArc = t;
	}
}

void output(Graph G) {
	Arc* p;
	for (int i = 0; i < G.numv; i++) {
		p = G.vex[i].firstArc;
		printf("%4s", G.vex[i].data);
		while (p != NULL) {
			printf("%4s", G.vex[p->adjvex].data);
			p = p->nextArc;
		}
		printf("\n");
	}
}

///������ȱ��� (�ݹ�)
int visit[2 * MAX];
void dfs(Graph G, int s) {
	Arc* p = G.vex[s].firstArc;
	if (!visit[s]) {
		printf("%4s", G.vex[s].data);
		visit[s] = 1;
	}
	while (p != NULL) {
		if (!visit[p->adjvex])
			dfs(G, p->adjvex);
		p = p->nextArc;
	}
}

///������ȱ��� (�ݹ�)
///ȱ��ݹ����ΪG.numv��
int q[2 * MAX], f = 0, r = 0;
int visit_q[MAX];
void bfs(Graph G, int s) {
	if (!visit_q[s]) {
		printf("%4s", G.vex[s].data);
		visit_q[s] = 1;
		Arc* p = G.vex[s].firstArc;
		while (p != NULL) {
			if (!visit_q[p->adjvex])
				q[r++] = p->adjvex;
			p = p->nextArc;
		}
	}
	while (f < r) {
		bfs(G, q[f++]);
	}
}

///������ȱ��� (�ǵݹ�)
int Q[2 * MAX], F = 0, R = 0;
int visit_Q[MAX];
void bfs_1(Graph G, int s) {
	printf("%4s", G.vex[s].data);
	visit_Q[s] = 1;
	Arc* p = G.vex[s].firstArc;
	while (p != NULL) {
		Q[R++] = p->adjvex;
		p = p->nextArc;
	}
	while (F < R) {
		int node = Q[F++];
		if (!visit_Q[node]) {
			printf("%4s", G.vex[node].data);
			visit_Q[node] = 1;
			p = G.vex[node].firstArc;
			while (p != NULL) {
				if (!visit_Q[p->adjvex])
					Q[R++] = p->adjvex;
				p = p->nextArc;
			}
		}
	}
}