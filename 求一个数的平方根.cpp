//������ƽ������ʽ��x1 = 1/2 * (x0 + a/x0),��a��ƽ����

#include<stdio.h>
#include<math.h>
int main(int argc,char * argv[])
{
	double a, x0, x1;
	printf("����������Ҫ�����:");
	scanf_s("%lf", &a);

	x0 = a / 2;
	x1 = (x0 + a / x0)/2;
	//printf("x0 = %lf", x0);

	do
	{
		x0 = x1;
		x1 = (x0 + a / x0)/2;//ע�⣺����ĳ��������д�ɳ���������ĵ���
	} while (fabs(x0 - x1) >= 1e-6);
	printf("%lf��ƽ������%lf", a, x1);
	return 0;
}