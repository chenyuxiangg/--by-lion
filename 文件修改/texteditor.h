#pragma once
/*���ͷ�ļ����������ڱ༭�ı��ļ���texteditor�������͡�
��������������
���캯���� Ϊ�������ļ�����һ��texteditor����
run() :���б༭��
showmenu(): ��ʾһ���ȼ��˵�
insert��������һ���ı�����һ���ַ���
erase������ ��һ���ı�ɾ��һ���ַ���
replace������ ��һ���ı���ĳ���ַ����滻Ϊ��һ���ַ���
next������ ����༭����в���ȡ��һ��Ҫ�༭����
quit���� �������༭*/

#include <iostream>
#include <string>
#include <fstream> //ifstream  ofstream

class texteditor
{
public:
	texteditor(string infile, string outfile);
	/*
	���ܣ�Ϊ��Ϊinfile��outfile���ļ�����һ���ı��༭��
	ǰ��������infile�ǽ����༭���ļ�
	����������outfile �����༭����ļ�
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
