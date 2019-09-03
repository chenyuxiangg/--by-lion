#include "BinarySortTree.h"

int main(int argc,char* argv[])
{
	Bitree* tree = NULL;

	char Ch = 'y';
	while(Ch == 'y')
	{
		cout << "**************************操作菜单***************************" << endl;
		cout << "          1.创建新树                   2.删除一棵树          " << endl;
		cout << "          3.查找数据                   4.删除一数据          " << endl;
		cout << "          5.遍历此树                   6.插入一数据          " << endl;
		cout << "          7.退出                                             " << endl;
		cout << "*************************************************************" << endl;
		cout << "请输入操作序号：";
		char i;
		cin >> i;
		switch(i)
		{
		case '1':
			tree = new Bitree;
			cout << "请为此树建立第一个数据结点：";
			int Da;
			cin >> Da;
			BCreatBiTree(tree,Da);
			break;
		case '2':
			BDelete(tree);
			tree = NULL;
			break;
		case '3':
			cout << "您查找的数据在此位置：" << BSerch(tree) << endl;
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
			cout << "输入操作不允许..." << endl;
			break;
		}

		cout << "您是否想继续操作？" << endl;
		cin >> Ch;
		system("cls");
	}
	BDelete(tree);
	tree = NULL;
	cout << "按任意键退出..." << endl;

	getchar();
	getchar();
	return 0;
}