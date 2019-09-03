#pragma once
/*这个头文件定义了用于编辑文本文件的texteditor数据类型。
基本操作包括：
构造函数： 为给定的文件创建一个texteditor对象
run() :运行编辑器
showmenu(): 显示一个热键菜单
insert（）：在一行文本插入一个字符串
erase（）： 从一行文本删除一个字符串
replace（）： 将一行文本的某个字符串替换为另一个字符串
next（）： 输出编辑完的行并提取下一行要编辑的行
quit（） ：结束编辑*/

#include <iostream>
#include <string>
#include <fstream> //ifstream  ofstream

class texteditor
{
public:
	texteditor(string infile, string outfile);
	/*
	功能：为名为infile和outfile的文件创建一个文本编辑器
	前置条件：infile是将被编辑的文件
	后置条件：outfile 包含编辑完的文件
	*/

	void run();

	void showmenu();

	void insert(string str1,string str2);

	void erase(string str);

	void replace(string str1,string str2);

	void next();

	void quit();

private:
	ifstream myinfile;
	ofstream myoutfile;
	string mystring;
};
