#include<stdio.h>
#include<string.h>
#define M 2

struct person
{
	char name[16];
	int coun = 0;
};
void input(struct person ld[],int n)
{
	int i;
	printf("请输入%d个候选人的基本信息：\n",M);
	for (i = 0; i < n; i++)
	{
		printf("姓名：");
		scanf_s("%s", ld[i].name,16);
	}
}

int vote(struct person ld[],int n)
{
	char ename[16];
	int i, j, m, t;
	printf("此次参加投票的人数为：");
	scanf_s("%d", &m);
	printf("\n");
	for (i = 0; i < m; i++)
	{
		printf("您想要投：");
		scanf_s("%s", ename,16);
		for (j = 0; j < n; j++)
		{
			if (strcmp(ld[j].name, ename))
				ld[j].coun++;
		}
	}
	printf("\n");
	return ld[j].coun;
}

void output(struct person ld[],int n)//在自定义函数中定义结构体或结构体数组时，需要写标志 struct,数据类型 如person
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("第%d位候选人的信息：\n",i + 1);
		printf("姓名：%s\t",ld[i].name);//当使用结构体变量获取结构体数组成员时，如此
		printf("票数：%d\n",ld[i].coun);
	}
}

int main(int argc, char * argv[])
{
	struct person leader[M];
	input(leader, M);
	vote(leader, M);
	output(leader, M);

	return 0;
}