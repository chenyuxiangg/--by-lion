#include <iostream>
#include "queue.h"
using namespace std;

int main(int argc,char* argv[])
{
	Queue<int> queue;
	queue.Push(1);
	queue.Push(2);
	queue.Push(3);
	queue.Push(4);
	queue.Push(5);
	queue.Push(6);
	queue.Push(7); 
	queue.Push(8);
	queue.Push(9);
	//queue.Push(2);

	/*queue.Front();
	queue.Real();

	int elem;
	queue.Pop(elem);

	queue.Front();
	queue.Real();

	queue.Push(10);
	queue.Front();
	queue.Real();*/

	int e;
	queue.Pop(e);
	queue.Pop(e);
	queue.Pop(e);
	queue.Pop(e);
	queue.Pop(e);
	queue.Pop(e);
	queue.Pop(e);
	queue.Pop(e);
	//queue.Pop(e);
	//queue.Pop(e);
	queue.Front();
	queue.Real();

	system("pause");
	return 0;
}
