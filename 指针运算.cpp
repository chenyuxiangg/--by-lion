#include <stdio.h>
int main(void)
{
	int x = 10;
	int * p = &x;
	printf("p��ֵΪ%p\n",p);
	printf("*p++��ֵΪ%d\n", *p++);
	printf("p��ֵΪ%p\n", p);

	int xi = 10;
	int * pi = &xi;
	printf("pi��ֵΪ%p\n", pi);
	printf("(*pi)++��ֵΪ%d\n", (*pi)++);
	printf("*pi��ֵΪ%d\n", *pi);
	printf("pi��ֵΪ%p\n", pi);
	return 0;
}