# include <stdio.h>
struct student
{
	int age;
	float score;
	char sex;
};

int main(void)
{
	//��һ�ַ�ʽ
	struct student st = { 80,66.6, 'F' };//��ʼ�� �����ͬʱ����ֵ
	//�ڶ��ַ�ʽ
	struct student st2;
	//ȡ���ṹ���еĳ�Ա ��ʽһ
	st2.age = 10;
	st2.score = 88;
	st2.sex = 'F';
	/*��ʽ��
	int * pst;
	pst = &st;
	pst -> age;//�൱�ڣ�*pst��.age Ҳ�൱��st.age
	*/
	printf("%d %f %c\n", st.age, st.score, st.sex);
	printf("%d %f %c\n", st2.age, st2.score, st2.sex);
	return 0;
}