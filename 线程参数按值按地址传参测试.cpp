#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

/*
1�������̵߳�boolֵ�������ж����� ��Ϊʲô���� 
2��ʹ��yeild()Ȼ���ٻ����̵߳ĵ���˳���ƺ���jion()�й�
3����Ҫ��������̣߳�Ӧ��ʹ��condition_variable�������ȴ� 
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
