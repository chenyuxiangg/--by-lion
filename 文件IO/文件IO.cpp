/*
读取文件中的数据，计算最小值 最大值 平均值，并将这些值输出到另一个文件中

输入（键盘）：输入和输出文件名
输入（文件）：一个数值序列
输出（文件）：值的个数，最小值，最大值，平均值
*/

#include <iostream>//cout,cin
#include <string>
#include <fstream>//ifstream,ofstream
#include <cassert>//assert
#include <cfloat>//DBL_MIN,DBL_MAX

using namespace std;

int main(int argc, char *argv[])
{
	cout << "本程序用于计算文件 'cfile'中数值的最大与最小以及平均值 "
		<< "，并将三者存入文件 'cnew'" << endl;
	cout << endl;

	//---------------输入部分-----------------
	cout << "请输入您要读取的文件名：";
	string infile;
	cin >> infile;
	ifstream fin(infile.data());//声明并打开一个与文件联通的流，注意open（）是流的函数，不是文件的函数
	assert(fin.is_open());

	int count = 0;
	double reading,
		minimum = DBL_MAX,//不能将maximum 初始化为 DBL_MAX
		maximum = DBL_MIN,
		sum = 0;

	for(;;)
	{
		fin >> reading;//当一个流于文件联通时，相当于文件是水源，流是渠道，文件的内容像水流一样流到流对象中，只用提取操作符 >> 将内容在提取到目标中
		count++;
		sum += reading;//此步与上步应在 fin.eof()之前，这样才能遍历整个文件
		if (fin.eof())
			break;
		
		if (reading < minimum)
			minimum = reading;
		if (reading > maximum)
			maximum = reading;
	}
	fin.close();

	//-----------------------输出部分----------------------
	cout << "请输入输出文件的名字：";
	string outfile;
	cin >> outfile;

	ofstream fo(outfile.data());
	assert(fo.is_open());

	fo << "\n-->" << infile << "文件中共有 " << count << "个数值，"
		<< "数值的范围在 " << minimum << " 到 " << maximum << "之间"
		<< "且数值的平均值为 " << sum / count << endl;

	fo.close();

	cout << "Processing complete.\n";
}