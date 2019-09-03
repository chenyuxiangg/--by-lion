/*
读入一个有空格分隔的（名字，值）对，其中的每个单词是有空白分隔的一个单词，值是一个整数或一个浮点数
。计算并打印出对应于每个名字的所有值之和及平均值，以及所有名字的和与平均值。
*/

/*
map 与 pair的区别与联系：
共同点：他们关联的两个值类型可以相同，也可以不同
不同点：map:用它关联的一对数据必有联系
pair:用它关联的一对数据可以有联系，也可以没有联系。

联系：map 是由 pair 组成的

当用insert()向map里边插值时，可用以下语句检验是否插入成功：

pair<map<int, string>::iterator, bool> Insert_Pair;
Insert_Pair = mapStudent.insert(map<int, string>::value_type (1, "student_one"));
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;

//数据类型：包括值的和与引用次数
struct Stat {
	double m_sum;
	int m_count;
	Stat() :m_sum(0.0), m_count(0) {}//构造函数
};

//定义一张关联Stat 与 string 的表
typedef map<string, Stat> Data;

//计算每个名字对应的值的和
void Sum(Data& data);

//计算并打印所有名字的和与平均值同时打印每个名字对应的值的和与平均值
void My_printf(Data data);

//驱动程序
int main(int argc, char* argv[])
{
	Data data;

	Sum(data);
	My_printf(data);

	system("pause");
	return 0;
}

void Sum(Data& data)
{
	string name;
	double digit;
	char ch;

	while (cin >> name)
	{
		cin >> digit;
		data[name].m_sum += digit;
		data[name].m_count++;
		cin.get(ch);
		if (ch == '\n')
			break;
		else
			cin.putback(ch);
	}
}

void My_printf(Data data)
{
	double all_sum = 0.0;
	int all_count = 0;
	for (Data::iterator p = data.begin();
		p != data.end();
		p++)
	{
		cout << (*p).first << ":sum = " << (*p).second.m_sum
			<< ",ave = " << (*p).second.m_sum / (*p).second.m_count << endl;

		all_sum += (*p).second.m_sum;
		all_count += (*p).second.m_count;
	}

	cout << "all_sum = " << all_sum << ",all_ave = " << all_sum / all_count;
	cout << endl;
}

//总结：
/*
cin 的特性：
	使用cin时，无论有用字符前还是后有多少空格，都会被cin 自动忽略
*/

