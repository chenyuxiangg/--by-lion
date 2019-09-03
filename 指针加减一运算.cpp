#include <stdio.h>
int main(void)
{
	int x, * pi;
	double y, * pd;

	pd = &y;
	pi = &x;

	printf("pi的值为%p\n", pi);
	printf("pi + 1的值为%p\n", pi + 1);
	printf("pi - 1的值为%p\n", pi - 1);
	printf("pd的值为%p\n", pd);
	printf("pd + 1的值为%p\n", pd + 1);
	printf("pd - 1的值为%p\n", pd - 1);
	return 0;

}