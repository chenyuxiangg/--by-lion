#include<stdio.h>
#define N 10
/*���Һ�����ʵ��*/
int serch(int a[],int n,int x)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (a[i] == x)
			break;
	}
	if (i < n)
	{
		return i + 1;
	}
	return -1;
}

/*������*/
int main(int argc, char * argv[])
{
	int a[N];
	int i, x, t, p;
	char ch;

	printf("������%d���������س�������", N);
	for(i = 0; i < N; i++)
	{
		scanf_s("%d", &a[i]);
	}
	printf("�����������Ϊ��");
	for (i = 0; i < N; i++)
		printf("%d", a[i]);
	printf("\n");

	for(p = 0;; p++)
	{
		printf("��~������Ҫ���ҵ����֣����ǽ����������ţ�");
		scanf_s("%d", &x);
		t = serch(a, N, x);
		if (t != -1)
			printf("���ҳɹ���%d�����Ϊ %d\n", x, t);
		else
			printf("�Բ��𣬲��޴�����\n");

		printf("���Ƿ�������ң���y/n��\n");
		scanf_s(" %c", &ch);//���뵥���ַ�ʱ����Ҫ�� %c",%��ǰ�����пո�
		if (ch == 'n')
			break;
	}

	return 0;
}