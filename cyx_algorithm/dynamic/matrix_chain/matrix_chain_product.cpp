#include <iostream>
#include <memory.h>
#include <limits.h>
using namespace std;
const int MAX_LIMIT = 100;
int g_m[MAX_LIMIT][MAX_LIMIT];
int g_s[MAX_LIMIT][MAX_LIMIT];

int matrix_chain_product(int* p,int n){
	int i,j,l,k;	//起点，终点，长度，划分点
	for(l = 2;l <= n;++l){
		for(i = 1;i <= n-l+1;++i){
			j = i+l-1;
			g_m[i][j] = -1;
			for(k = i;k < j;++k){
				int tmp = g_m[i][k]+g_m[k+1][j]+p[i-1]*p[k]*p[j];
				if(tmp < g_m[i][j] || g_m[i][j] == -1){
					g_m[i][j] = tmp;
					g_s[i][j] = k;
					}
				}
			}
		}
		return g_m[1][n-1];
	}

void print_optimal(int s[][MAX_LIMIT],int i,int j){
	if(i == j){
		cout << "A" << i;
		}
	else{
		cout << "(";
		print_optimal(s,i,s[i][j]);
		print_optimal(s,s[i][j]+1,j);
		cout << ")";
		}
	}

int main(int argc,char* argv[]){
	memset(g_m,0,sizeof(g_m));
	memset(g_s,0,sizeof(g_s));
	int n;
	int* p = new int[n];
	cin >> n;
	for(int i = 0;i < n;++i){
		cin >> p[i];
		}
	int res = matrix_chain_product(p,n);
	cout << res << endl;
	print_optimal(g_s,1,n-1);
	cout << endl;
	return 0;
	}
