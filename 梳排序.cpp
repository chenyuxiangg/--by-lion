#include "iostream"
using namespace std;

void swap(int* a, int* b)
{
	int* t = a;
	a = b;
	b = t;
}

void comsort(int a[],int count)
{
	const double A = 1.3;
	int delta = count, i,Swap = 1;
	while(Swap)
	{
		if (delta > 1)
		{
			delta /= A;
			//noSwap = 0;
		}
		for (Swap = 0, i = 0;i + delta < count;i++)
		{
			if(a[i] > a[i + delta])
			{
				swap(a[i], a[i + delta]);
				Swap = 1;//���������ھ���whileѭ������
			}
		}
	}
	void print(int a[], int count);
	print(a, count);
}

void print(int a[],int count)
{
	int i;
	for (i = 0; i < count; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main(int argc,char* argv[])
{
	int arr[10] = { 5,9,4,6,3,2,7,8,0,1 };
	cout << "����ǰ��" << endl;
	print(arr, 10);
	cout << "�����" << endl;
	comsort(arr, 10);

	return 0;
}