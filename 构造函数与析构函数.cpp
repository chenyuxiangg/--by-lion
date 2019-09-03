#include"iostream"
using namespace std;

class time
{
	private:
		int hour;
		int minute;
		int second;
public:
	time(int h, int m, int s);
	~time();
};

time :: time(int h,int m,int s):hour(h),minute(m),second(s)
{
	cout << "time created at " << hour << ":" << minute << ":" << second << endl;
}

time :: ~time()
{
	cout << "time destruct at " << hour << ":" << minute << ":" << second << endl;
}

class date
{private:
	int year;
	int mon;
	int day;
public:
	date(int y, int m, int d);
	~date();
}yestaday(2016,4,23);

date :: date(int y,int m,int d):year(y),mon(m),day(d)
{
	time t(11, 11, 11); // 在类date构造函数中定义类time的对象
	static time t1(12, 12, 12);//在类date构造函数中定义time的静态对象
	cout << "date created " << year << "," << mon << "," << day << endl;
}

date :: ~date()
{
	cout << "date destruct " << year << "," << mon << "," << day << endl;
}

int  main(int argc,char * argv[])
{
	date today(2016, 4, 24);
	return 0;
}