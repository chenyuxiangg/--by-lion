#include <iostream>
#include <string>

using namespace std;
#include "texteditor.h"

int main(int argc,char * argv[])
{
	string infile;
	string outfile;

	cout << "��������Ҫ�򿪵��ļ�����";
	getline(cin, infile);
	outfile = infile + ".out";
	cout << "����ļ���Ϊ��" << outfile << endl;

	texteditor editor(infile, outfile);
	editor.run();
}