#pragma once
#ifndef GRAGH_H
#define GRAGH_H
#include <iostream>
using namespace std;


//图的类型定义（需要斟酌）
//enum graph{DG,DN,UDG,UDN};//有向图，有向网，无向图，无向网
//

#define MaxVnum 50  //顶点上限
//临接矩阵的定义
typedef int AdjMatrix[MaxVnum][MaxVnum];//矩阵
typedef struct
{
	int vex[MaxVnum];//顶点集
	int vexnum;//图的顶点数
	int arcnum;//图的边数
	AdjMatrix arcs;//临接矩阵
}GraphM;

//邻接表的定义
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