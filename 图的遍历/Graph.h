#pragma once
#ifndef GRAGH_H
#define GRAGH_H
#include <iostream>
using namespace std;


//ͼ�����Ͷ��壨��Ҫ���ã�
//enum graph{DG,DN,UDG,UDN};//����ͼ��������������ͼ��������
//

#define MaxVnum 50  //��������
//�ٽӾ���Ķ���
typedef int AdjMatrix[MaxVnum][MaxVnum];//����
typedef struct
{
	int vex[MaxVnum];//���㼯
	int vexnum;//ͼ�Ķ�����
	int arcnum;//ͼ�ı���
	AdjMatrix arcs;//�ٽӾ���
}GraphM;

//�ڽӱ�Ķ���
typedef char VertexType;
typedef struct ArcNode
{
	int adjvex;
	ArcNode* nextarc;
}ArcNode;

typedef struct  
{
	VertexType date;
	ArcNode* firstarc;
}AdjList[MaxVnum],Vnode;

typedef struct  
{
	int vexnum;
	int arcnum;
	AdjList vertices;
}GraphL;

GraphM CreatGraph();
void MDepth_First_Search(GraphM g, int k);
void MTraverse(GraphM g);
#endif