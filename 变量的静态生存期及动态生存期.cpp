#include <iostream>
using namespace std;
int i = 0;

void fun ()
{
	static int a = 1; //aΪ��̬������ӵ�о�̬�����ڣ���һ�ε���funʱ����ʼ�����Ժ�ÿ�ε���funʱ��������һ�������
	static int b = 2; //bͬa
	int c = 3;

	a += 1;
	c -= 2;  //cΪfun�������еľֲ�������ӵ�ж�̬�����ڣ�ÿ�ε���funʱ�ܻᱻ��ʼ��Ϊ 3��
	cout << "fun()�н���� " << " a = " << a << endl;
	cout << "             " << " b = " << b << endl;
	cout << "             " << " c = " << c << endl;
	b = a;
}

int main(int argc,char * argv[])
{
	int i = 5;

	cout << "main()�н���� " << " i = " << i << endl;  //���Ϊ5����Ϊ�ڲ���������㣻
	fun();
	fun();
	fun();

	return 0;
}