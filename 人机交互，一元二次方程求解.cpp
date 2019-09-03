#include <stdio.h>
#include <math.h>
int main(void)
{
	double a, b, c;
	double delta;
	double x1, x2;

	char ch;

	do
	{
		printf("请输入一元二次方程系数：\n");
		printf("请输入a = ");
		scanf_s("%lf", &a);

		printf("请输入b = ");
		scanf_s("%lf", &b);

		printf("请输入c = ");
		scanf_s("%lf", &c);

		delta = b*b - 4 * a*c;
		x1 = (-b + sqrt(delta)) / (2 * a);
		x2 = (-b - sqrt(delta)) / (2 * a);


		if (delta == 0)
		{
			printf("方程有两个相同的实数根\n");
			printf("x1 =x2 =%lf\n", x1);
		}

		if (delta < 0)
		{
			printf("方程无实数根，有两个虚根\n");
		}

		if (delta > 0)
		{
			printf("方程有两个不相等的实属根\n");
			printf("x1 = %lf,x2 = %lf\n", x1, x2);
		}
		printf("您是否还想继续？（Y/N）\n");
		scanf_s(" %c", &ch);
	} while (ch == 'y' || ch == 'Y');
	return 0;

}