#include<stdio.h>
/*�����ڽṹ��Ķ���   �ṹ�嶨�壺struct student{  };   */
enum Weakend //������һ����������enum Weakend,��û�ж������
{
	Monday, Tuthday, Wednsday, Thursday, Friday, Saturday, Sunday
};//��Monday ��ʼ��Sunday,�����Զ���ֵΪ0-6

int main(void)
{
	enum Weakend i;

	i = Monday;

	printf("%d\n", i);

	return 0;


}