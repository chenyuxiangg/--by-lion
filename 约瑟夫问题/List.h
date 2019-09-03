#pragma once
#include <iostream>
using namespace std;

class List;
class Note
{public:
	friend class List;
	Note(int d);
	Note* getnext();
	int getdate();
	int getnum();
	void setnum(int num);
	Note();
	~Note();
private:
	int date;
	int num;
	Note* next;
};

void Note :: setnum(int nu)
{
	num = nu;
}

int Note :: getnum()
{
	return num;
}

int Note :: getdate()
{
	return date;
}

Note* Note::getnext()
{
	return next;
}

Note :: Note(int d)
{
	date = d;
	num = -1;
	next = NULL;
}

Note :: Note()
{
	date = 0;
	num = -1;
	next = NULL;
}

Note :: ~Note()
{}

class List
{public:
	List();
	~List();
	bool InsertNote(Note* n);
	bool OutNote(Note* n);
	bool Isempty();
	void ClearList();
	Note* geth();
	void seth(Note* n);
private:
	Note* h;//Í·½áµã
	int length;
};

void List :: seth(Note* n)
{
	h = n;
}

Note* List :: geth()
{
	return h;
}

void List :: ClearList()
{
	Note* p = h->next;
	Note* nxt = p;
	while(p->next != h)
	{
		nxt = p->next;
		delete p;
		p = nxt;
	}
	delete p;
	p = NULL;
	nxt = NULL;
	length = 1;
}


List :: List()
{
	h = new Note;
	h->next = h;
	length = 0;
}


List :: ~List()
{
	ClearList();
	delete h;
	h = NULL;
	length = 0;
}

bool List::Isempty()
{
	if (length == 0)
		return true;
	return false;
}

bool List :: InsertNote(Note* n)
{
	if (Isempty())
	{
		Note* p = h;
		h = n;
		h->next = h;
		delete p;
		p = NULL;
		length++;
		return true;
	}
	Note* CurrentNote = h;
	while(CurrentNote->next != h)
	{
		CurrentNote = CurrentNote->next;
	}
	CurrentNote->next = n;
	n->next = h;
	length++;
	return true;
}

bool List :: OutNote(Note* n)
{
	Note* Pre = h;
	while(Pre->next != n)
	{
		Pre = Pre->next;
	}
	Pre->next = n->next;
	delete n;
	n = NULL;
	length--;
	return true;
}

