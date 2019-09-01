#include <iostream>
#include <stdio.h>
using namespace std;

union {
	short s;
	char c[sizeof(short)];
}un;

int main(int argc,char* argv[]){
	un.s = 0x0102;
	for(int i = 0;i < sizeof(short); ++i)
		printf("%c ",un.c[i]);
	printf("\n");
	/*if(sizeof(un.s) == 2){
		if(un.c[0] == 1 && un.c[1] == 2)
			cout << "big-endian" << endl;
		else if(un.c[0] == 2 && un.c[1] == 1)
			cout << "small-endian" << endl;
		else
			cout << "unkown" << endl;
	}
	else
		cout << "un.s:" << un.s << endl;*/
	return 0;
}
