//求数的平方根公式：x1 = 1/2 * (x0 + a/x0),求a的平方根

#include<stdio.h>
#include<math.h>
int main(int argc,char * argv[])
{
	double a, x0, x1;
	printf("请输入您所要求的数:");
	scanf_s("%lf", &a);

	x0 = a / 2;
	x1 = (x0 + a / x0)/2;
	//printf("x0 = %lf", x0);

	do
	{
		x0 = x1;
		x1 = (x0 + a / x0)/2;//注意：除以某个数不能写成乘以这个数的倒数
	} while (fabs(x0 - x1) >= 1e-6);
	printf("%lf的平方根是%lf", a, x1);
	return 0;
}