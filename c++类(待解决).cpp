#include <iostream>
#include <string>
using namespace std;
class student
{
public:
	student();
	void gz(string& mane);
	void xh(string& numb);
private:
	string m_name = 0;
	string m_num = 0;
};
student::student() :
	m_name("ÕÅÈı"), m_num("1007423165")
{}
void student :: gz(string& name)
{
	cout << "my name is " << name << "all the best!";
	cout << endl;
}

void student :: xh(string& numb)
{
	cout << "My nummber is " << numb;
	cout << endl;
}

int main(int argc[],char argv[])
{
	cout << "Please our new student!!" << endl;
	student stu1;
	stu1.gz(m_name);
	stu1.xh(n_num);
	return 0;
}