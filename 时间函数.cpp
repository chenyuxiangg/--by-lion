#include <iostream>
#include  <ctime>

using namespace std;

int main(int argc,char* argv[])
{
	errno_t err;
	time_t i_now = time(0);
	cout << "从1970年一月一日午夜至今经过 " << i_now << " s" << endl;

	char dt[26];
	err = ctime_s(dt,26,&i_now);
	cout << "本地日期和时间：" << dt << endl;

	tm i_time;
	err = gmtime_s(&i_time,&i_now);
	err = asctime_s(dt,26,&i_time);
	cout << "UTC时间：" << dt << endl;

	system("pause");
	return 0;
}