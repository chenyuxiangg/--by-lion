#include"iostream"
using namespace std;
class squre
{private:
	double length;
public:
	squre(double x);
	void area()
	{
		cout << "�����ε����Ϊ�� " << length * length << endl;
	}
	inline void perimeter();
};

//���캯������
squre::squre(double x)
{
	length = x;
}

//������������
void squre::perimeter()  //����ֵ����Ӧ�������֮ǰ
{
	cout << "�����ε��ܳ�Ϊ�� " << 4 * length << endl;
}

int main(int argc,char * argv[])
{
	squre ss(2.1); //���˴�Ϊ�����������ʱֻ��������û��С�������˴���С����������������ʱ����С��
	ss.area();
	ss.perimeter();

	return 0;
}
