#include "Reader.h"
int Creader::max_count;
int Creader::reader_count;

Creader::Creader(int i)
{
	id = i;
	reader_count++;
	max_count = MAX_COUNT;
}

Creader::~Creader(){
}

void Creader::Read(ItemStory* it,bool& r)
{
	unique_lock<mutex> lock(it->mtx);
	while(!r)
	{
		cout << "¶ÁÕßÔÚµÈ´ý.." << endl;
		it->ready.wait(lock);
	}
	while(!(it->can_read))
	{
		it->enable_read.wait(lock);
	}
	if(id < MAX_COUNT)
	{
		it->can_write = false;
		cout << id << " is reading..." << endl;
		cout << "the data is " << it->data << endl; 
		cout << id << " completed read." << endl;
		reader_count--;
		it->enable_read.notify_all();
	
		if(reader_count <= 0)
		{
			it->can_write = true;
			it->enable_write.notify_all();
		}
	}
	else
	{
		cout << "reader number is max..." << endl;
		reader_count--;
	}

	lock.unlock();
}


