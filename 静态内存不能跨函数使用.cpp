#include <stdio.h>
int f(int **q)
{
	int i = 5;
	*q = &i;

}
int main(void)
{
	int * p;
	f(&p);
	printf("%d\n", *p);//error,因为i 是静态变量，当f（）执行完后就被释放，故不能输出
	return 0;
}