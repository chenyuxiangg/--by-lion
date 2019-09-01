#include <fstream>
#include <iostream>
#include <memory.h>
#include "CYufa.h"
using namespace std; 

int main(int argc, char** argv) {
	if(argc < 2){
		cout << "参数错误" << endl;
		return 0;
	}
	
	ifstream infile;
	infile.open(argv[1]);
	if(!infile.is_open())
	{
		cout << argv[1] << " 文件打开失败." << endl;
		return 0;
	}
	
	char str[100];
	while(!infile.eof())
	{
		cout << endl;
		memset(str,0,sizeof(str));
		infile.getline(str,100);
		CYufa* y = new CYufa();
		y->Parser(str);
	}
	infile.close();
	return 0;
}
