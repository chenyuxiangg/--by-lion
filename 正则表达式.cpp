#include <iostream>
#include <regex>
using namespace std;
/*
С�᣺
1������c++��ƥ��������ʽ�е������ַ������硰+������.��������֮���
��Ҫʹ��������б������ʾת�壬ԭ����c++�еķ�б��Ҳ��ʾת�壬ʹ��������б�ܿ��Խ���Ϊ��
��һ�η�б����c++��������ʽ��б�ܵ�ת�壨Ҳ���Է����������ڶ��β���������ʽ���������
��ת�塣���Գ���һ����������󣺵�Ҫƥ��һ����б��ʱ��ȴ��Ҫ��patten��д�ĸ���б�ܡ� 
2��regex_match()��regex_rearch()������ :
regex_match()�Ƕ�����targetƥ���˲����true,��regex_search()��ֻҪtarget�к���patten��
����true. 
*/

int main(int argc,char** atgv)
{
	string str = "ikak\\kk";
	regex patten("\\\\");
	
	if(regex_search(str,patten))
	{
		cout << " is match" << endl;
	}
	else
	{
		cout << "not match." << endl;
	}
	return 0;
 } 
