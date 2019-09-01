#include <iostream>
using namespace std;

enum month{
	Jan = 31,Feb = 28,Mar = 31,Apr = 30,May = 31,
	Jun = 30,Jul = 31,Aug = 31,Sep = 30,Oct = 31,
	Nov = 30,Dec = 31
};
int main(int argc,char* argv[])
{
	int days = 0;
	int two = Feb;
	int year,month,day;
	while(1)
	{
		cin >> year;
		cin.get();
		cin >> month;
		cin.get();
		cin >> day;
		if(year%400 == 0)
		{
			two += 1;
		}
	
		switch(month)
		{
			case 1:
				days += day;
				cout << days << endl;
				return 0;
			case 2:
				days = Jan+day;
				cout << days << endl;
				return 0;
			case 3:
				days = Jan+two+day;
				cout << days << endl;
				return 0;
			case 4:
				days = Jan+two+Mar+day;
				cout << days << endl;
				return 0;
			case 5:
				days = Jan+two+Mar+Apr+day;
				cout << days << endl;
				return 0;
			case 6:
				days = Jan+two+Mar+Apr+May+day;
				cout << days << endl;
				return 0;
			case 7:
				days = Jan+two+Mar+Apr+May+Jun+day;
				cout << days << endl;
				return 0;
			case 8:
				days = Jan+two+Mar+Apr+May+Jun+Jul+day; 
				cout << days << endl;
				return 0;
			case 9:
				days = Jan+two+Mar+Apr+May+Jun+Jul+Aug+day;
				cout << days << endl;
				return 0;
			case 10:
				days = Jan+two+Mar+Apr+May+Jun+Jul+Aug+Sep+day;
				cout << days << endl;
				return 0;
			case 11:
				days = Jan+two+Mar+Apr+May+Jun+Jul+Aug+Sep+Oct+day;
				cout << days << endl;
				return 0;
			case 12:
				days = Jan+two+Mar+Apr+May+Jun+Jul+Aug+Sep+Oct+Nov+day;
				cout << days << endl;
				return 0;
			default:
				continue;
				break;
		}
	}
	return 0;
 } 
