#include<stdio.h>
#include<stdlib.h>

/*����һ���ṹ������*/
typedef struct student 
{
	long no;
	char name[20];
	char addr[30];
	struct student *next;//ָ����һ���ڵ�
}STU;
STU *h, *prev, *cur;//hָ���һ���ڵ�ĵ�ַ��prevָ��cur֮ǰ��һ���ڵ㣬curָ��ǰ��ַ
long no;
/*��������*/
STU * creatlist()
{
	int i, n;//i����ѭ����nΪ�����ѧ����
	h = NULL;
	prev = NULL;

	printf("������ѧ������ ");
	scanf_s("%d", &n);
	printf("ѧ��      ����       סַ\n");
	for(i = 0; i < n; i++)
	{
		cur = (STU *)malloc(sizeof(STU));//��̬����ڵ��ڴ�
		cur->next = NULL;//����cur->nextָ���
		if (h == NULL)
		{
			h = cur;
		}
		else
			prev->next = cur;
		scanf_s("%d %s %s", &cur->no, cur->name,20, cur->addr,30);
		prev = cur;
	}
	return h;
}
/*�������*/
void displist()
{
	STU * p;
	p = h;
	printf("ѧ��            ����            סַ\n");
	while(p != NULL)
	{
		printf("%-10d%10s%16s", p->no, p->name, p->addr);
		printf("\n");
		p = p->next;
	}
}
/*����ڵ�*/
STU * insertnode(STU *h,STU *s)
{
	STU * pre, *p;
	pre = NULL;
	p = h;
	if(h == NULL)
	{
		h = s;
		s->next = NULL;
	}
	else
	{
		while((s->no > p->no)&&(p->next != NULL))
		{
			pre = p;
			p = p->next;
		}
		if(s->no <= p->no)
		{
			if (h == p)
			{
				h = s;
				s->next = p;
			}
			else
			{
				pre->next = s;
				s->next = p;
			}
		}
		else
		{
			p->next = s;
			s->next = NULL;
		}
	}
	return h;
}
/*ɾ���ڵ�*/
STU * deletenode(STU * h,long no)
{
	STU * pre, *p;
	pre = NULL;
	if(h == NULL)
{
	printf("����Ϊ�գ�ɾ��ʧ�ܣ�");
	return;
}
	p = h;
	printf("��������Ҫɾ����ѧ����ѧ�ţ�");
	scanf_s("%d", &no);
	while((p->no < no) && (p->next != NULL))
	{
		pre = p;
		p = p->next;
	}
	if (p->no == no)
	{
		if (p == h)
			h = p->next;
		else
			pre->next = p->next;
		free(p);
	}
	else
		printf("û�з���Ҫɾ���Ľڵ㣬ɾ��ʧ�ܣ�");
	return h;
}
int main(int argc,char * argv[])
{
	STU *s;
	s = NULL;
	creatlist();
	displist();
	printf("��������Ҫ�����ѧ����Ϣ��\n");
	printf("ѧ��      ����       סַ\n");
	scanf_s("%d %s %s", &s->no, s->name,20, s->addr,30);
	insertnode(h, s);
	displist();
	deletenode(h, no);

	return 0;
}


