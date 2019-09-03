#include<stdio.h>

typedef struct 
{
	int year;
	int month;
	int day;
}DATE;

DATE day1;//定义一个结构体变量

void input(DATE *d)
{
	printf("请输入 年 月 日：");
	scanf_s("%d%d%d", &d->year, &d->month, &d->day);
	printf("您输入的是%d年%d月%d日", d->year, d->month, d->day);
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
	printf("%d年%d月%d日在%d年是第%d天\n",d.year,d.month,d.day,d.year,t);
}*/

int main(int argc,char * argv[])
{
	int daysum;
	/*printf("请输入 年 月 日：");
	scanf_s("%d%d%d", &day1.year, &day1.month, &day1.day);
	printf("您输入的是%d年%d月%d日", day1.year, day1.month, day1.day);
	printf("\n");*/
	input(&day1);//如果定义input（DATE d)则不能将输入的值传入z(d)，传入数据时需要传地址
	daysum = z(day1);//如果这里定义指针类型，即z（d）定义成z(*d)也行，效果一样
	//output(day1);
	printf("%d年%d月%d日是%d年的第%d天\n",day1.year,day1.month,day1.day,day1.year, daysum);

	return 0;
}
