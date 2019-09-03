#include <iostream>
#include <string>

using namespace std;
#include "texteditor.h"

int main(int argc,char * argv[])
{
	string infile;
	string outfile;

	cout << "请输入您要打开的文件名：";
	getline(cin, infile);
	outfile = infile + ".out";
	cout << "输出文件名为：" << outfile << endl;

	texteditor editor(infile, outfile);
	editor.run();
}