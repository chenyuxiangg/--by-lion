#include<stdio.h>
#define N 10
/*���뺯��*/
void input(int a[],int n)
{
	int i;
	printf("������%d��Ԫ�أ�",N);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);

	}
	printf("\n");
}

/*�������*/
void output(int a[],int n)
{
	int i;
	printf("Ԫ��Ϊ��");
	for (i = 0; i < n; i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}

/*�����ֵ�����±�*/
void mani(int a[],int n)
{
	int i;
	int max = a[0];
	int maxid;

	for (i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			maxid = i;
		}
	
	}
	printf("����������Ԫ��Ϊ%d,���±�Ϊ%d.\n", max, maxid + 1);
	printf("\n");
}

int main(void)
{
	int a[N];
	input(a, N);
	output(a, N);
	mani(a, N);

	return 0;
}