#include <stdio.h>
int main(void)
{
	int x, * pi;
	double y, * pd;

	pd = &y;
	pi = &x;

	printf("pi��ֵΪ%p\n", pi);
	printf("pi + 1��ֵΪ%p\n", pi + 1);
	printf("pi - 1��ֵΪ%p\n", pi - 1);
	printf("pd��ֵΪ%p\n", pd);
	printf("pd + 1��ֵΪ%p\n", pd + 1);
	printf("pd - 1��ֵΪ%p\n", pd - 1);
	return 0;

}