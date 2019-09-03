#include <iostream>
#include <cstring>
using namespace std;

int main(int argc,char* argv[])
{
	string str;
	getline(cin,str,'.');
	cin.get();
	while(str != "")
	{
		int len = str.length();
		int sum = 0;
		int res = 0;
		for(int i = 0; i < len;++i)
		{
			sum += str[i];
		}
		res = sum%64 + ' ';
		cout << char(res) << endl;
		getline(cin,str,'.');
		cin.get();
	}
	
	return 0;
}
