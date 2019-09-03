#include "produce_and_consume.h"

ItemRepository g_ir;

void task(CProduceAndConsume*);

int main(int argc, char* argv[])
{
	memset(&(g_ir.item_buffer), 0, MAX_BUF);
	CProduceAndConsume* pprodece = new CProduce(1000);
	CProduceAndConsume* pconsume = new CConsume(1000);

	thread producer(task,pprodece);
	thread consumer(task,pconsume);

	/*thread producer(&CProduce::Task,&pprodece,&g_ir);
	thread consumer(&CConsume::Task,&pprodece,&g_ir);*/

	producer.join();
	consumer.join();

	delete pconsume;
	delete pprodece;
	pconsume = NULL;
	pprodece = NULL;
	system("pause");
	return 0;
}

void task(CProduceAndConsume* cp)
{
	cp->Task(&g_ir);
}