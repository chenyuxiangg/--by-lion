#include<stdio.h>
#include<stdlib.h>

/*定义一个结构体类型*/
typedef struct student 
{
	long no;
	char name[20];
	char addr[30];
	struct student *next;//指向下一个节点
}STU;
STU *h, *prev, *cur;//h指向第一个节点的地址，prev指向cur之前的一个节点，cur指向当前地址
long no;
/*创建链表*/
STU * creatlist()
{
	int i, n;//i控制循环，n为输入的学生数
	h = NULL;
	prev = NULL;

	printf("请输入学生数： ");
	scanf_s("%d", &n);
	printf("学号      姓名       住址\n");
	for(i = 0; i < n; i++)
	{
		cur = (STU *)malloc(sizeof(STU));//动态分配节点内存
		cur->next = NULL;//先让cur->next指向空
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
/*输出链表*/
void displist()
{
	STU * p;
	p = h;
	printf("学号            姓名            住址\n");
	while(p != NULL)
	{
		printf("%-10d%10s%16s", p->no, p->name, p->addr);
		printf("\n");
		p = p->next;
	}
}
/*插入节点*/
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
/*删除节点*/
STU * deletenode(STU * h,long no)
{
	STU * pre, *p;
	pre = NULL;
	if(h == NULL)
{
	printf("链表为空，删除失败！");
	return;
}
	p = h;
	printf("请输入您要删除的学生的学号：");
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
		printf("没有发现要删除的节点，删除失败！");
	return h;
}
int main(int argc,char * argv[])
{
	STU *s;
	s = NULL;
	creatlist();
	displist();
	printf("请输入你要插入的学生信息：\n");
	printf("学号      姓名       住址\n");
	scanf_s("%d %s %s", &s->no, s->name,20, s->addr,30);
	insertnode(h, s);
	displist();
	deletenode(h, no);

	return 0;
}


