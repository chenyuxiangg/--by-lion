/*
*��Ŀ���ƣ�ģ���������
*���ߣ�Mr.c
*�������ڣ�2017��2��11��
*/
#include<stdio.h>
double tspeek;//�ڹ���ٶ�
double rspeek;//���ӵ��ٶ�
double xtime;//����˯��ʱ��
double lng;//ȫ��

/*
*���ܣ���ǰ׼������ȥ���������Ϣ
*���룺��
*�������
*/
void init()//��Ϸ��ʼ��
{
	printf("�������ڹ���ٶȣ�\n");
	scanf_s("%lf", &tspeek);//�ǵ��ڶ���ȫ�ֱ������������Ľ������Ҫ�Ĳ����������������
	printf("���������ӵ��ٶȣ�\n");
	scanf_s("%lf", &rspeek);
	printf("����������˯��ʱ�䣺\n");
	scanf_s("%lf", &xtime);
	printf("������ȫ����\n");
	scanf_s("%lf", &lng);
	//�������
	//printf("ts = %f,rs = %f,len = %f,xt = %f", tspeek, rspeek, lng, xtime);
	printf("--------------------------------------------------------\n");

}

/*
*���ܣ�ģ��������ܹ���
*���룺�����ܳ�
*������ڹ�����ʱ��
*/
double trun(double lng)
{
	double t;
	t = lng / tspeek;
	printf("�ڹ�����ʱ��Ϊ��%.2lf\n", t);
	return (t);
}

/*
*���ܣ�ģ��������ܹ���
*���룺�����ܳ�
*�������������ʱ��
*/
double rrun(double lng)
{
	double t;
	t = lng / rspeek;
	printf("��������%.2lf\n", t);
	printf("����˯��%.2lf\n", xtime);
	printf("����������ʱ��Ϊ��%.2lf\n", t + xtime);
	return (t + xtime);
}

/*
*���ܣ�ģ��������ܹ���
*���룺��
*�������
*/
void start()
{
	double Tt;
	double Tr;
	printf("�������ڿ�ʼ����\n");
	printf("���棬���Ҹ����ʵ��ת������\n");
	printf("\n");
	printf("�������ǿ��������ڹ�ѡ�֣�С�ڹ���Ȼ��������������Ȼ�ƶ����ᣬΪ�����е�Ŀ��Ŀ���¸�ǰ������\n");
	printf("������ΪС�ڹ���ͣ�\n");
	printf("����������С���ӣ�������֪�����ӵı����ٶȱ��ڹ����ˡ���\n");
	printf("������������С���Ӿ�Ȼ�ҵ�һ����������Ȼ��ʼ˯���ˣ�����\n");
	printf("С���Ӿ�Ȼ��ô���ţ������Σ���������Ŀ�Դ��ɣ�\n");
	printf("\n");
	printf("���������Ǽ������ĵ�ʱ�̣�\n");
	printf("������һ�𿴿�\n");
	printf("------------------------------------------------------------\n");
	
	Tt = trun(lng);
	printf("\n");
	Tr = rrun(lng);
	printf("\n");

	if (Tt < Tr)
		printf("��~ ���򲻸������ˣ��ڹ꾭����иŬ��������սʤ�����ӣ�����\n");
	else if (Tt > Tr)
		printf("��Ȼ�������Ӹ��죡\n");
	else
		printf("�漣�����ˣ����ڹ������ͬʱ�����\n");
	
}
int main(void)
{
	init();
	start();

	return 0;

}