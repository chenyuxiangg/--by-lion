#include"iostream"
#include"string"
using namespace std;
void area(double R);
void area(double x, double y);
void perime(double R);
void perime(double x, double y);

int main(int argc,int argv[])
{
	double R;
	double x, y;//xΪ���γ���yΪ���ο�
	string str;

	cout << "��Ҫ�����ĸ�ͼ�ε�������ܳ��� " << endl;
	cin >> str;
	if (str == "Բ")
	{
		cout << "������R = ";
		cin >> R;
		area(R);
		perime(R);
	}
	else if (str == "������" || str == "������")
	{
		cout << "������ x = ";
		cin >> x;
		cout << "������ y = ";
		cin >> y;
		area(x, y);
		perime(x, y);
	}
	else
		cout << "������������" << endl;

	return 0;
}

void area(double R)
{
	const double Pi = 3.14;
	double s = Pi * R * R;
	cout << "Բ�����Ϊ�� " << s << endl;
}

void perime(double R)
{
	const double Pi = 3.14;
	double c = Pi * R * 2;
	cout << "Բ���ܳ�Ϊ�� " << c << endl;
}

void area(double x,double y)
{
	double s = x * y;
	cout << "���ε����Ϊ�� " << s << endl;
}

void perime(double x,double y)
{
	double c = 2 * (x + y);
	cout << "�����ܳ�Ϊ�� " << c << endl;
}