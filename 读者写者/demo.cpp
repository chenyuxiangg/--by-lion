#include <vector>
#include "Writer.h"
#include "Reader.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool ready = false;
ItemStory itm;
void wtask(Cwriter*,int);
void rtask(Creader*);
void go();

int main(int argc, char** argv) {
	
	itm.data = 0;
	itm.can_read = true;
	itm.can_write = true;
	
	Cwriter* writer = new Cwriter();
	vector<Creader*> rvec;
	vector<thread> tvec;
	for(int i = 0;i < 10;++i)
	{
		rvec.push_back(new Creader(i));
		tvec.push_back(thread(rtask,rvec[i]));
	}
	thread w(wtask,writer,5);
	
	go();
	
	w.join();
	for(auto& th : tvec)
	{
		th.join();
	}
	for(auto it : rvec)
	{
		delete it;
		it = nullptr;
	}
	return 0;
}

void wtask(Cwriter* pw,int data)
{
	pw->Write(&itm,data,ref(ready));
}

void rtask(Creader* pr)
{
	pr->Read(&itm,std::ref(ready));
}

void go()
{
	unique_lock<mutex> lock(itm.mtx);
	cout << "go!" << endl;
	ready = true;
	itm.ready.notify_all();
	lock.unlock();
}
