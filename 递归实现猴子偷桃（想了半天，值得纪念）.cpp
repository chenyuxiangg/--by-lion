#include <iostream>
using namespace std;
int sum = 0;
int fun(int n,int m)
{
	int t = 0;
	if(n == 1)
	{
		return m;
	}
	
	else
	{
		t = 2*fun(n-1,m) + 1;
		sum += t;
		return t;
	}
}

int main()
{
	int n;
	int m;
	
	cin >> n >> m;
	sum = m;
	fun(n,m);
	
	cout << sum << endl;
	
	return 0;
}
