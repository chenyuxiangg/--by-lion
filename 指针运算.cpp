#include <stdio.h>
int main(void)
{
	int x = 10;
	int * p = &x;
	printf("p的值为%p\n",p);
	printf("*p++的值为%d\n", *p++);
	printf("p的值为%p\n", p);

	int xi = 10;
	int * pi = &xi;
	printf("pi的值为%p\n", pi);
	printf("(*pi)++的值为%d\n", (*pi)++);
	printf("*pi的值为%d\n", *pi);
	printf("pi的值为%p\n", pi);
	return 0;
}