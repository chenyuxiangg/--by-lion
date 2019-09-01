#include <string.h>
#include <iostream>
using namespace std;

/*
小结：
想法错了，那么所有的努力都是徒劳，本来我想使用string::find()来在原串中
查找模式串中出现的每一个字符，但是我忽略了一点，使用find()若是成功则返回
查找到的位置，没有查找成功则返回string::npos，而且我使用的是遍历模式串，
为模式串中出现的每一个字符调用一次find(),但是这出现一个问题，例如：
patten(&#),str(abd&def#dd&),那么由于方法的固定性，导致中间的#是匹配不到的
，那么是不是当找到模式串中的一个字符后继续匹配下一个模式符而不用从头遍历
模式串就能解决问题？显然不是，这只是拆东墙补了西墙。关键在于我没掌握问题的
本质：对于每一个模式串中的模式符，我应该都能完美识别，因此，我需要遍历的不应该是
模式串，而是源串，对于每一个原串的字符，我需要判断它是否处于模式串中，这样才能完美解决
问题。解决问题的启发来自于：<string.h>中的strtok()函数。 
*/

int main(int argc,char* argv[])
{
	char pat[10] = "@ #;";
	char str[50] = "b@ha jf@kdka#ccc";
	char* tmp = strtok(str,pat);
	while(tmp)
	{
		printf("%s\t",tmp);
		tmp = strtok(NULL,pat);
	 } 
	 
	 return 0;
}
