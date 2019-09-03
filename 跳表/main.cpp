/*
�������������ʶ����
1��ָ�������ڶ��з���󣬱����ֶ�����ÿһ��ָ�룬����ָ��delete[]�����������ͷ������ڴ棻
2��ʹ����ĳ�ʼ�����ʽʱ�����ܼ���������ȶ��ĸ������ĸ�ֵ��Ѫ�Ľ�ѵ����
3��ͬʱ��Ҳѧ���˶�̬����ָ������

���ʵĵط���
ʹ�� ��&�� ������ģ����ʣ�����������3�������ƣ����룬ֻ���ķ�֮һ�Ŀ��ܵĵ�0.

���⣺
ָ��������������ڽ����󲻻��Զ�������������������

����Ľ⣺
���»ع˶�������������ʱ���ã�
1�������������ڽ����󣨶�����ջ�д����Ķ���
2��ָ����ָ����ڶ��з���Ķ��󣬱����ֶ�����delete���ͷ��ڴ棬��ʱ�Ż������������
3�����a��b�ĳ�Ա����ô��b����������������ʱ,a����������Ҳ�ᱻ���á�

˵����
��ʵ��������Ĳ����Ҽ����1�㿪ʼ�����Ǵ洢��ʱ������ʹ�õ������飬�����ʵ�����1.

����޸ģ�
2019/3/2   ����֮ʨ
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
	SlipNode** m_ppforward;      		//�ɱ�ǰ��ָ������ 
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
	int SearchValue(const T1& k);				//���������ؼ��ַ���ֵ������������򷵻�-1 
	SlipNode<T1,T2>* SearchNode(const T2& value);	//����ֵ���ؽڵ㣬����������򷵻�NULL 

private:
	int RandomLevel();

private:
	SlipNode<T1,T2>* m_phead;
	int m_level;							//����ʵ�ʵĲ������ܱ������д洢��ֵ��һ
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
		b = m_random_bit & 3;				//1/4����Ϊ0,Ҳ����˵�������ӵĸ����ǣ�1/4��^n 
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
		level = ++m_level;						//����ط���С���⣬��Ϊ�Ͼ���������޵ģ����m_level+1�����MAX_LEVEL 
		update[level-1] = m_phead;				//�ͻ�������ǲ���Խ�����ԽС����˿ɽ�����Ϊ�����ܳ���MAX_LEVEL 
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


