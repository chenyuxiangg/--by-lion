/*
����һ���пո�ָ��ģ����֣�ֵ���ԣ����е�ÿ���������пհ׷ָ���һ�����ʣ�ֵ��һ��������һ��������
�����㲢��ӡ����Ӧ��ÿ�����ֵ�����ֵ֮�ͼ�ƽ��ֵ���Լ��������ֵĺ���ƽ��ֵ��
*/

/*
map �� pair����������ϵ��
��ͬ�㣺���ǹ���������ֵ���Ϳ�����ͬ��Ҳ���Բ�ͬ
��ͬ�㣺map:����������һ�����ݱ�����ϵ
pair:����������һ�����ݿ�������ϵ��Ҳ����û����ϵ��

��ϵ��map ���� pair ��ɵ�

����insert()��map��߲�ֵʱ�����������������Ƿ����ɹ���

pair<map<int, string>::iterator, bool> Insert_Pair;
Insert_Pair = mapStudent.insert(map<int, string>::value_type (1, "student_one"));
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;

//�������ͣ�����ֵ�ĺ������ô���
struct Stat {
	double m_sum;
	int m_count;
	Stat() :m_sum(0.0), m_count(0) {}//���캯��
};

//����һ�Ź���Stat �� string �ı�
typedef map<string, Stat> Data;

//����ÿ�����ֶ�Ӧ��ֵ�ĺ�
void Sum(Data& data);

//���㲢��ӡ�������ֵĺ���ƽ��ֵͬʱ��ӡÿ�����ֶ�Ӧ��ֵ�ĺ���ƽ��ֵ
void My_printf(Data data);

//��������
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

//�ܽ᣺
/*
cin �����ԣ�
	ʹ��cinʱ�����������ַ�ǰ���Ǻ��ж��ٿո񣬶��ᱻcin �Զ�����
*/

