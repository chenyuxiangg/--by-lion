#include"iostream"
using namespace std;
class Book
{public:
	char title[20], author[10], publish[30];
	float price;

	void input();
	void output();
};

void Book ::input()
{
	cin >> title >> author >> publish;//连续键入，中间空格。
	cin >> price;
}

void Book :: output()
{
	cout << title << "  " << author << "  " << publish << "  ";
	cout << price << endl;
}

int main(int argc,char* argv[])
{
	int i, j;
	Book b[10], temp;
	cout << "请输入书的名字、作者、出版社和价格： " << endl;
	for (i = 0; i <= 9; i++)
		b[i].input();
	for(i = 0;i < 9;i++)
		for(j = i + 1;j < 10;j++)
		{
			if(b[i].price > b[j].price)
		{
			temp = b[i];
			b[i] = b[j];
			b[j] = temp;
		}
		}

	cout << "输出结果： " << endl;
	for (i = 0; i <= 9; i++)
		b[i].output();

	return 0;
}