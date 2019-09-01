/*
johnson�㷨
1��ʵ��˼·
	johnson�㷨������������Ȩֵ������ͼȫԴ���·������ķ��������ȷ�������
	�㷨���졣
	���㷨���ʹ���˵Ͻ�˹�����㷨(��Դ�����·���㷨������̰��)��bellman_ford
	�㷨(��Դ�����·���㷨�����ڶ�̬�滮��Ч���ȵϽ�˹�����㷨��)������˼���ǣ�
	�ȶ�ԭͼ��Ȩֵ�Ǹ�����Ȼ����ʹ�õϽ�˹�����㷨�ֱ�����Ը���ΪԴ������·
	�����������£�
	1����ԭͼ�м���һ����Դ�㡱���õ㵽�������е�ľ���Ϊ 0.
	2��ʹ��bellman_form�㷨�����Դ�㡱����������·�����ֱ��¼��disc[]�б���
	3����ԭͼ�����б߽��д�����w(u,v) = disc[u]-disc[v]+w(u,v)
	4����һ�����õ�ͼ��Ϊ�Ǹ�Ȩͼ��Ȼ�����ԭͼ���нڵ㣬�ֱ�ʹ�õϽ�˹�����㷨�� 
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

//����Դ��
void Johnson::add_src(Graphic* G){
	if(!G){
		return;
	}
	G->m_edge += m_node;
	G->m_node += 1;
	int src_num = m_node-1;  //��Դ����뵽�ڵ�����ĩβ
	int node_size = G->m_node;  
	int edge_size = G->m_edge;
	
	//�����Դ������ı� 
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
	//��ʼ��disc
	disc = new int[node_size];
	for(int i = 0;i < node_size-1;++i){
		disc[i] = INT_MAX;
	}
	disc[node_size-1] = 0;
	
	//��⣬�������disc�У����ڸú�����ʹ�� 
	for(int i = 0;i < node_size-1;++i){
		for(int j = 0;j < edge_size;++j){
			//��ÿһ���߽����ɳ�
			int start = G->edges[j].start;
			int end = G->edges[j].end;
			int weight = G->edges.weight;
			if(disc[start] != INT_MAX && disc[end] > disc[start]+weight){
				disc[end] = disc[start]+weight;
			}
		}
	}
	
	//����Ƿ���ڸ���
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
