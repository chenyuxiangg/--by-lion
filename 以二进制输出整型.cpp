//��������ת��Ϊ�����Ʊ�ʾ�ķ���֮һ
#include "iostream"
using namespace std;

void printbinary(int valure)
{
	unsigned int mask = 0x80000000;//��ʾ32λ�� 10000000000000000000000000000000
	int n = sizeof(unsigned int) * 8;
	for(int i = 0;i < n;i++)
	{
		if (valure & mask)
			cout << "1";
		else
			cout << "0";
		mask = (mask >> 1);
	}
}

int main(int argc,char * argv[])
{
	int valure;
	cout << "��������Ҫת����������" << endl;
	cin >> valure;
	cout << endl;
	cout << valure << " " << "ת���ɶ�����Ϊ��" << endl;
	printbinary(valure);

	return 0;
}


//�ܽ᣺��ʹ��������������λ����ʱ��������ڲ���ͨ��������ʽʵ�ֵ�
