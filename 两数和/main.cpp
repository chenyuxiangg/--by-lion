#include <iostream>
using namespace std;

class Node {
public:
	Node(int val = -1);
	~Node();
	void Update(int val);

public:
	int m_value;
	Node* m_next;
};

class List {
public:
	List();
	~List();
	void Delete(Node* node);
	void addNode(Node* node);
	void addNode(int val);
	void Display();

public:
	Node* m_head;
};

Node::Node(int val) :m_value(val), m_next(nullptr) {

}

Node::~Node() {
	if (m_next) {
		delete m_next;
		m_next = nullptr;
	}
}

void Node::Update(int val) {
	m_value = val;
}

List::List() :m_head(new Node()) {

}

List::~List() {
	Delete(m_head);
}

void List::Delete(Node* node) {
	while (node) {
		Delete(node->m_next);
	}
	if (node == nullptr)
		return;
	delete node;
	node = nullptr;
}

void List::addNode(Node* node) {
	Node* p = m_head;
	Node* q = p->m_next;
	while (q) {
		p = q;
		q = p->m_next;
	}
	p->m_next = node;
}

void List::addNode(int val) {
	if (val < 0)
		return;
	Node* newnode = new Node(val);
	addNode(newnode);
}

void List::Display() {
	Node* p = m_head->m_next;
	while (p) {
		cout << p->m_value;
		p = p->m_next;
	}
}

class Solution {
public:
	List* addTwoNumbers(List* l1, List* l2) {
		int c = 0;//½øÎ»
		List* newlist = new List();
		Node* p1 = l1->m_head->m_next;
		Node* p2 = l2->m_head->m_next;
		while (p1 && p2) {
			int sum = p1->m_value + p2->m_value + c;
			c = sum / 10;
			sum %= 10;
			newlist->addNode(sum);
			p1 = p1->m_next;
			p2 = p2->m_next;
		}
		Node* x = (p1 == nullptr || (p1 == nullptr && p2 == nullptr)) ? p2 : p1;
		while (c != 0) {
			if (x) {
				int sum = x->m_value + c;
				c = sum / 10;
				sum %= 10;
				newlist->addNode(sum);
			}
			else {
				newlist->addNode(c);
				c = 0;
			}
			if (x) {
				x = x->m_next;
			}
		}
		p1 = newlist->m_head;
		p2 = p1->m_next;
		while (p2) {
			p1 = p2;
			p2 = p2->m_next;
		}
		p1->m_next = x;
		return newlist;
	}
};

int main(int argc, char* argv[]) {
	Solution solu;
	List* l1 = new List();
	List* l2 = new List();
	List* res = nullptr;

	l1->addNode(1);
	l1->addNode(3);
	l1->addNode(9);

	l2->addNode(7);
	l2->addNode(9);

	res = solu.addTwoNumbers(l1, l2);
	res->Display();
	delete l1;
	delete l2;
	delete res;
	system("pause");
	return 0;
}