#include<stdio.h>
#define N 2

void input(struct student * p);
void chuli(struct student * p);

struct student 
{
	unsigned int age;
	char name[16];
	float score;
};

int main(int argc,char * argv[])
{
	struct student stu[N];
	input(stu);
	chuli(stu);

	return 0;
}

void input(struct student * p)
{
	int i;
	printf("������%d��ѧ������Ϣ��\n", N);
	for(i = 0; i < N; i++,p++)
	{
		printf("�������%dλѧ������Ϣ��\n",i + 1);
		printf("���֣�");
		scanf_s("%s", p->name,16);
		printf("\n");
		printf("���䣺");
		scanf_s("%d", &p->age);
		printf("\n");
		printf("�ɼ�:");
		scanf_s("%f", &p->score);
		printf("\n");
	}
}

/*������߳ɼ���ѧ����Ϣ*/
void chuli(struct student * p)
{
	struct student max = *p;
	int i;
	p++;
	//printf("%f", p->score);//Ϊʲô��һ�����һ�����룿
	for (i = 1; i < N; i++)
	{
		if (p->score > max.score)
			max = *p;
		p++;
	}
	printf("����ߵ���ϢΪ��\n");
	printf("���֣�%s\t ���䣺%d\t �ɼ���%f\t", max.name, max.age, max.score);
}