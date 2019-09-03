#include "iostream"
#include "cmath"
using namespace std;
class point 
{public:
	point(float a, float b);//���캯��
	point(point &a);//�������캯��
	~point();
	float getx();
	float gety();
private:
	float x;
	float y;
};

point ::point(float a,float b):x(a),y(b)
{
	cout << "point���캯��������" << endl;
}

point :: point(point &a)
{
	x = a.x;
	y = a.y;
	cout << "point�Ŀ������캯��������" << endl;
}

point :: ~point()
{
	cout << "point ����������������" << endl;
}

float point :: getx()
{
	return x;
}

float point :: gety()
{
	return y;
}

class distate
{private:
	point pa;
	point pb;
	double dis;
public:
	distate(point pa, point pb);//distate���캯��
	distate(distate &d);
	~distate();
	double getd();
};

distate :: distate(point pa,point pb):pa(pa),pb(pb)
{
	double x = double(pa.getx() - pb.getx());
	double y = double(pa.gety() - pb.gety());
	dis = sqrt(x*x + y*y);
	cout << "distate���캯��������" << endl;
}

distate :: distate(distate& d):pa(d.pa),pb(d.pb)
{
	cout << "dis�������캯��������" << endl;
	dis = d.dis;
}

distate :: ~distate()
{
	cout << "distate��������������" << endl;
}

double distate :: getd()
{
	return dis;
}

int main(int argc,char* argv[])
{
	point p1(2, 2), p2(5, 5);
	distate d1(p1, p2);
	distate d2(d1);
	cout << "ͨ��d1�õ�����ľ���" << d1.getd() << endl;
	cout << "ͨ��d2�õ�����ľ���" << d2.getd() << endl;
	return 0;
}

//�ܽ᣺��������У������������ж�����֪��Ķ��󣬵����ڶ������๹�캯�����������캯��ʱ������ 55  63�еĶ�����ʽ��
//     ��c++��ǿ������ת���� 57  58 ��