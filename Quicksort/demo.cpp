#include <iostream>
#include <windows.h>
#include <ctime>
#include "Quicksort.h"
using namespace std;

int main(int argc,char* argv[])
{
	LARGE_INTEGER nFreq;//LARGE_INTEGER ��һ�����ṹ�Ľṹ��
	LARGE_INTEGER start;
	LARGE_INTEGER end;
	QueryPerformanceFrequency(&nFreq);//����Ӳ��֧�ֵĸ߾��ȼ�������Ƶ��  ԭ�ͣ�BOOL QueryPerformanceFrequency(LARGE_INTEGER *lpFrequency);
	QueryPerformanceCounter(&start);

	//�����������
	const int n = 50;
	int i_arr[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		i_arr[i] = rand() % 100;
	cout << "ϵͳΪ�����ɵ�����Ϊ��" << endl;
	for (int j = 0; j < n; j++)
	{
		if (j % 10 == 0)
			cout << endl;
		cout << i_arr[j] << " ";
	}
	cout << endl;
	/*cout << "������5������" << endl;
	for (int i = 0; i < n; i++)
		cin >> i_arr[i];*/

	//�����
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
	cout << "�������е�ʱ��Ϊ��" << i_time << "΢��" << endl;

	system("pause");
	return 0;
}