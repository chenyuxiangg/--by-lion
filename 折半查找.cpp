#include<stdio.h>
#define N 5
/*�۰���Һ���ʵ��*/
int zserch(int a[], int n, int x)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if (a[mid] == x)
			return 1;
		else if (a[mid] < x)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

/*������*/
int main (int argc,char* argv[])
{
	int a[N];
	int i, x, t;

	printf("�������СΪ%d�ĵ������飺", N);
	for (i = 0; i < N; i++)
	{
		scanf_s("%d", &a[i]);
	}
	printf("�����������Ϊ��");
	for (i = 0; i < N; i++)
		printf("%4d", a[i]);
	printf("\n");

	printf("��������Ҫ���ҵ�����");
	scanf_s("%d", &x);
	t = zserch(a, N, x);
	
	if (t == 1)
		printf("���ҳɹ���");
	else
		printf("�Բ��𣬲��޴�����");

	return 0;
}