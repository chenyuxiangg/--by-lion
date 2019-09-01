#include <iostream>
using namespace std;

class Base{
	public :
		void Show(){
			toString();
		}
	private:
		virtual void toString(){
			cout << "base toString." << endl;
		}
}; 

class A:public Base{
	private:
		virtual void toString(){
			cout << "A toString." << endl;
		}
};

int main(int argc,char* argv[]){
	Base* pb = new A();
	pb->Show();
	delete pb;
	pb = nullptr;
	return 0;
}
