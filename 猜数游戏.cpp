/*
*��Ŀ���ƣ�������Ϸ
*��   �ߣ�Mr.c
*�������ڣ�2017/2/12
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//��������
int init();
int play(int);
void getscore(int);

//��ʼ��
/*
���ܣ��������һ��1~100����
���룺��
������������1~100
*/
int init()
{
	srand((unsigned)time(NULL));
	return (rand() % 100);
}

//��Ҳ²�
/*
���ܣ���Ҷ�β²����֣�ֱ���¶�Ϊֹ
���룺�����1~100
����������ܴ���
*/
int play(int cnum)
{
	int gnum;
	int gnumt = 1;

	printf("���������µ�����\n");
	scanf_s("%d", &gnum);

	do 
	{
		gnumt += 1;

		if(gnum < cnum)
		{
			printf("ƫС����~���������룺\n");
		}
		else
		{
			printf("�е�ƫ�󰡣����������룺\n");
		}

		scanf_s("%d", &gnum);
		//printf("%d", cnum);
		
	} while (gnum != cnum);

	return gnumt;
}



int main(void)
{
	int cnum = init();
	//printf("%d", cnum);
	int gnumt = play(cnum);
	getscore(gnumt);

	return 0;
}

//����
/*
���ܣ�ϵͳ���û���������ܽ�
���룺�û������ܴ���
������Ƿ������Y/y������N/n�˳�
*/
void getscore(int gnumt)
{
	if (gnumt <= 2)
		printf("�񰡣������Ȼ%d�ξͲ����ˣ�������һ��С�컨~\n", gnumt);
	else if (gnumt <= 5)
		printf("�����ϣ�����%d�ξͲ���~�������ͣ��������ܸ�����\n", gnumt);
	else
		printf("С���ӣ�����%d�βŲ��У�û������\n", gnumt);
}


