#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char argv[])
{//ȭ����Ϸ�����ĺ��ƣ��ҷ��ȳ�ȭ�����Ժ��ȭ��
 //��ȭ������1~10
 //����ֵ��30

	int mylife = 30;//�ҷ�����ֵ
	int enemy = 30;//���Է�����ֵ
	int power;//����

	srand((unsigned)time(NULL));//��ʼ�����������

	while(1)
	{
		system("pause");//�ҷ���ȭ
		power = rand() % 10 + 1;//�õ������ֵ��1��10֮�����

		//������ԣ����������
		enemy -= power;
		//�жϵ��Է��Ѿ�û������
		if(enemy <= 0)
		{//���Է��Ѿ�û������
			printf("\n��������ɹ�KO�˵���\n");
			break;
		}
		printf("\n�ҷ����˵���һȭ������Ϊ%d,���Է�������Ϊ%d�����Է���ʣ������%d\n",power,power,enemy);

		//���Է���ȭ
		power = rand() % 10 + 1;
		mylife -= power;

		if(mylife <= 0)
		{
			printf("\n���ź����㱻����over��\n");
			break;
		}
		printf("\n���Դ�����һȭ������Ϊ%d�������%d�����������������ʣ��%d\n", power, power, mylife);


	}
	return 0;
}