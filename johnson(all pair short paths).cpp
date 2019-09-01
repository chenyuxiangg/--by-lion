/*
johnson算法
1、实现思路
	johnson算法是求解允许带负权值边有向图全源最短路径问题的方法，它比佛洛依德
	算法更快。
	该算法组合使用了迪杰斯特拉算法(单源点最短路径算法，基于贪心)和bellman_ford
	算法(单源点最短路径算法，基于动态规划，效果比迪杰斯特拉算法差)。它的思想是，
	先对原图做权值非负处理，然后再使用迪杰斯特拉算法分别求解以各点为源点的最短路
	径。步骤如下：
	1、在原图中加入一个“源点”，该点到其他所有点的距离为 0.
	2、使用bellman_form算法求出“源点”到各点的最短路径，分别记录到disc[]中备用
	3、对原图中所有边进行处理，及w(u,v) = disc[u]-disc[v]+w(u,v)
	4、上一步所得的图即为非负权图，然后遍历原图所有节点，分别使用迪杰斯特拉算法。 
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge{
	int start;
	int end;
	int weight;
};

class Graphic{
public:
	int m_node;
	int m_edge;
	vector<struct Edge> edges;
	
public:
	Graphic(int node,int edge):m_node(node),m_edge(edge){
		for(int i = 0;i < m_edge;++i){
			struct Edge tmp;
			cout << "(start,end,weight):";
			cin >> tmp.start >> tmp.end >> tmp.weight;
			edges.push_back(tmp);
		}
	}
};

class Johnson{
public:
	Johnson(){}
	~Johnson(){}
	static void calculate(Graphic* G,int* node_values);
	
private:
	static void add_src(Graphic* G);
	static bool bellman_ford(Graphic* G,int* disc);
	static void update_graphic(Graphic* G,int* node_values);
	static void dijkstra(Graphic* G);
};

//加入源点
void Johnson::add_src(Graphic* G){
	if(!G){
		return;
	}
	G->m_edge += m_node;
	G->m_node += 1;
	int src_num = m_node-1;  //将源点加入到节点数组末尾
	int node_size = G->m_node;  
	int edge_size = G->m_edge;
	
	//加入从源点出发的边 
	for(int i = 0;i < node_size-1;++i){
		struct Edge tmp;
		tmp.start = src_num;
		tmp.end = i;
		tmp.weight = 0;
		G->edges.push_back(tmp);
	}
} 

bool Johnson::bellman_ford(Graphic* G,int* disc){
	int node_size = G->m_node;
	int edge_size = G->m_edge;
	//初始化disc
	disc = new int[node_size];
	for(int i = 0;i < node_size-1;++i){
		disc[i] = INT_MAX;
	}
	disc[node_size-1] = 0;
	
	//求解，结果放在disc中，可在该函数外使用 
	for(int i = 0;i < node_size-1;++i){
		for(int j = 0;j < edge_size;++j){
			//对每一条边进行松弛
			int start = G->edges[j].start;
			int end = G->edges[j].end;
			int weight = G->edges.weight;
			if(disc[start] != INT_MAX && disc[end] > disc[start]+weight){
				disc[end] = disc[start]+weight;
			}
		}
	}
	
	//检测是否存在负环
	bool flag = true;
	for(int j = 0;j < edge_size;++j){
		int start = G->edges[j].start;
		int end = G->edges[j].end;
		int weight = G->edges.weight;
		if(disc[start] != INT_MAX && disc[end] > disc[start]+weight){
			flag = false;
			break;
		}
	}
	return flag;
}

void Johnson::update_graphic(Graphic* G,int* node_values){
	int node_size = G->m_node;
	int edge_size = G->m_edge;
	for(int i = 0;i < edge_size;++i){
		int start = G->edges[i].start;
		int end = G->edges[i].end; 
		G->edges[i].weight += (node_values[start] - node_values[end]);
	}
}

void Johnson::dijkstra(Graphic* G){
	
}
