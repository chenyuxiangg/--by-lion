#include<stdio.h>
#include<malloc.h>
int main(void)
{
	int * p;
	int i = 5;

	p = (int *)malloc(sizeof(int));
	p = &i;

	printf("%d", *p);
	return 0;
}