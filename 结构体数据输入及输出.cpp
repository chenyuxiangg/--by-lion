/*ͨ�������Խṹ������������*/

#include <stdio.h>
#include <string.h>
struct student
{
	int age;
	char name[100];
	char sex;
};
void Inputstudent(struct student * pstu);//����ʹ��ǰ����������

void Outputstudent(struct student * pst);

int main(void)
{
	/*
	struct student
	{
	int age;
	float score;
	char sex;
	};//�ֺŲ���ʡ
	struct student st = { 10,66.6,'F' };

	struct student * pst;
	pst = &st;

	printf("%d %f %c", pst->age, pst->score, pst->sex);
	return 0;
	*/
	struct student st;

	Inputstudent(&st);//�Խṹ��������룬���뷢��st�ĵ�ַ
	Outputstudent(&st);//�Խṹ�������������Է���st��ַҲ�ɷ�������

	return 0;
}
void Inputstudent(struct student * pstu)//�������������Ҫ����ֵ
{
	pstu->age = 10;//pstuֻռ4���ֽ�
	strcpy_s(pstu->name, "����");
	pstu->sex = 'F';
}

/*
void Outputstudent(struct student ss)//����д��Ҳ��ȷ����һ����ָ�룬�����ַ����൱�ڰ�st������
                                       ���Ƶ�ss��,����ָ��Ҳ��Σ�գ����ݿ��Ը�д��������ͨ����const
									   ���
{
	printf("%d %c %s\n", ss.age, ss.sex, ss.name);
}
*/
void Outputstudent(struct student * pst)//���͵�ַ�ĺô�  ���Կ��ٴ������ݣ���ռ���ڴ�С
{
	printf("%d %c %s\n", pst->age, pst->sex, pst->name);
}