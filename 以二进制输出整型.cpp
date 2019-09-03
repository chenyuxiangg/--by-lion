//将整型量转化为二进制表示的方法之一
#include "iostream"
using namespace std;

void printbinary(int valure)
{
	unsigned int mask = 0x80000000;//表示32位的 10000000000000000000000000000000
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
	cout << "请输入您要转换的整数：" << endl;
	cin >> valure;
	cout << endl;
	cout << valure << " " << "转换成二进制为：" << endl;
	printbinary(valure);

	return 0;
}


//总结：当使用两个整型量做位运算时，计算机内部是通过补码形式实现的
