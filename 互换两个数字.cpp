#include <stdio.h>
void swap(int * p, int * q)
{
	int t;

	t = *p;
	*p = *q;
	*q = t;
	return;
}
int main(void)
{
	int a = 3;
	int b = 5;
	swap(&a, &b);
	printf("a = %d,b = %d\n", a, b);
	return 0;
}