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
		printf("������һԪ���η���ϵ����\n");
		printf("������a = ");
		scanf_s("%lf", &a);

		printf("������b = ");
		scanf_s("%lf", &b);

		printf("������c = ");
		scanf_s("%lf", &c);

		delta = b*b - 4 * a*c;
		x1 = (-b + sqrt(delta)) / (2 * a);
		x2 = (-b - sqrt(delta)) / (2 * a);


		if (delta == 0)
		{
			printf("������������ͬ��ʵ����\n");
			printf("x1 =x2 =%lf\n", x1);
		}

		if (delta < 0)
		{
			printf("������ʵ���������������\n");
		}

		if (delta > 0)
		{
			printf("��������������ȵ�ʵ����\n");
			printf("x1 = %lf,x2 = %lf\n", x1, x2);
		}
		printf("���Ƿ����������Y/N��\n");
		scanf_s(" %c", &ch);
	} while (ch == 'y' || ch == 'Y');
	return 0;

}