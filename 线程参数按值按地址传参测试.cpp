#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

/*
1、传入线程的bool值不能起判断作用 ，为什么？？ 
2、使用yeild()然后再唤醒线程的调用顺序似乎和jion()有关
3、想要随机唤醒线程，应该使用condition_variable变量来等待 
*/

void prit(char,int*);

mutex mtx;
condition_variable cv;
int i = 0;
bool ready = false;

int main(int argc,char* argv[])
{
	thread a(prit,'a',&i);
	thread b(prit,'b',&i);
	thread c(prit,'c',&i);
	
	unique_lock<mutex> lock(mtx);
	ready = true;
	i++;
	cout << "i = " << i << endl;
	cv.notify_all();
	lock.unlock();
	
	a.join();
	b.join();
	c.join();
	
	return 0;
 } 
 void prit(char k,int* i)
 {
 	unique_lock<mutex> lock(mtx);
 	while(!ready) cv.wait(lock);
 	
 	cout <<  k << " " << *i << endl;
 	lock.unlock();
 }
