/*
从这个程序我认识到：
1、指针数组在堆中分配后，必须手动销毁每一个指针，不能指望delete[]整个数组来释放所有内存；
2、使用类的初始化表达式时，不能假设编译器先对哪个变量的赋值，血的教训！！
3、同时我也学会了动态申请指针数组

出彩的地方：
使用 “&” 方法来模拟概率：如任意数和3（二进制）相与，只用四分之一的可能的到0.

问题：
指针变量在生命周期结束后不会自动调用析构函数？？？

问题的解：
重新回顾对象析构函数何时调用：
1、对象生命周期结束后（对于在栈中创建的对象）
2、指针所指向的在堆中分配的对象，必须手动调用delete来释放内存，此时才会调用析构函数
3、如果a是b的成员，那么当b的析构函数被调用时,a的析构函数也会被调用。

说明：
此实现中跳表的层数我假设从1层开始，但是存储的时候由于使用的是数组，因此与实际相差1.

最后修改：
2019/3/2   紫翼之狮
*/

#include <iostream>
#include <ctime>
using namespace std;

template<class T1,class T2>
class SlipNode {
public:
	SlipNode() {
	};
	SlipNode(int level, T1 k, T2 value);
	~SlipNode();

public:
	T1 m_k;
	T2 m_value;
	int m_level;
	SlipNode** m_ppforward;      		//可变前向指针数组 
};

template<class T1,class T2>
class SlipList {
public:
	SlipList(const int maxlevel = 16, const int maxbit = 32);
	~SlipList();
	void Insert(const T1& key, const T2& value);
	void Delete(const T1& key);
	void Display();
	int Random();
	int SearchValue(const T1& k);				//根据索引关键字返回值，如果不存在则返回-1 
	SlipNode<T1,T2>* SearchNode(const T2& value);	//根据值返回节点，如果不存在则返回NULL 

private:
	int RandomLevel();

private:
	SlipNode<T1,T2>* m_phead;
	int m_level;							//这是实际的层数，总比数组中存储的值大一
	const int MAX_LEVEL;
	const int MAX_BIT;
	int m_random_bit;
	int m_bit_left;
};

template<class T1,class T2>
SlipNode<T1,T2>::SlipNode(int level, T1 k, T2 value) :m_k(k), m_value(value) {
	m_level = level < 1 ? 1 : level;
	m_ppforward = new SlipNode<T1,T2>*[m_level];
	for (int i = 0; i < m_level; ++i) {
		m_ppforward[i] = NULL;
	}
}

template<class T1,class T2>
SlipNode<T1,T2>::~SlipNode() {
	cout << "index:" << m_k << " is deleted!" << endl;
	if (m_ppforward)
		delete[] m_ppforward;
	m_ppforward = NULL;
}

template<class T1, class T2>
SlipList<T1,T2>::SlipList(const int maxlevel, const int maxbit) :m_level(1), MAX_LEVEL(maxlevel), MAX_BIT(maxbit), m_bit_left(MAX_BIT) {
	m_phead = new SlipNode<T1,T2>(MAX_LEVEL, -1, -1);
	m_random_bit = Random();
}

template<class T1, class T2>
SlipList<T1,T2>::~SlipList() {
	if (m_phead) {
		SlipNode<T1,T2>* p = m_phead;
		while (p) {
			m_phead = p->m_ppforward[0];
			delete p;
			p = m_phead;
		}
	}
}

template<class T1, class T2>
int SlipList<T1,T2>::Random() {
	srand(time(0));
	return rand();
}

template<class T1, class T2>
int SlipList<T1,T2>::RandomLevel() {
	int level = 1;
	int b;
	do {
		b = m_random_bit & 3;				//1/4概率为0,也就是说层数增加的概率是（1/4）^n 
		if (!b)
			level++;
		m_random_bit >>= 2;
		m_bit_left -= 2;
		if (m_bit_left == 0) {
			m_random_bit = Random();
			m_bit_left = MAX_BIT;
		}
	} while (!b);
	return (level > (MAX_LEVEL - 1) ? (MAX_LEVEL - 1) : level);
}

template<class T1, class T2>
int SlipList<T1,T2>::SearchValue(const T1& k) {
	int l = m_level;
	SlipNode<T1,T2>* p = m_phead;
	SlipNode<T1,T2>* q = NULL;
	while (l > 0) {
		while ((p = p->m_ppforward[l-1]) && (p->m_k < k)) q = p;
		l--;
	}
	if (!q || q->m_k != k) {
		return -1;
	}
	return q->m_value;
}

template<class T1, class T2>
SlipNode<T1,T2>* SlipList<T1,T2>::SearchNode(const T2& value) {
	int l = m_level;
	SlipNode<T1,T2>* p = m_phead;
	SlipNode<T1,T2>* q = NULL;
	while (l > 0) {
		while ((q = p->m_ppforward[l-1]) && (q->m_value < value)) p = q;
		l--;
	}
	if (!q || q->m_value != value) {
		return NULL;
	}
	return q;
}

template<class T1, class T2>
void SlipList<T1,T2>::Insert(const T1& key, const T2& value) {
	int l = m_level;
	SlipNode<T1,T2>** update = new SlipNode<T1,T2>*[MAX_LEVEL];
	SlipNode<T1,T2>* p = m_phead;
	SlipNode<T1,T2>* q = NULL;
	int level = RandomLevel();

	while (l > 0) {
		while (q = p->m_ppforward[l - 1]) {
			if(q->m_value < value)
				p = q;
			
		}
		update[l-1] = p;
		l--;
	}

	if (q && q->m_value == value) {
		q->m_value = value;
		delete[] update;
		update = NULL;
		return;
	}

	if (level > m_level) {
		level = ++m_level;						//这个地方有小问题，因为毕竟层次是有限的，如果m_level+1后大于MAX_LEVEL 
		update[level-1] = m_phead;				//就会出错，但是层数越大概率越小，因此可近乎认为不可能超过MAX_LEVEL 
	}

	q = new SlipNode<T1,T2>(level, key, value);
	while (level > 0) {
		p = update[level-1];
		q->m_ppforward[level-1] = p->m_ppforward[level-1];
		p->m_ppforward[level-1] = q;
		level--;
	}
	delete[] update;
	update = NULL;
}

template<class T1, class T2>
void SlipList<T1,T2>::Delete(const T1& key) {
	int level = m_level;
	int curlevel = m_level;
	SlipNode<T1,T2>** update = new SlipNode<T1,T2>*[MAX_LEVEL];
	SlipNode<T1,T2>* p = m_phead;
	SlipNode<T1,T2>* q = NULL;

	while (level > 0) {
		while ((q = p->m_ppforward[level-1]) && (q->m_k < key)) p = q;
		update[level-1] = p;
		level--;
	}

	if (q->m_k != key) {
		delete[] update;
		update = NULL;
		return;
	}

	for (level = 1; level <= curlevel && (p = update[level-1])->m_ppforward[level-1] == q; ++level) {
		p->m_ppforward[level-1] = q->m_ppforward[level-1];
	}
	delete q;

	while (curlevel > 0 && m_phead->m_ppforward[curlevel-1] == NULL) {
		curlevel--;
	}
	m_level = curlevel;
	delete[] update;
	update = NULL;
}

template<class T1, class T2>
void SlipList<T1,T2>::Display() {
	cout << "list level:" << m_level << endl;
	for (SlipNode<T1,T2>* p = m_phead->m_ppforward[0]; p; p = p->m_ppforward[0]) {
		cout << "key: " << p->m_k << " value: " << p->m_value << " level: " << p->m_level << endl;
	}
}

int main(int argc, char* argv[]) {
	SlipList<int,double>* list = new SlipList<int,double>();
	for (int i = 1; i <= 5; ++i) {
		list->Insert(i, i + 0.3);
	}
	list->Display();
	list->Delete(2);
	cout << "delete key = 2:" << endl;
	list->Display();
	delete list;
	list = NULL;

	system("pause");
	return 0;
}


