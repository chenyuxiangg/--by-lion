#include"iostream"
using namespace std;
class squre
{private:
	double length;
public:
	squre(double x);
	void area()
	{
		cout << "正方形的面积为： " << length * length << endl;
	}
	inline void perimeter();
};

//构造函数定义
squre::squre(double x)
{
	length = x;
}

//内联函数定义
void squre::perimeter()  //返回值类型应该在类别之前
{
	cout << "正方形的周长为： " << 4 * length << endl;
}

int main(int argc,char * argv[])
{
	squre ss(2.1); //若此处为整数，则输出时只有整数，没有小数；若此处是小数点后有数，则输出时才有小数
	ss.area();
	ss.perimeter();

	return 0;
}
