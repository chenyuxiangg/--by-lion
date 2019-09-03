#include "iostream"
using namespace std;
class student
{public:
	student(int num, int age, float score);
	void total();
	static float average();
private:
	int num;
	int age;
	float score;
	static float sum;
	static int count;
};

student :: student(int num,int age,float score):num(num),age(age),score(score)
{}

void student :: total()
{
	sum += score;
	count++;
}

float student :: average()
{
	return (sum / count);
}

float student::sum = 0;
int student::count = 0;

int main(int argc,char* argv[])
{
	int n;
	cout << "请输入学生个数《1~10》:";
	cin >> n;
	student stu[10] =
	{
		student(10010,18,93),
		student(10020,18,68),
		student(10030,18,55),
		student(10040,18,88),
		student(10050,18,66),
		student(10060,18,84),
		student(10070,18,53),
		student(10080,18,56),
		student(10090,19,92),
		student(10100,19,100)
	};
	for (int i = 0; i < n; i++)
		stu[i].total();
	cout << "前" << n << "个同学的平均成绩为：" << student::average() << endl; //一般通过类名调用静态成员函数

	return 0;
}