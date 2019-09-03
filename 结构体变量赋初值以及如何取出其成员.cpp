# include <stdio.h>
struct student
{
	int age;
	float score;
	char sex;
};

int main(void)
{
	//第一种方式
	struct student st = { 80,66.6, 'F' };//初始化 定义的同时赋初值
	//第二种方式
	struct student st2;
	//取出结构体中的成员 方式一
	st2.age = 10;
	st2.score = 88;
	st2.sex = 'F';
	/*方式二
	int * pst;
	pst = &st;
	pst -> age;//相当于（*pst）.age 也相当于st.age
	*/
	printf("%d %f %c\n", st.age, st.score, st.sex);
	printf("%d %f %c\n", st2.age, st2.score, st2.sex);
	return 0;
}