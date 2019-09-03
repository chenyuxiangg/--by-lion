#include <iostream>
#include <cmath>
#include <memory.h>
using namespace std;

int N = 0;
int queenarr[100];
int queen_count = 0;

int queensolt(int k)
{
	//int static queen_count = 0;
	if(k == N)
	{
		for (int i = 0; i < N; ++i)
		{
			cout << queenarr[i] << " ";
		}
		cout << endl;
		return (++queen_count);
	}
	
	for(int i = 0;i < N;++i)
	{
		int j;
		for(j = 0;j < k;++j)
		{
			if(queenarr[j] == i || abs(queenarr[j]-i) == abs(k-j))
				break;
		}
		if(j == k)
		{
			queenarr[k] = i;
			queensolt(k+1);
		}
	}
	return queen_count;
}

int main(int argc,char* argv[])
{
	cin >> N;
	memset(queenarr,0,sizeof(queenarr));
	
	cout << "Result:" << queensolt(0) << endl;
	
	return 0;
}