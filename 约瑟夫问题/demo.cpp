#include <iostream>
#include "List.h"
using namespace std;



int main(int argc,char* argv[])
{
	//cout << "ok" << endl;
	int n;
	int myst;
	List L;
	cout << "�����������ڴ���n��";
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		int num = i + 1;
		cout << "�������" << num << "�˵����룺";
		cin >> myst;
		Note* p = new Note(myst);
		p->setnum(num);
		L.InsertNote(p);
		cout << "�ѽ���" << num << "�˼�������" << endl;
		//cout << p->getnum() << endl;//����
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