/*
��ȡ�ļ��е����ݣ�������Сֵ ���ֵ ƽ��ֵ��������Щֵ�������һ���ļ���

���루���̣������������ļ���
���루�ļ�����һ����ֵ����
������ļ�����ֵ�ĸ�������Сֵ�����ֵ��ƽ��ֵ
*/

#include <iostream>//cout,cin
#include <string>
#include <fstream>//ifstream,ofstream
#include <cassert>//assert
#include <cfloat>//DBL_MIN,DBL_MAX

using namespace std;

int main(int argc, char *argv[])
{
	cout << "���������ڼ����ļ� 'cfile'����ֵ���������С�Լ�ƽ��ֵ "
		<< "���������ߴ����ļ� 'cnew'" << endl;
	cout << endl;

	//---------------���벿��-----------------
	cout << "��������Ҫ��ȡ���ļ�����";
	string infile;
	cin >> infile;
	ifstream fin(infile.data());//��������һ�����ļ���ͨ������ע��open���������ĺ����������ļ��ĺ���
	assert(fin.is_open());

	int count = 0;
	double reading,
		minimum = DBL_MAX,//���ܽ�maximum ��ʼ��Ϊ DBL_MAX
		maximum = DBL_MIN,
		sum = 0;

	for(;;)
	{
		fin >> reading;//��һ�������ļ���ͨʱ���൱���ļ���ˮԴ�������������ļ���������ˮ��һ�������������У�ֻ����ȡ������ >> ����������ȡ��Ŀ����
		count++;
		sum += reading;//�˲����ϲ�Ӧ�� fin.eof()֮ǰ���������ܱ��������ļ�
		if (fin.eof())
			break;
		
		if (reading < minimum)
			minimum = reading;
		if (reading > maximum)
			maximum = reading;
	}
	fin.close();

	//-----------------------�������----------------------
	cout << "����������ļ������֣�";
	string outfile;
	cin >> outfile;

	ofstream fo(outfile.data());
	assert(fo.is_open());

	fo << "\n-->" << infile << "�ļ��й��� " << count << "����ֵ��"
		<< "��ֵ�ķ�Χ�� " << minimum << " �� " << maximum << "֮��"
		<< "����ֵ��ƽ��ֵΪ " << sum / count << endl;

	fo.close();

	cout << "Processing complete.\n";
}