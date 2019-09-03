#include "produce_and_consume.h"
#include <iostream>
#include <thread>
#include <windows.h>
using namespace std;

CProduceAndConsume::CProduceAndConsume()
{
}

CProduceAndConsume::~CProduceAndConsume()
{
}

CProduce::CProduce(int pcount):CProduceAndConsume()
{
	m_producecount = pcount;
}

CProduce::~CProduce(){}

void CProduce::Task(ItemRepository* ir)
{
	for (int i = 1; i <= m_producecount; ++i)
	{
		cout << "Produce the" << i << "th item..." << endl;
		ProduceItem(ir, i);
	}
}

void CProduce::ProduceItem(ItemRepository* ir, int itm)
{
	unique_lock<mutex> lock(ir->mtx); //将公共缓冲区锁住
	while ((ir->write_position + 1) % MAX_BUF == ir->read_position)
	{
		cout << "Produce is waiting a empty..." << endl;
		(ir->repo_not_full).wait(lock);
	}
	ir->item_buffer[ir->write_position] = itm;
	(ir->write_position)++;

	if (ir->write_position == MAX_BUF)
		ir->write_position = 0;

	(ir->repo_not_empty).notify_all();//通知消费者缓冲区不为空
	lock.unlock();//解锁
}

CConsume::CConsume(int ccount) :CProduceAndConsume()
{
	m_consumecount = ccount;
}

void CConsume::Task(ItemRepository* ir)
{
	int count = 1;
	while(1)
	{
		Sleep(2);
		m_data = ConsumeItem(ir);
		count++;
		cout << "Consume The" << m_data << "th item..." << endl;
		if (count > m_consumecount)
			break;
	}
}

int CConsume::ConsumeItem(ItemRepository* ir)
{
	int d = -1;
	unique_lock<mutex> lock(ir->mtx);
	while (ir->read_position == ir->write_position)
	{
		cout << "Consume is waiting an data..." << endl;
		(ir->repo_not_empty).wait(lock);
	}
	d = ir->item_buffer[ir->read_position];
	(ir->read_position)++;
	if (ir->read_position == MAX_BUF)
		ir->read_position = 0;
	(ir->repo_not_full).notify_all();
	lock.unlock();
	return d;
}

CConsume::~CConsume(){}