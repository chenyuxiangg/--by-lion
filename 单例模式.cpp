/*
*����ģʽ��Ҫ˽�еĹ��캯����˽�еĸ��ƹ��캯���Լ�˽�еĵȺŸ�ֵ������
*����ģʽ˵���˾���������һ���ڴ棬�����ö��ָ��ȥָ������
*��̬��Ա���������ڷǺ���������ڶ��塣������ָ��Ҳ�С� 
*/

#include <iostream>
using namespace std;

class A{
	private:
		A(){
			i = 0;
			cout << "����ģʽ" << endl;
		}
		
		A(const A&){
		}
		
		A& operator=(const A&)
		{
		}
		
		
	public:
		static A* GetA()
		{
			return a;
		}
		
		int Geti()
		{
			return i;
		}
		
		void Seti(int k)
		{
			i = k;
		}
		~A()
		{
			delete a;
			a = NULL;
		}
		
	private:
		static A* a;
		int i;
}; 

A* A::a = new A();

//���������Ե���ģʽ�Ƿ���Ա��̳�
//����ģʽ���ɼ̳У���Ϊ���캯��˽�� 

/*
class B : public A{
	public:
		B(){
			cout << "����ģʽ���Լ̳�" << endl;
		}
};
*/

int main(int argc,char* argv[])
{
	A* b = A::GetA();
	b->Seti(5);
	A* c = A::GetA();
	cout << c->Geti() << endl;
	return 0;
}
