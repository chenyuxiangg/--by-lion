#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread> 
#include <vector>
#include <ctime>
using namespace std;

class Semaphore{
	private:
		int wakeups;
	
	public:
		Semaphore();
		~Semaphore();
		void wait();
		void signal();
		
	public:
		mutex mtx;
		condition_variable cv;
		int count;
};

typedef struct ItemStory{
	Semaphore cons_sema;
	Semaphore prod_sema;
	vector<int> data;
}ItemStory;

class Cproduce{
	public:
		Cproduce(int id);
		~Cproduce();
		void produce(ItemStory* pit);
		
	private:
		int m_da;
		int m_id;
};

class Cconsume{
	public:
		Cconsume(int i);
		~Cconsume();
		void consume(ItemStory* pit);
		
	private:
		int id;
};

bool ready = false;
vector<thread> vectc;
vector<thread> vectp;

void go(); 
void ctask(Cconsume*);
void ptask(Cproduce*);

ItemStory it;

int main(int argc,char* argv[])
{
	vector<Cconsume*> vecc;
	vector<Cproduce*> vecp;
	it.cons_sema.count = 0;
	
	for(int i = 0; i < 10;++i)
	{
		vecc.push_back(new Cconsume(i));
		vecp.push_back(new Cproduce(i));
	}
	
	for(int i = 0;i < 10;++i)
	{
		vectc.push_back(thread(ctask,vecc[i]));
	}
	for(int i = 0;i < 10; ++i)
	{
		vectp.push_back(thread(ptask,vecp[i]));
	}
	
	//go();
	
	for(auto& t : vectc)
	{
		t.join();
	}
	for(auto& t : vectp)
	{
		t.join();
	}
	return 0;
}

//void go()
//{
//	unique_lock<mutex> lock(it.cons_sema.mtx);
//	unique_lock<mutex> loc(it.prod_sema.mtx);
//	cout << "go!" << endl;
//	ready = true;
//	it.cons_sema.cv.notify_all();
//	it.prod_sema.cv.notify_all();
//	loc.unlock();
//	lock.unlock();
//}

void ctask(Cconsume* pc)
{
//	unique_lock<mutex> lock(it.cons_sema.mtx);
//	while(!ready)
//	{
//		it.cons_sema.cv.wait(lock);
//	}
//	lock.unlock();
	pc->consume(&it);
	delete pc;
	pc = nullptr;
}

void ptask(Cproduce* pp)
{
//	unique_lock<mutex> lock(it.prod_sema.mtx);
//	while(!ready)
//	{
//		it.prod_sema.cv.wait(lock);
//	}
//	lock.unlock();
	pp->produce(&it);
	delete pp;
	pp = nullptr;
}

Semaphore::Semaphore()
{
	count = 5;
	wakeups = 0;
 } 
 
 void Semaphore::wait()
 {
 	unique_lock<mutex> lock(mtx);
 	if(--count < 0)
 	{
 		cv.wait(lock,[&]()->bool{return wakeups > 0;});
 		--wakeups;
	 }
	lock.unlock();
 }
 
 //资源数加一，通知一个线程可以执行 
 void Semaphore::signal()
 {
 	unique_lock<mutex> lock(mtx);
 	if(++count <= 0)
 	{
 		++wakeups;
 		cv.notify_one();
	 }
	lock.unlock();
 }
 
 Semaphore::~Semaphore()
 {
 }
 
 Cproduce::Cproduce(int id)
 {
 	m_id = id;
 }
 
 Cproduce::~Cproduce(){
 }
 
 void Cproduce::produce(ItemStory* pit)
 {
 	pit->prod_sema.wait();
 	unique_lock<mutex> lock(pit->prod_sema.mtx);
 	srand(time(0));
 	m_da = rand()%10 + 1;
 	cout << m_id << " produced a product:" << m_da << endl;
 	pit->data.push_back(m_da);
 	lock.unlock();
 	pit->cons_sema.signal();
 }
 
 Cconsume::Cconsume(int i)
 {
 	id = i;
 }
 
 Cconsume::~Cconsume()
 {
 }
 
 void Cconsume::consume(ItemStory* pit)
 {
 	pit->cons_sema.wait();
 	unique_lock<mutex> lock(pit->cons_sema.mtx);
 	int da = *(--(pit->data.end()));
 	pit->data.pop_back();
 	cout << id << "consumed a product" << da << endl;
 	lock.unlock();
 	pit->prod_sema.signal();
 }
