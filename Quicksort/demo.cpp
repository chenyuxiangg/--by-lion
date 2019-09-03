#include <iostream>
#include <windows.h>
#include <ctime>
#include "Quicksort.h"
using namespace std;

int main(int argc,char* argv[])
{
	LARGE_INTEGER nFreq;//LARGE_INTEGER 是一个含结构的结构体
	LARGE_INTEGER start;
	LARGE_INTEGER end;
	QueryPerformanceFrequency(&nFreq);//返回硬件支持的高精度计数器的频率  原型：BOOL QueryPerformanceFrequency(LARGE_INTEGER *lpFrequency);
	QueryPerformanceCounter(&start);

	//随机生成数组
	const int n = 50;
	int i_arr[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		i_arr[i] = rand() % 100;
	cout << "系统为您生成的数组为：" << endl;
	for (int j = 0; j < n; j++)
	{
		if (j % 10 == 0)
			cout << endl;
		cout << i_arr[j] << " ";
	}
	cout << endl;
	/*cout << "请输入5个数：" << endl;
	for (int i = 0; i < n; i++)
		cin >> i_arr[i];*/

	//排序后
	Quicksort(i_arr, n, 0, n-1);
	cout << "----------------------------------------------" << endl;
	for (int j = 0; j < n; j++)
	{
		if (j % 10 == 0)
			cout << endl;
		cout << i_arr[j] << " ";
	}
	cout << endl;
	QueryPerformanceCounter(&end);
	double i_time = (end.QuadPart - start.QuadPart) / (double)nFreq.QuadPart;
	cout << "程序运行的时间为：" << i_time << "微秒" << endl;

	system("pause");
	return 0;
}