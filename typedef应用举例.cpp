#include<stdio.h>

typedef struct 
{
	int year;
	int month;
	int day;
}DATE;

DATE day1;//����һ���ṹ�����

void input(DATE *d)
{
	printf("������ �� �� �գ�");
	scanf_s("%d%d%d", &d->year, &d->month, &d->day);
	printf("���������%d��%d��%d��", d->year, d->month, d->day);
	printf("\n");
}

int z(DATE d)
{
	int daysum = 0;
	switch(d.month)
	{case 1:
		daysum = d.day;
		break;
	case 2:
		daysum = d.day + 31;
		break;
	case 3:
		daysum = d.day + 59;
		break;
	case 4:
		daysum = d.day + 90;
		break;
	case 5:
		daysum = d.day + 120;
		break;
	case 6:
		daysum = d.day + 151;
		break;
	case 7:
		daysum = d.day + 181;
		break;
	case 8:
		daysum = d.day + 212;
		break;
	case 9:
		daysum = d.day + 243;
		break;
	case 10:
		daysum = d.day + 274;
		break;
	case 11:
		daysum = d.day + 304;
		break;
	case 12:
		daysum = d.day + 334;
		break;
	}
	return daysum;
}

/*void output(DATE d)
{
	int t;
	t = z(&d);
	printf("%d��%d��%d����%d���ǵ�%d��\n",d.year,d.month,d.day,d.year,t);
}*/

int main(int argc,char * argv[])
{
	int daysum;
	/*printf("������ �� �� �գ�");
	scanf_s("%d%d%d", &day1.year, &day1.month, &day1.day);
	printf("���������%d��%d��%d��", day1.year, day1.month, day1.day);
	printf("\n");*/
	input(&day1);//�������input��DATE d)���ܽ������ֵ����z(d)����������ʱ��Ҫ����ַ
	daysum = z(day1);//������ﶨ��ָ�����ͣ���z��d�������z(*d)Ҳ�У�Ч��һ��
	//output(day1);
	printf("%d��%d��%d����%d��ĵ�%d��\n",day1.year,day1.month,day1.day,day1.year, daysum);

	return 0;
}
