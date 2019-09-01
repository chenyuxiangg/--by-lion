#include <fstream>
#include <iostream>
#include <memory.h>
#include "Lexical_analyzer.h"
using namespace std;

int main(int argc,char* argv[])
{
	if(argc < 2)
	{
		cout << "�����������." << endl;
		return 0;
	}
	ifstream infile;
	infile.open(argv[1]);
	if(!infile.is_open())
	{
		cout << argv[1] << " �ļ���ʧ��." << endl;
		return 0;
	}
	
	char str[100];
	Clexical_Analyzer analy;
	while(!infile.eof())
	{
		cout << endl;
		memset(str,0,sizeof(str));
		infile.getline(str,100);
		analy.Analyze(str);
		analy.Show();
		analy.Clear();
	}
	cout << endl;
	cout << "��������" << endl;
	infile.close();
	return 0;
}
