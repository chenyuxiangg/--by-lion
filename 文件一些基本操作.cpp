#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char* argv[])
{
	ofstream outfile;
	cout << "�������ļ�����";
	char a[10];
	cin >> a;
	getchar();
	outfile.open(a, ios::out);//�ļ������ڣ��Զ�����һ���ļ�
	cout << "�������ݣ�";
	char b[50];
	cin.getline(b, 50);
	outfile << b;
	outfile << '\n';//����һ�к���
	cout << "�ٴ����룺";
	char r[5];
	cin.getline(r, 5);//��������һ�����ݣ��ո�Ҳ������ȡ����ռһ��������λ
	outfile << r;
	outfile.close();
	cout << "���ļ��ж�����" << endl;
	//cin.ignore();
	ifstream infile;
	cout << "�������ļ�����";
	char t[20];
	cin >> t;
	infile.open(t, ios::in);
	string c;

	//�ж��ļ��Ƿ񵽴�ĩβ�����ô���������ļ��е�����������ȡ���㹻���������
	/*while (!infile.eof())
	{
		infile >> c;
		cout << c;
	}*/

	infile >> c;
	cout << c;
	cout << endl;
	istringstream in(c);//���ַ���ת�������ͣ�������Ϊ55ddd55�����ת����55����߶���ض�
	int h;
	in >> h;
	cout << h << endl;
	

	infile.close();
	system("pause");
	return 0;
}