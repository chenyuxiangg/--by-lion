#include <iostream>
#include <cmath> 
using namespace std;

struct pai{
	int count;
	int flag;
	pai(){
		count = 4;
	}
};

bool is_bao(int i,int j,int k);
bool is_shun(int i,int j,int k);
bool is_dui(int i,int j,int k);
int getequ(int i,int j,int k);
int getsingle(int i,int j,int k);
int mymin(int i,int j,int k);
int mymax(int i,int j,int k);

int main(int argc,char* argv[])
{
	pai arr[10];
	int result = 0;
	for(int i = 1;i < 10;++i)
	{
		arr[i].flag = i;
	}
	
	int i,j,k;
	cin >> i >> j >> k;
	arr[i].count--;
	arr[j].count--;
	arr[k].count--;
	
	if(is_bao(i,j,k))
	{
		result += 9-i+1;
	}
	else if(is_shun(i,j,k))
	{
		int min = mymin(i,j,k)+1;
		while(min+2 <= 9)
		{
			result++;
		}
		result += 9;
	}
	else if(is_dui(i,j,k))
	{
		int e = getequ(i,j,k);
		int s = getsingle(i,j,k);
		
		result += 9-s;
		result += 8*(9-e);
		result += 7;
		result += 9;
	}
	else
	{
		int max = mymax(i,j,k);
		result += (9-max)*7*8;
		result += 8*9;
		result += 7;
		result += 9;
	}
	
	cout << result << endl;
	return 0;
} 

bool is_bao(int i,int j,int k)
{
	if(i == j && i == k)
	{
		return true;
	}
	return false;
}

bool is_shun(int i,int j,int k)
{
	if((fabs(i-j) >= 1 && fabs(i-j) <=2 ) && (fabs(i-k) >= 1 && fabs(i-k) <= 2))
	{
		return true;
	}
	return false;
}

bool is_dui(int i,int j,int k)
{
	if(i == j || i == k || j == k)
	{
		return true;
	}
	return false;
}

int mymin(int i,int j,int k)
{
	if(i < j)
	{
		return i < k ? i : k;
	}
	else
	{
		return j < k ? j : k;
	}
}

int getequ(int i,int j,int k)
{
	return i == j ? i : j;
}

int getsingle(int i,int j,int k)
{
	return i == j ? k : i;
}

int mymax(int i,int j,int k)
{
	if(i > j)
	{
		return i > k ? i : k;
	}
	else
	{
		return j > k ? j : k;
	}
}
