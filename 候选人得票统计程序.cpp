#include<stdio.h>
#include<string.h>
#define M 2

struct person
{
	char name[16];
	int coun = 0;
};
void input(struct person ld[],int n)
{
	int i;
	printf("������%d����ѡ�˵Ļ�����Ϣ��\n",M);
	for (i = 0; i < n; i++)
	{
		printf("������");
		scanf_s("%s", ld[i].name,16);
	}
}

int vote(struct person ld[],int n)
{
	char ename[16];
	int i, j, m, t;
	printf("�˴βμ�ͶƱ������Ϊ��");
	scanf_s("%d", &m);
	printf("\n");
	for (i = 0; i < m; i++)
	{
		printf("����ҪͶ��");
		scanf_s("%s", ename,16);
		for (j = 0; j < n; j++)
		{
			if (strcmp(ld[j].name, ename))
				ld[j].coun++;
		}
	}
	printf("\n");
	return ld[j].coun;
}

void output(struct person ld[],int n)//���Զ��庯���ж���ṹ���ṹ������ʱ����Ҫд��־ struct,�������� ��person
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("��%dλ��ѡ�˵���Ϣ��\n",i + 1);
		printf("������%s\t",ld[i].name);//��ʹ�ýṹ�������ȡ�ṹ�������Աʱ�����
		printf("Ʊ����%d\n",ld[i].coun);
	}
}

int main(int argc, char * argv[])
{
	struct person leader[M];
	input(leader, M);
	vote(leader, M);
	output(leader, M);

	return 0;
}