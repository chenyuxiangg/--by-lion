#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include<stdlib.h>

double money = 0.0;
char ch;

int main()
{
	int pass, i = 0, p = 5;
	printf("��ע���ܱ߻�����ȫ����\n");
	printf("\n");
	printf("�������������룺\n");
	while (1)
	{
		scanf_s("%d", &pass);
		if (pass != 123456)
			printf("������������%d��\n", ++i);
		if (i >= 3)
		{
			printf("�Բ������Ŀ�����������ϵ��������~\n");
			while (i == 3 && p >= 0)
			{
				printf("\r%d����˳�ϵͳ��������\n", p--);
				Sleep(1000);
			}

			return -1;
		}
		if (pass == 123456)
		{
			printf("������ȷ�����ڽ���ϵͳ����\n");
			while (p >= 0)
			{
				printf("\r%d������ϵͳ����\n", p--);
				Sleep(1000);
			}
			/*
			#��Ŀ���ƣ�ģ������ATM�Զ���ȡ���
			#��   �ߣ�Mr.c
			#��   �ڣ�2017/02/16
			*/

			int menu();//�˵��б�����ѡ��
			double cmoney();//�����ǰ���
			void getmoney(int);//��Ǯ
			void withdraw(int);//ȡǮ

			ch = menu();
			printf("====================================\n");
			int temp;

			while (ch != 0)
			{
				switch (ch)
				{
				case 1:
					printf("����ǰ�����Ϊ %.2lf\n", cmoney());
					break;
				case 2:
					printf("���������Ĵ���:\n");
					scanf_s("%ld", &temp);
					getmoney(temp);
					printf("����ǰ�����Ϊ %.2lf\n", cmoney());
					break;
				case 3:
					printf("����������ȡ����:\n");
					scanf_s("%ld", &temp);
					withdraw(temp);
					printf("����ǰ�����Ϊ %.2lf\n", cmoney());
				}
				printf("\n\n");
				_getch();//��ͣ�����û����壬�����������
				ch = menu();
			}
			printf("===============================================\n");
			printf("ллʹ���й����У����ǽ��߳�Ϊ������\n");
			return 0;
		}


	}
}

/*
#���ܣ���ʾ�˵��б�����ѡ��
#���룺��
#���������ѡ�������
*/
int menu()
{
	int i;
	printf("��ӭʹ���й����У����ǽ��߳�Ϊ������\n");
	printf("=========================================\n");
	printf("��ѡ��������ķ���\n");
	printf("\n");
	printf("1.��ѯ���\t 2.���\n");
	printf("3.ȡ��\t     0.�˳�\n");
	scanf_s("%d", &i);
	return i;
}

/*
#���ܣ�������
#���룺���
#�������
*/
void getmoney(int x)
{
	money = money + x;
}

/*
#���ܣ�ȡ�����
#���룺���
#�������
*/
void withdraw(int x)
{
	if (x > money)
	{
		printf("�������㡣\n");
	}
	else
		money = money - x;
}

/*
#���ܣ���ǰ���
#���룺��
#�������ǰ���
*/
double cmoney()
{
	return money;
}
