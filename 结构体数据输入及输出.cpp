/*通过函数对结构体进行输入输出*/

#include <stdio.h>
#include <string.h>
struct student
{
	int age;
	char name[100];
	char sex;
};
void Inputstudent(struct student * pstu);//函数使用前必须先声明

void Outputstudent(struct student * pst);

int main(void)
{
	/*
	struct student
	{
	int age;
	float score;
	char sex;
	};//分号不能省
	struct student st = { 10,66.6,'F' };

	struct student * pst;
	pst = &st;

	printf("%d %f %c", pst->age, pst->score, pst->sex);
	return 0;
	*/
	struct student st;

	Inputstudent(&st);//对结构体变量输入，必须发送st的地址
	Outputstudent(&st);//对结构体变量输出，可以发送st地址也可发送内容

	return 0;
}
void Inputstudent(struct student * pstu)//输入输出都不需要返回值
{
	pstu->age = 10;//pstu只占4个字节
	strcpy_s(pstu->name, "张三");
	pstu->sex = 'F';
}

/*
void Outputstudent(struct student ss)//这种写法也正确，但一般用指针，用这种方法相当于把st的内容
                                       复制到ss中,但用指针也有危险，内容可以改写，但可以通过加const
									   解决
{
	printf("%d %c %s\n", ss.age, ss.sex, ss.name);
}
*/
void Outputstudent(struct student * pst)//发送地址的好处  可以快速传递数据，且占用内存小
{
	printf("%d %c %s\n", pst->age, pst->sex, pst->name);
}