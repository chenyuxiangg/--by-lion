#include <stdio.h>
#include <windows.h>
int main()
{
	int pass, i = 0, p = 5;
	printf("��ע���ܱ߻�����ȫ����\n");
		while (1)
		{
			scanf_s("%d", &pass);
			if (pass != 123456)
				printf("������������%d��\n",++i);
			if (i >= 3)
			{
				printf("�Բ������Ŀ�����������ϵ��������~\n");
				while (i == 3 && p >= 0)
				{
					printf("\r%d����˳�ϵͳ��������\n",p--);
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
				return 0;
			}
		

		}
}
