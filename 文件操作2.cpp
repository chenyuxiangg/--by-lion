#include <iostream>
#include <fstream>
#include <string>
#include <memory.h>
using namespace std;

int main(int argc,char* argv[])
{
	string line;
	size_t line_count = 0;
	size_t word_count = 0;
	size_t letter_count[27];
	memset(letter_count,0,sizeof(letter_count));
	ifstream infile("./article.txt",ios::in);
	if(!infile.is_open())
	{
		cout << "文件打开失败！" << endl;
		return 0;
	}
	else{
		while(!infile.eof())
		{
			line_count++;
			getline(infile,line);
			size_t len = line.length();
			for(int i = 0;i < len;++i)
			{
				if(line[i] >= 'A' && line[i] <= 'Z')
				{
					line[i] += 32;
				}
				if(line[i] == ' ' || line[i] == ',' || line[i] == '.')
				{
					word_count++;
				}
				letter_count[line[i] - 'a']++;
			}
			if(line[len-1] != ',' || line[len-1] != '.')
			{
				word_count++;
			}
		}
	}
	infile.close();
	cout << "这篇文章共有" << line_count << "行；" << "共有" << word_count << "个单词。" << endl;
	for(int i = 0;i < 26;++i)
	{
		cout << char('a'+i) << "出现了" << letter_count[i] << "次；" << endl; 
	}
	return 0;
 } 
