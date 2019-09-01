#include "Writer.h"
using namespace std;

Cwriter::Cwriter(){
}

Cwriter::~Cwriter(){
}

void Cwriter::Write(ItemStory* it,int da,bool& r)
{
	unique_lock<mutex> lock(it->mtx);
	while(!r)
	{
		cout << "д���ڵȴ�.." << endl;
		it->ready.wait(lock);
	}
	while(!(it->can_write))
	{
		cout << "�ȴ�����ȫ���˳�..." << endl;
		it->enable_write.wait(lock);
	}
	it->can_read = false;
	cout << "Writer: I am writing..." << endl;
	cout << "story will be " << da << endl;
	it->data = da;
	it->can_read = true;
	it->enable_read.notify_all();
	lock.unlock();
}
