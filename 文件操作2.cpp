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
		cout << "�ļ���ʧ�ܣ�" << endl;
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
	cout << "��ƪ���¹���" << line_count << "�У�" << "����" << word_count << "�����ʡ�" << endl;
	for(int i = 0;i < 26;++i)
	{
		cout << char('a'+i) << "������" << letter_count[i] << "�Σ�" << endl; 
	}
	return 0;
 } 
