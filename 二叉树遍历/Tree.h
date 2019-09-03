#pragma once
#include <iostream>
#include <conio.h>
using namespace std;

class Tree;
class Coordinate
{
public:
	friend class Tree;
	Coordinate(int D = 0,int flag = 0,int num = 1);
	~Coordinate(){}
	friend bool Pretransform(Coordinate* coor);
	friend bool Posttransform(Coordinate* coor);
	friend bool Intransform(Coordinate* coor);
	friend bool SetleftC(Coordinate* coo,int num,Coordinate* coor);
	friend bool SetrightC(Coordinate* coo,int num,Coordinate* coor);
	bool Setnum(int n);
	Coordinate* Getleft();
	Coordinate* Getright();
	int Getdate();
	bool Is_Left(int Flag);
	int Getnum();
	friend bool Clear(Coordinate* coor);
	friend Coordinate* serch(Coordinate* coor, int i_n);

private:
	Coordinate* Lp;
	Coordinate* Rp;
	int date;
	int mark;
	int i_num;
};

bool Coordinate :: Setnum(int n)
{
	i_num = n;
	return true;
}

Coordinate ::Coordinate(int D, int flag, int num)
{
	Lp = NULL;
	Rp = NULL;
	i_num = num;
	mark = flag;
	date = D;
}

bool Clear(Coordinate* coor)
{
	if (coor == NULL)
	{
		cout << "您删除的元素不存在..." << endl;
		return false;
	}

	if(coor->Getleft() == NULL && coor->Getright() == NULL)
	{
		delete coor;
		coor = NULL;
		return true;
	}
	if(coor->Getleft() != NULL)
	{
		Clear(coor->Getleft());
	}
	if(coor->Getright() != NULL)
	{
		Clear(coor->Getright());
	}
	return true;
}

int Coordinate :: Getdate()
{
	return date;
}

Coordinate* Coordinate :: Getleft()
{
	return Lp;
}

Coordinate* Coordinate::Getright()
{
	return Rp;
}

int Coordinate :: Getnum()
{
	return i_num;
}

Coordinate* serch(Coordinate* coor, int i_n)
{
	Coordinate* l_p = coor;
	Coordinate* r_p = coor;
	while ((l_p->Getleft() || r_p->Getright()) && (l_p->Getnum() != i_n && r_p->Getnum() != i_n))
	{
		if (l_p->Getleft() != NULL)
		{
			l_p = l_p->Getleft();
		}
		if (r_p->Getright() != NULL)
		{
			r_p = r_p->Getright();
		}
	}

	if(l_p->Getnum() == i_n)
	{
		return  l_p;
	}
	else if (r_p->Getnum() == i_n)
	{
		return r_p;
	}
	else
	{
		cout << "您选择的父结点不存在，请核查..." << endl;
		_getch();
		return NULL;
	}
}

bool Coordinate::Is_Left(int Flag)
{
	if (Flag != 0 || Flag != 1)
	{
		cout << "请输入（0 or 1）..." << endl;
		return false;
	}
	else if (Flag == 0)
		return true;
	else
		return false;

}

bool SetrightC(Coordinate* coo,int num,Coordinate* coor)
{
	coor->Setnum(2 * num + 1);
	Coordinate* temp = serch(coo, num);
	if (temp == NULL)
	{
		delete coor;
		coor = NULL;
		return false;
	}
	if (temp->Rp == NULL)
	{
		temp->Rp = coor;
		return true;
	}
	cout << "您插入的位置已存在元素，插入失败..." << endl;
	delete coor;
	coor = NULL;
	_getch();
	return false;
}

bool SetleftC(Coordinate* coo,int num,Coordinate* coor)
{
	coor->Setnum(2 * num);
	Coordinate* temp = serch(coo, num);
	if (temp == NULL)
	{
		delete coor;
		coor = NULL;
		return false;
	}
	if (temp->Lp == NULL)
	{
		temp->Lp = coor;
		return true;
	}
	cout << "您插入的位置已存在元素，插入失败..." << endl;
	delete coor;
	coor = NULL;
	_getch();
	return false;
}

//Coordinate* pre = NULL;
//Coordinate* pl = NULL;
//Coordinate* pr = NULL;
bool Pretransform(Coordinate* coor)
{
	if (coor == NULL && coor == NULL)
		return true;
	cout << coor->Getdate() << " ";
	if (coor->Getleft() != NULL)
	{
		Pretransform(coor->Getleft());
	}
	if (coor->Getright() != NULL)
	{
		Pretransform(coor->Getright());
	}
	return true;
}

bool Posttransform(Coordinate* coor)
{
	if (&coor == NULL && &coor == NULL)
	{
		cout << coor->Getdate() << " ";
		return true;
	}
	if (coor->Getleft() != NULL)
	{
		Posttransform(coor->Getleft());
	}
	if (coor->Getright() != NULL)
	{
		Posttransform(coor->Getright());
	}
	cout << coor->Getdate() << " ";
	return true;
}

bool Intransform(Coordinate* coor)
{
	if (&coor == NULL && &coor == NULL)
	{
		cout << coor->Getdate() << " ";
		return true;
	}
	if (coor->Getleft() != NULL)
	{
		Intransform(coor->Getleft());
	}

	cout << coor->Getdate() << " ";

	if (coor->Getright() != NULL)
	{
		Intransform(coor->Getright());
	}
	return true;
}

class Tree
{public:
	Tree(Coordinate* coor);
	Tree();
	~Tree();
	Coordinate* Tserch(int Num);
	void SetCoor(Coordinate* coor);
	bool TsetleftC(int num, Coordinate* coor);
	bool TsetrightC(int num, Coordinate* coor);
	bool Tpretransform();
	bool Tposttransform();
	bool Tintransform();
	Coordinate* GetCoor();

private:
	Coordinate* Coor;
};

void Tree :: SetCoor(Coordinate* coor)
{
	Coor = coor;
}

bool Tree :: Tpretransform()
{
	if (this->GetCoor() == NULL)
	{
		cout << "您访问的树为空" << endl;
		return false;
	}
	return Pretransform(this->GetCoor());
}

bool Tree::Tposttransform()
{
	if (this->GetCoor() == NULL)
	{
		cout << "您访问的树为空" << endl;
		return false;
	}
	return Posttransform(this->GetCoor());
}

bool Tree::Tintransform()
{
	if(this->GetCoor() == NULL)
	{
		cout << "您访问的树为空" << endl;
		return false;
	}
	return Intransform(this->GetCoor());
}

bool Tree :: TsetleftC(int num, Coordinate* coor)
{
	return SetleftC(this->GetCoor(), num, coor);
}

bool Tree::TsetrightC(int num, Coordinate* coor)
{
	return SetrightC(this->GetCoor(), num, coor);
}

Coordinate* Tree :: Tserch(int Num)
{
	return serch(this->GetCoor(), Num);
}

Tree :: Tree(Coordinate* coor)
{
	Coor = coor;
}

Tree :: Tree()
{
	Coor = NULL;
}

Tree :: ~Tree()
{
	Clear(this->GetCoor());
	Coor = NULL;
}

Coordinate* Tree :: GetCoor()
{
	return Coor;
}