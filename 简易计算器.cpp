#include <stdio.h>
double add(double * a, double * b)
{
	return (*a + *b);
}

double sub(double * a,double * b)
{
	return (*a - *b);
}

double mul(double * a,double * b)
{
	return (*a * *b);
}

double div(double * a,double * b)
{
	return (*a / *b);
}
int main(void)
{
	double a, b;
	char ch,sh;

	do {
		printf("«Î ‰»Î£∫\n");
		scanf_s("%lf", &a);
		scanf_s(" %c", &ch);
		scanf_s("%lf", &b);

		if (ch == '+')
		{
			add(&a, &b);
			printf("a %c b = %lf", ch, a + b);
		}
		else if (ch == '-')
		{
			sub(&a, &b);
			printf("a %c b = %lf", ch, a - b);
		}
		else if (ch == '*')
		{
			mul(&a, &b);
			printf("a %c b = %lf", ch, a * b);
		}
		else if (ch == '/')
		{
			div(&a, &b);
			printf("a %c b = %lf", ch, a / b);
		}
		printf("ƒ˙ «∑ÒºÃ–¯£ø£®Y/N£©\n");
		scanf_s(" %c", &sh);
	} while (sh == 'y' || sh == 'Y');
	return 0;

}