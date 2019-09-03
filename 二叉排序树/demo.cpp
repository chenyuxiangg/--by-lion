#include "BinarySortTree.h"

int main(int argc,char* argv[])
{
	Bitree* tree = NULL;

	char Ch = 'y';
	while(Ch == 'y')
	{
		cout << "**************************�����˵�***************************" << endl;
		cout << "          1.��������                   2.ɾ��һ����          " << endl;
		cout << "          3.��������                   4.ɾ��һ����          " << endl;
		cout << "          5.��������                   6.����һ����          " << endl;
		cout << "          7.�˳�                                             " << endl;
		cout << "*************************************************************" << endl;
		cout << "�����������ţ�";
		char i;
		cin >> i;
		switch(i)
		{
		case '1':
			tree = new Bitree;
			cout << "��Ϊ����������һ�����ݽ�㣺";
			int Da;
			cin >> Da;
			BCreatBiTree(tree,Da);
			break;
		case '2':
			BDelete(tree);
			tree = NULL;
			break;
		case '3':
			cout << "�����ҵ������ڴ�λ�ã�" << BSerch(tree) << endl;
			break;
		case '4':
			BDlesinsgle(tree);
			break;
		case '5':
			BInoderTranverce(tree);
			cout << endl;
			break;
		case '6':
			BInput(tree);
			break;
		case '7':
			break;
		default:
			cout << "�������������..." << endl;
			break;
		}

		cout << "���Ƿ������������" << endl;
		cin >> Ch;
		system("cls");
	}
	BDelete(tree);
	tree = NULL;
	cout << "��������˳�..." << endl;

	getchar();
	getchar();
	return 0;
}