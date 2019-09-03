/*
*项目名称：模拟龟兔赛跑
*作者：Mr.c
*开发日期：2017年2月11日
*/
#include<stdio.h>
double tspeek;//乌龟的速度
double rspeek;//兔子的速度
double xtime;//兔子睡觉时间
double lng;//全长

/*
*功能：赛前准备，都去比赛相关信息
*输入：无
*输出：无
*/
void init()//游戏初始化
{
	printf("请输入乌龟的速度：\n");
	scanf_s("%lf", &tspeek);//记得在定义全局变量后，如果输出的结果和想要的不符，考虑输入符号
	printf("请输入兔子的速度：\n");
	scanf_s("%lf", &rspeek);
	printf("请输入兔子睡觉时间：\n");
	scanf_s("%lf", &xtime);
	printf("请输入全长：\n");
	scanf_s("%lf", &lng);
	//测试语句
	//printf("ts = %f,rs = %f,len = %f,xt = %f", tspeek, rspeek, lng, xtime);
	printf("--------------------------------------------------------\n");

}

/*
*功能：模拟龟兔赛跑过程
*输入：赛道总长
*输出：乌龟所用时间
*/
double trun(double lng)
{
	double t;
	t = lng / tspeek;
	printf("乌龟所用时间为：%.2lf\n", t);
	return (t);
}

/*
*功能：模拟龟兔赛跑过程
*输入：赛道总长
*输出：兔子所用时间
*/
double rrun(double lng)
{
	double t;
	t = lng / rspeek;
	printf("兔子跑了%.2lf\n", t);
	printf("兔子睡了%.2lf\n", xtime);
	printf("兔子所用总时间为：%.2lf\n", t + xtime);
	return (t + xtime);
}

/*
*功能：模拟龟兔赛跑过程
*输入：无
*输出：无
*/
void start()
{
	double Tt;
	double Tr;
	printf("比赛现在开始！！\n");
	printf("下面，由我给大家实况转播！！\n");
	printf("\n");
	printf("现在我们看到的是乌龟选手！小乌龟虽然爬得慢，但他依然锲而不舍，为了心中的目标目标勇敢前进！！\n");
	printf("让我们为小乌龟加油！\n");
	printf("接下来就是小兔子，众所周知，兔子的奔跑速度比乌龟快多了……\n");
	printf("啊？？？？，小兔子居然找到一处荫凉，居然开始睡觉了！！！\n");
	printf("小兔子居然这么自信，结果如何，让我们拭目以待吧！\n");
	printf("\n");
	printf("接下来就是激动人心的时刻！\n");
	printf("让我们一起看看\n");
	printf("------------------------------------------------------------\n");
	
	Tt = trun(lng);
	printf("\n");
	Tr = rrun(lng);
	printf("\n");

	if (Tt < Tr)
		printf("哇~ 功夫不负有心人，乌龟经过不懈努力，终于战胜了兔子！！！\n");
	else if (Tt > Tr)
		printf("果然还是兔子更快！\n");
	else
		printf("奇迹出现了！！乌龟和兔子同时到达！！\n");
	
}
int main(void)
{
	init();
	start();

	return 0;

}