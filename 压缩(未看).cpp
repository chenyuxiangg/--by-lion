#include"iostream"
#include"cstdio"
#include"string.h"

using namespace std;
int main(int argc,int argv[])
{
	char words[2014];
	gets_s(words);//

	words[strlen(words) + 1] = 0;
	words[strlen(words)] = ' ';
	char * pb = words;
	for (char *p = words; *p != 0; ++p)
	{
		if(*p == ' ')
	{
		for (char *p1 = pb; p1 < p - 1; ++p1)
		{
			if (*p1 != 0x01)
				for (char *p2 = p1 + 1; p2 < p; ++p2)
				{
					if (*p1 == *p2)
						*p2 = 0x01;
				}
		}
		while (pb <= p)
		{
			if (*pb != 0x01)
				cout << *pb;
			++pb;
		}
	}
	}
	return 0;

}