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
		cout << "������ myCref::operator char() const" << endl;
		return s.myread(i); 
	}//��myCref����ת��Ϊchar����
	void operator =(char c) { 
		cout << "������ void myCref::operator =(char c)" << endl;
		s.mywrite(i, c); 
	}//�ص㣡�������ܰ�
};

int mystring::getn(){return rep->n;}

inline void mystring::mycheck(int i) const {
	if (i < 0 || rep->sz <= i)
		throw myRange();
}

inline char mystring :: myread(int i) const {
	cout << "������ inline char mystring :: myread(int i) const" << endl;
	return rep->s[i];
}

inline void mystring::mywrite(int i,char p) {
	cout << "������ inline void mystring::mywrite(int i,char p)" << endl;
	rep = rep->get_own_copy();
	rep->s[i] = p;
}

inline mystring :: myCref mystring :: operator [](int i) {
	cout << "������ inline mystring :: myCref mystring :: operator [](int i)" << endl;
	mycheck(i);
	return myCref(*this, i);
}

inline char mystring :: operator [](int i) const {
	cout << "������ inline char mystring :: operator [](int i) const" << endl;
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
	cout << "������ mystring::mystring(const mystring& x)" << endl;
	x.rep->n++;
	rep = x.rep;
}

mystring::~mystring()
{
	if (--rep->n == 0)
		delete rep;
}

//Ū����������ط�ΪʲôҪ����д
mystring& mystring::operator =(const mystring& x)
{
	cout << "������ mystring& mystring::operator =(const mystring& x)" << endl;
	x.rep->n++;//���ˣ�̫���ˣ�������s = sʱ��x.rep��rep��ͬһ��������n++�Լ�--n�պõ��������ò�������
	if (--rep->n == 0)
		delete rep;
	rep = x.rep;
	return *this;
}

mystring::mystring(const char* s)
{
	cout << "������ mystring::mystring(const char* s)" << endl;
	rep = new mySrep(strlen(s), s);
}

//������ʲôʱ�����ü�����1��ʲôʱ�����ü�����1��Ϊʲô�ӣ�Ϊʲô����
//�������ַ���x,���ڶ��mystring ����������������һ��ѡ��=(const char* s)�ķ�ʽ�����Ż�ʱ
//����֮ǰ������ַ��������õĴ����ͼ�1������Ϊʲô�ӣ��Ǿͼ��ˣ������µ�mystring������
//�ַ���x��ʱ���������ü����ͼ�1
mystring& mystring::operator =(const char* s)
{
	cout << "������ mystring& mystring::operator =(const char* s)" << endl;
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

