#include <stdio.h>
#include<malloc.h>

struct student
{
	int age;
	float score;
	char name[100];
};//创建一个结构体，结构体是一个数据类型
int main(void)
{
	int len, i, j;
	struct student * parr;//定义一个指针，相当于一个数组，他的元素是所有学生
	struct student t;

	printf("请输入学生人数：\n");
	printf("len = ");
	scanf_s("%d", &len);

	parr = (struct student *)malloc(len * sizeof(struct student));//动态构造一维数组

	for (i = 0; i < len; ++i)
	{
		printf("请输入第%d个学生的信息：\n", i + 1);
		printf("age = ");
		scanf_s("%d", &parr[i].age);//由于parr是struct student 类型的，所以他的每一个元素（学生）都是结构体类型，取出结构体的元素，就用  结构体变量名.成员名

		printf("name = ");
		scanf_s("%s", parr->name,100);//name是数组名，本身就已经是数组首元素的地址，所以parr[i].name
								   //不能写成&parr[i].name

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

	printf("\n\n学生的信息是：\n");
	//输出
	for (i = 0; i < len; ++i)
	{
		printf("输出第%d个学生的信息：", i + 1);
		printf("age = %d\n", parr[i].age);
		printf("name = %s\n", parr[i].name);
		printf("score = %f\n", parr[i].score);
		printf("\n");
	}

	return 0;
}