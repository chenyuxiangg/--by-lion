#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <stdlib.h> 
using namespace std;

int main(int argc,char* argv[])
{
	string str;
	char* res;
	int count = 0;
	
	getline(cin,str);
	int len = str.length();
	res = new char[len+1];
	for(int i = 0;i < len;++i)
	{
		if(isdigit(str[i]) || str[i] == '.')
		{
			res[count++] = str[i];
		}
	 } 
	 
	 res[count] = '\0';
	 double x = atof(res);
	 cout << x << endl;
	 cout << sqrt(x);
	 
	 delete[] res;
	 res = NULL;
	 return 0;
 } 
