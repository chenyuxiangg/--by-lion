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
	printf("请输入%d个学生的信息：\n", N);
	for(i = 0; i < N; i++,p++)
	{
		printf("请输入地%d位学生的信息：\n",i + 1);
		printf("名字：");
		scanf_s("%s", p->name,16);
		printf("\n");
		printf("年龄：");
		scanf_s("%d", &p->age);
		printf("\n");
		printf("成绩:");
		scanf_s("%f", &p->score);
		printf("\n");
	}
}

/*查找最高成绩的学生信息*/
void chuli(struct student * p)
{
	struct student max = *p;
	int i;
	p++;
	//printf("%f", p->score);//为什么这一步输出一个乱码？
	for (i = 1; i < N; i++)
	{
		if (p->score > max.score)
			max = *p;
		p++;
	}
	printf("最高者的信息为：\n");
	printf("名字：%s\t 年龄：%d\t 成绩：%f\t", max.name, max.age, max.score);
}