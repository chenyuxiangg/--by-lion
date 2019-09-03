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
	double x, y;//x为矩形长，y为矩形宽
	string str;

	cout << "您要计算哪个图形的面积与周长？ " << endl;
	cin >> str;
	if (str == "圆")
	{
		cout << "请输入R = ";
		cin >> R;
		area(R);
		perime(R);
	}
	else if (str == "长方形" || str == "正方形")
	{
		cout << "请输入 x = ";
		cin >> x;
		cout << "请输入 y = ";
		cin >> y;
		area(x, y);
		perime(x, y);
	}
	else
		cout << "您的输入有误！" << endl;

	return 0;
}

void area(double R)
{
	const double Pi = 3.14;
	double s = Pi * R * R;
	cout << "圆的面积为： " << s << endl;
}

void perime(double R)
{
	const double Pi = 3.14;
	double c = Pi * R * 2;
	cout << "圆的周长为： " << c << endl;
}

void area(double x,double y)
{
	double s = x * y;
	cout << "矩形的面积为： " << s << endl;
}

void perime(double x,double y)
{
	double c = 2 * (x + y);
	cout << "矩形周长为： " << c << endl;
}