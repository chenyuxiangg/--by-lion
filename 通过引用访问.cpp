#include"iostream"
using namespace std;

class Book
{
public:
	char title[10], author[20];

	void input();
	void output();
};

void Book::input()
{
	cin >> title >> author;
}

void Book::output()
{
	cout << title << " " << author << endl;
}

int main(int argc, char* argv[])
{
	Book b[2];
	cout << "请输入书名及作者： " << endl;
	for (int i = 0; i < 2; i++)
		b[i].input();
	Book & pb = b[0];
	cout << "输出： " << endl;
	pb.output();
	b[0].output();
	b[1].output();

	return 0;
}