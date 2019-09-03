#include <iostream>
#include <cstring>    //memset(),memcpy头文件
using namespace std;

//获取第j位
int Getbit(int num,int j)
{
    return (num >> j)&1;
}
//设置第j位
void Setbit(char& num,int j, int s)
{
    if(s)
		num |= (1 << j);
	else
		num &= ~(1 << j);
}
//反转第j位
void Flipbit(char& num,int j)
{
	num ^= (1 << j);
}

int main(int argc,char* argv[])
{
	char orilight[5];//原始灯状态
	char curlight[5];//当前灯的状态
	char result[5];  //结果
	int switchs;     //开关状态
	bool flag = false;//判断是否有结果
	
	//初始化原始灯状态
	memset(orilight,0,sizeof(orilight));
	for(int i = 0;i < 5;++i)
		for(int j = 0;j < 6;++j)
		{
			int single;
			cin >> single;
			Setbit(orilight[i],j,s);
		}
	//确定结果
	for(int n = 0;n < 64;++n)
	{
		switchs = n;
		memcpy(curlight,orilight,sizeof(orilight));//每执行一次枚举就将原始灯的状态存到当前灯矩阵中
												   //以保证每次测试结果都不会改变原始状态
		//处理每一行灯的状态
		for(int i = 0;i < 5;++i)
		{
			result[i] = switchs;
			for(int j = 0;j < 6;++j)
			{
				if(Getbit(switchs,j))
				{
					if(j > 0)
						Flipbit(curlight[i],j - 1);
					Flipbit(curlight[i],j);
					if(j < 5)
						Flipbit(curlight[i],j+1);
				}
			}
			//处理第i+1行灯的状态
			if(j < 4)
				curlight[i+1] ^= switchs;
			switchs = curlight[i];
		}
		//当第五行的灯熄灭时，找到结果
		if(curlight[4] == 0)
		{
			flag = true;
			break;
		}
	}
	if(flag)
	{
		for(int i = 0;i < 5;++i)
		{
			for(int j = 0;j < 6;++j)
			{
				cout << Getbit(result[i],j) << " ";
			}
			cout << endl;
		}
	}
	else
		cout << "no anwser" << endl;
	
	return 0;
}