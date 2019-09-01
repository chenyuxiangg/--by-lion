#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable
#include <windows.h>

//线程从其被初始化时就开始执行
//为什么while中的语句只执行了一次，因为被wait()阻塞了
//join()到底有什么作用？为什么把go()放到join()后边就一直等待？
//为什么将jion删除就会提示terminate called without an active exception??
/*
thread::join()是个简单暴力的方法，主线程等待子进程期间什么都不能做，一
般情形是主线程创建thread object后做自己的工作而不是简单停留在join上。
thread::join()还会清理子线程相关的内存空间，此后thread object将不再和
这个子线程相关了，即thread object不再joinable了，所以join对于一个子
线程来说只可以被调用一次，为了实现更精细的线程等待机制，可以使用条
件变量等机制。
*/ 

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void print_id (int id) {
  std::unique_lock<std::mutex> lck(mtx);
  while (!ready)
  {
  	std::cout << "正在等待开始..." << std::endl;
  	cv.wait(lck);
  }
  // ...
  std::cout << "thread " << id << '\n';
}

void go() {
  std::unique_lock<std::mutex> lck(mtx);
  ready = true;
  cv.notify_all();
}

int main ()
{
  std::thread threads[10];
  // spawn 10 threads:
  for (int i=0; i<10; ++i)
    threads[i] = std::thread(print_id,i);

  std::cout << "10 threads ready to race...\n";
  Sleep(5000);
  go();

  for (auto& th : threads) th.join();
  
  return 0;
}
