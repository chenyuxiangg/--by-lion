// condition_variable::wait (with predicate)
#include <iostream>           // std::cout
#include <thread>             // std::thread, std::this_thread::yield
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable

/*
这段代码演示了如何使用wait()函数的谓词来控制阻塞。
需要注意的是，该程序有一个主线程main()，在主线程中又创建了另一个子线程
consumer_thread,运行逻辑是：当主线程发现cargo不为0时，将主线程唤醒
子线程，并挂起自己一段时间。 
*/

std::mutex mtx;
std::condition_variable cv;

int cargo = 0;
bool shipment_available() {return cargo!=0;}

void consume (int n) {
	//std::cout << "创建了线程：" << std::this_thread::get_id() << std::endl;
  for (int i=0; i<n; ++i) {
    std::unique_lock<std::mutex> lck(mtx);
    cv.wait(lck,shipment_available);
    // consume:
    std::cout << cargo << '\n';
    cargo=0;
  }
}

int main ()
{
  std::thread consumer_thread (consume,10); 

  // produce 10 items when needed:
  for (int i=0; i<10; ++i) {
    while (shipment_available()) 
	{
		std::this_thread::yield();
	}
    std::unique_lock<std::mutex> lck(mtx);
    cargo = i+1;
    cv.notify_one();
  }

  consumer_thread.join();

  return 0;
}

