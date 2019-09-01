#include <iostream>
#include <cmath>
using namespace std;

enum month{
	Jan = 31,Feb = 28,Mar = 31,Apr = 30,May = 31,
	Jun = 30,Jul = 31,Aug = 31,Sep = 30,Oct = 31,
	Nov = 30,Dec = 31
};

int culculate(int year,int month,int day);
int main(int argc,char* argv[])
{
	int year1,month1,day1;
	int year2,month2,day2;
	int result = 0;
	
	cin >> year1;cin.get();
	cin >> month1;cin.get();
	cin >> day1;
	cin >> year2;cin.get();
	cin >> month2;cin.get();
	cin >> day2;
	
	if(year1 == year2)
	{
		result = fabs(culculate(year1,month1,day1)-culculate(year2,month2,day2));
	}
	else if(year1 < year2)
	{
		while(year1 != year2)
		{
			if(year1%400 == 0)
			{
				result += 366;
			}
			else
			{
				result += 365;
			}
			year1++;
		}
		result += culculate(year2,month2,day2);
	}
	else
	{
		while(year1 != year2)
		{
			if(year2%400 == 0)
			{
				result += 366;
			}
			else
			{
				result += 365;
			}
			year2++;
		}
		result += culculate(year1,month1,day1);
	}
	
	cout << result << endl;
	
	return 0;
 } 
 
 int culculate(int year,int month,int day)
 {
 	int days = 0;
 	int two = Feb;
 	if(year%400 == 0)
		{
			two += 1;
		}
	
		switch(month)
		{
			case 1:
				if(day <= 0 || day > 31)
				{
					cout << "日期输入有误！" << endl;
					return 0;
				}
				days += day;
				break;
			case 2:
				if(day <= 0 || day > 29)
				{
					cout << "日期输入有误！" << endl;
					return 0;
				}
				days = Jan+day;
				break;
			case 3:
				if(day <= 0 || day > 31)
				{
					cout << "日期输入有误！" << endl;
					return 0;
				}
				days = Jan+two+day;
				break;
			case 4:
				if(day <= 0 || day > 30)
				{
					cout << "日期输入有误！" << endl;
					return 0;
				}
				days = Jan+two+Mar+day;
				break;
			case 5:
				if(day <= 0 || day > 31)
				{
					cout << "日期输入有误！" << endl;
					return 0;
				}
				days = Jan+two+Mar+Apr+day;
				break;
			case 6:
				if(day <= 0 || day > 30)
				{
					cout << "日期输入有误！" << endl;
					return 0;
				}
				days = Jan+two+Mar+Apr+May+day;
				break;
			case 7:
				if(day <= 0 || day > 31)
				{
					cout << "日期输入有误！" << endl;
					return 0;
				}
				days = Jan+two+Mar+Apr+May+Jun+day;
				break;
			case 8:
				if(day <= 0 || day > 31)
				{
					cout << "日期输入有误！" << endl;
					return 0;
				}
				days = Jan+two+Mar+Apr+May+Jun+Jul+day; 
				break;
			case 9:
				if(day <= 0 || day > 30)
				{
					cout << "日期输入有误！" << endl;
					return 0;
				}
				days = Jan+two+Mar+Apr+May+Jun+Jul+Aug+day;
				break;
			case 10:
				if(day <= 0 || day > 31)
				{
					cout << "日期输入有误！" << endl;
					return 0;
				}
				days = Jan+two+Mar+Apr+May+Jun+Jul+Aug+Sep+day;
				break;
			case 11:
				if(day <= 0 || day > 30)
				{
					cout << "日期输入有误！" << endl;
					return 0;
				}
				days = Jan+two+Mar+Apr+May+Jun+Jul+Aug+Sep+Oct+day;
				break;
			case 12:
				if(day <= 0 || day > 31)
				{
					cout << "日期输入有误！" << endl;
					return 0;
				}
				days = Jan+two+Mar+Apr+May+Jun+Jul+Aug+Sep+Oct+Nov+day;
				break;
			default:
				cout << "日期输入有误！" << endl;
				break;
		}
		return days;
	}
