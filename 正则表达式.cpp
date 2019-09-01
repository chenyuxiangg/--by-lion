#include <iostream>
#include <regex>
using namespace std;
/*
小结：
1、对于c++中匹配正则表达式中的特殊字符，例如“+”，“.”“？”之类的
需要使用两个反斜杠来表示转义，原因是c++中的反斜杠也表示转义，使用两个反斜杠可以解释为：
第一次反斜杠是c++对正则表达式反斜杠的转义（也可以反过来），第二次才是正则表达式对特殊符号
的转义。所以出现一个奇葩的现象：当要匹配一个反斜杠时，却需要在patten中写四个反斜杠。 
2、regex_match()与regex_rearch()的区别 :
regex_match()是对整个target匹配了才输出true,而regex_search()是只要target中函数patten就
返回true. 
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
