/*����*/
#include<stdio.h>
#define N 6
/*���ú���*/
void invert(int a[],int n)
{
	int i,t;
	for (i = 0; i < n / 2; i++)
	{
		t = a[i];
		a[i] = a[n - 1 -i];
		a[n - 1 - i] = t;

	}
	printf("\n");
}
/*���뺯��*/
void input(int a[],int n)
{
	int i;
	printf("������Ԫ�أ�");
	for(i = 0; i < N; i++)
	{
		scanf_s("%d", &a[i]);
	}
	printf("\n");
}
/*�������*/
void output(int a[], int n)
{
	int i;
	printf("Ԫ��Ϊ��");
	for (i = 0; i < N; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
}

int main(void)
{
	int a[N];
	printf("����Ԫ�ظ�����%d\n", N);
	input(a, N);
	output(a, N);
	invert(a, N);
	printf("���ú�Ľ���ǣ�\n");
	output(a, N);
	return 0;
}