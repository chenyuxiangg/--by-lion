#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
/*
int main(int argc,char argv[])
{
	int a = 10;//��ʼ������ʱ��
	while(a >= 0)
	{
		system("cls");//������ɶ����  �����Ļ��ǰ��ʾ������  ��������������������ʾ��ʣ0�룬�Լ� �������
		printf("\r�����껹��%d��\n", a--);
		Sleep(1000);//˯�߻��ӳ�1000���룬Ҳ����1��
		//system("cls");//���ڴ˴����ֻ��ʾ �������
	}
	printf("������֣�\n");
	return 0;
}
*/

int main(int argc,char * argv[])
{
	int h = 0, m = 0, s = 0;
	while(1)
	{
		printf("\r������ 2017 �� 3 �� 18 �� %02d:%02d:%02d", h, m, s++);
		Sleep(1000);
		if(s == 60)
		{
			m++;
			s = 0;
			if (m == 60)
			{
				h++;
				m = 0;
				if (h == 12)
					return 0;
			}
		}
		system("cls");
	}
	return 0;
}