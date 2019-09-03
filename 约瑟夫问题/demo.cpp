#include <iostream>
#include "List.h"
using namespace std;



int main(int argc,char* argv[])
{
	//cout << "ok" << endl;
	int n;
	int myst;
	List L;
	cout << "请输入您所期待的n：";
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		int num = i + 1;
		cout << "请输入第" << num << "人的密码：";
		cin >> myst;
		Note* p = new Note(myst);
		p->setnum(num);
		L.InsertNote(p);
		cout << "已将第" << num << "人加入链表" << endl;
		//cout << p->getnum() << endl;//测试
		cout << endl;
	}

	int m = 20;
	while (!L.Isempty())
	{
		Note* currentnote = L.geth();
		for (int j = 0; j < m - 1; j++)
		{
			currentnote = currentnote->getnext();
		}
		cout << currentnote->getnum() << " ";
		m = currentnote->getdate();
		L.seth(currentnote->getnext());
		L.OutNote(currentnote);

	}

	system("pause");
	return 0;
}