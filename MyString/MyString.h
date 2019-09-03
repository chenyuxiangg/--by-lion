#pragma once
#include <iostream>
using namespace std;

class mystring {
	struct mySrep;
	mySrep* rep;

public:
	class myRange{};
	class myCref;
	int getn();

	mystring();
	mystring(const char*);
	mystring(const mystring&);
	~mystring();
	mystring& operator =(const char*);
	mystring& operator =(const mystring&);

	inline void mycheck(int i) const;
	inline char myread(int i) const;
	inline void mywrite(int i, char c);
	inline myCref operator [](int i);
	inline char operator [](int i) const;
	inline int mysize() const;

	mystring& operator +=(const mystring&);
	mystring& operator +=(const char*);
	friend ostream& operator <<(ostream&, const mystring&);
	friend istream& operator >> (istream&, const mystring&);
	friend bool operator ==(const mystring& x, const char* s);
	friend bool operator ==(const mystring& x, const mystring& y);
	friend bool operator !=(const mystring& x, const char* s);
	friend bool operator !=(const mystring& x, const mystring& y);
};

struct mystring::mySrep {
	char* s;
	int sz;
	int n;

	mySrep(int nsz, const char* p)
	{
		n = 1;
		sz = nsz;
		s = new char[sz + 1];
		strcpy_s(s,sz+1,p);
	}

	~mySrep() { delete[] s; }

	mySrep* get_own_copy()
	{
		if (n == 1)
			return this;
		n--;
		return new mySrep(sz, s);
	}

	void myassign(int nsz, const char* p)
	{
		if (sz != nsz)
		{
			delete[] s;
			sz = nsz;
			s = new char[sz + 1];
		}
		strcpy_s(s, sz+1,p);
	}

private:
	mySrep(const mySrep&);
	mySrep& operator =(const mySrep&);
};

class mystring :: myCref {
	friend class mystring;
	mystring& s;
	int i;
	myCref(mystring& ss, int ii):s(ss),i(ii){}
public:
	operator char() const { 
		cout << "调用了 myCref::operator char() const" << endl;
		return s.myread(i); 
	}//将myCref类型转换为char类型
	void operator =(char c) { 
		cout << "调用了 void myCref::operator =(char c)" << endl;
		s.mywrite(i, c); 
	}//重点！！！！很棒
};

int mystring::getn(){return rep->n;}

inline void mystring::mycheck(int i) const {
	if (i < 0 || rep->sz <= i)
		throw myRange();
}

inline char mystring :: myread(int i) const {
	cout << "调用了 inline char mystring :: myread(int i) const" << endl;
	return rep->s[i];
}

inline void mystring::mywrite(int i,char p) {
	cout << "调用了 inline void mystring::mywrite(int i,char p)" << endl;
	rep = rep->get_own_copy();
	rep->s[i] = p;
}

inline mystring :: myCref mystring :: operator [](int i) {
	cout << "调用了 inline mystring :: myCref mystring :: operator [](int i)" << endl;
	mycheck(i);
	return myCref(*this, i);
}

inline char mystring :: operator [](int i) const {
	cout << "调用了 inline char mystring :: operator [](int i) const" << endl;
	mycheck(i);
	return rep->s[i];
}

inline int mystring::mysize() const {
	return rep->sz;
}

mystring::mystring()
{
	rep = new mySrep(0, "");
}

mystring::mystring(const mystring& x)
{
	cout << "调用了 mystring::mystring(const mystring& x)" << endl;
	x.rep->n++;
	rep = x.rep;
}

mystring::~mystring()
{
	if (--rep->n == 0)
		delete rep;
}

//弄不明白这个地方为什么要这样写
mystring& mystring::operator =(const mystring& x)
{
	cout << "调用了 mystring& mystring::operator =(const mystring& x)" << endl;
	x.rep->n++;//懂了，太棒了！当遇到s = s时，x.rep与rep是同一个，所以n++以及--n刚好抵消，引用不增不减
	if (--rep->n == 0)
		delete rep;
	rep = x.rep;
	return *this;
}

mystring::mystring(const char* s)
{
	cout << "调用了 mystring::mystring(const char* s)" << endl;
	rep = new mySrep(strlen(s), s);
}

//不明白什么时候引用计数加1，什么时候引用计数减1，为什么加，为什么减？
//假设有字符串x,存在多个mystring 对象共享它，当其中一个选择=(const char* s)的方式另立门户时
//，它之前共享的字符串被引用的次数就减1，至于为什么加，那就简单了，当有新的mystring对象共享
//字符串x的时候，它的引用计数就加1
mystring& mystring::operator =(const char* s)
{
	cout << "调用了 mystring& mystring::operator =(const char* s)" << endl;
	if (rep->n == 1)
	{
		rep->myassign(strlen(s), s);
	}
	else
	{
		rep->n--;
		rep = new mySrep(strlen(s), s);
	}
	return *this;
}

mystring& mystring::operator +=(const mystring& str)
{
	mystring tmp(this->rep->s);
	delete[] rep->s;
	rep->sz += str.rep->sz + 1;
	rep->s = new char[rep->sz];
	strcpy_s(rep->s, rep->sz, tmp.rep->s);
	strcpy_s(rep->s+tmp.rep->sz, rep->sz - tmp.rep->sz, str.rep->s);
	return *this;
}

mystring& mystring::operator +=(const char* s)
{
	mystring tmp(this->rep->s);
	size_t slen = strlen(s);
	delete[] rep->s;
	rep->sz += slen + 1;
	rep->s = new char[rep->sz];
	strcpy_s(rep->s, rep->sz, tmp.rep->s);
	strcpy_s(rep->s+tmp.rep->sz, rep->sz - tmp.rep->sz, s);
	return *this;
}

ostream& operator <<(ostream& out, const mystring& str)
{
	out << str.rep->s;
	return out;
}

istream& operator >> (istream& myin, const mystring& str)
{
	if (str.rep->s)
	{
		delete[] str.rep->s;
	}
	char* s = NULL;
	myin >> s;
	size_t slen = strlen(s);
	str.rep->sz = slen + 1;
	str.rep->s = new char[str.rep->sz];
	strcpy_s(str.rep->s, str.rep->sz, s);
	return myin;
}

bool operator ==(const mystring& x, const char* s)
{
	return (strcmp(x.rep->s, s) == 0);
}

bool operator ==(const mystring& x, const mystring& y)
{
	return(strcmp(x.rep->s, y.rep->s) == 0);
}

bool operator !=(const mystring& x, const char* s)
{
	return (strcmp(x.rep->s, s) != 0);
}

bool operator !=(const mystring& x, const mystring& y)
{
	return (strcmp(x.rep->s, y.rep->s) != 0);
}

mystring operator +(const mystring& str, const char* s)
{
	mystring tmp;
	tmp += str;
	tmp += s;
	return tmp;
}

mystring operator +(const mystring& x, const mystring& y)
{
	mystring tmp;
	tmp += x;
	tmp += y;
	return tmp;
}

