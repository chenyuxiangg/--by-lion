#include "iostream"
#include "cmath"
using namespace std;
class point 
{public:
	point(float a, float b);//构造函数
	point(point &a);//拷贝构造函数
	~point();
	float getx();
	float gety();
private:
	float x;
	float y;
};

point ::point(float a,float b):x(a),y(b)
{
	cout << "point构造函数被调用" << endl;
}

point :: point(point &a)
{
	x = a.x;
	y = a.y;
	cout << "point的拷贝构造函数被调用" << endl;
}

point :: ~point()
{
	cout << "point 的析构函数被调用" << endl;
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
	distate(point pa, point pb);//distate构造函数
	distate(distate &d);
	~distate();
	double getd();
};

distate :: distate(point pa,point pb):pa(pa),pb(pb)
{
	double x = double(pa.getx() - pb.getx());
	double y = double(pa.gety() - pb.gety());
	dis = sqrt(x*x + y*y);
	cout << "distate构造函数被调用" << endl;
}

distate :: distate(distate& d):pa(d.pa),pb(d.pb)
{
	cout << "dis拷贝构造函数被调用" << endl;
	dis = d.dis;
}

distate :: ~distate()
{
	cout << "distate析构函数被调用" << endl;
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
	cout << "通过d1得到两点的距离" << d1.getd() << endl;
	cout << "通过d2得到两点的距离" << d2.getd() << endl;
	return 0;
}

//总结：①组合类中，可以在新类中定义已知类的对象，但是在定义新类构造函数，拷贝构造函数时，需用 55  63行的定义形式；
//     ②c++中强制类型转换如 57  58 行