#pragma once
#ifndef PRODUCE_AND_CONSUME_H
#define PRODUCE_AND_CONSUME_H

#include <mutex>
#include <condition_variable>
#define MAX_BUF 800
using namespace std;

typedef struct ItemRepository {
	int item_buffer[MAX_BUF];
	size_t read_position;
	size_t write_position;
	mutex mtx;
	condition_variable repo_not_full;
	condition_variable repo_not_empty;
} ItemRepositoy;

class CProduceAndConsume
{
public:
	CProduceAndConsume();
	virtual ~CProduceAndConsume();
	virtual void Task(ItemRepository* ir) = 0;
};

class CProduce :public CProduceAndConsume {
public:
	CProduce(int pcount);
	virtual ~CProduce();
	virtual void Task(ItemRepository* ir);
	void ProduceItem(ItemRepository* ir,int itm);

private:
	int m_producecount;
};

class CConsume :public CProduceAndConsume {
public:
	CConsume(int ccont);
	virtual ~CConsume();
	virtual void Task(ItemRepository* ir);
	int ConsumeItem(ItemRepository* ir);

private:
	int m_data;
	int m_consumecount;
};

#endif