#include <stdio.h>
#include<malloc.h>

struct student
{
	int age;
	float score;
	char name[100];
};//����һ���ṹ�壬�ṹ����һ����������
int main(void)
{
	int len, i, j;
	struct student * parr;//����һ��ָ�룬�൱��һ�����飬����Ԫ��������ѧ��
	struct student t;

	printf("������ѧ��������\n");
	printf("len = ");
	scanf_s("%d", &len);

	parr = (struct student *)malloc(len * sizeof(struct student));//��̬����һά����

	for (i = 0; i < len; ++i)
	{
		printf("�������%d��ѧ������Ϣ��\n", i + 1);
		printf("age = ");
		scanf_s("%d", &parr[i].age);//����parr��struct student ���͵ģ���������ÿһ��Ԫ�أ�ѧ�������ǽṹ�����ͣ�ȡ���ṹ���Ԫ�أ�����  �ṹ�������.��Ա��

		printf("name = ");
		scanf_s("%s", parr->name,100);//name����������������Ѿ���������Ԫ�صĵ�ַ������parr[i].name
								   //����д��&parr[i].name

		printf("score = ");
		scanf_s("%f", &parr[i].score);
	}
	for (i = 0; i < len; ++i)
	{
		for (j = 0; j < len - 1 - i; ++j)
		{
			if (parr[j].score > parr[j + 1].score)
			{
				t = parr[j];
				parr[j] = parr[j + 1];
				parr[j + 1] = t;
			}
		}
	}

	printf("\n\nѧ������Ϣ�ǣ�\n");
	//���
	for (i = 0; i < len; ++i)
	{
		printf("�����%d��ѧ������Ϣ��", i + 1);
		printf("age = %d\n", parr[i].age);
		printf("name = %s\n", parr[i].name);
		printf("score = %f\n", parr[i].score);
		printf("\n");
	}

	return 0;
}