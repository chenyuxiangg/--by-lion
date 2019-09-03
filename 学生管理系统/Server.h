#ifndef SERVER_H
#define SERVER_H
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "StrCompare.h"
#include "Stack.h"
using namespace std;

ifstream inSch;
ofstream outSch;
int i_Sch = 0;
const int Student_num = 100;
const int Class_num = 100;
const int Id_num = 20;
const int Schstu = 20000;
enum Sex { man, wowan };
struct Subject
{
	float SJ;
	float LS;
	float DL;
	float GL;
	float YY;
};
struct Student
{
	unsigned long long Id;
	char name[20];
	Sex sex;
	int age;
	unsigned long long Tel;
	struct Subject sub;
};

struct Class
{
	struct Student student[Student_num];
	char Class_Id[Id_num];
	int Student_len;
};


//bool QuicksortID(struct Student* iarr, int i_n, int low, int hight);
bool QuicksortSJ(struct Student* iarr, int i_n, int low, int hight);
bool QuicksortLS(struct Student* iarr, int i_n, int low, int hight);
bool QuicksortGL(struct Student* iarr, int i_n, int low, int hight);
bool QuicksortYY(struct Student* iarr, int i_n, int low, int hight);
bool QuicksortDL(struct Student* iarr, int i_n, int low, int hight);
//bool Quicksortage(struct Student* iarr, int i_n, int low, int hight);

bool QuicksortDL(struct Student* iarr, int i_n, int low, int hight)
{
	int origin = low;
	struct Student temp;
	if (low > hight)//这一步的存在，确保下一步while中不需要low >= 0 && hight < i_n
		return true;
	while (low != hight)
	{
		while (low < hight && iarr[hight].sub.DL >= iarr[origin].sub.DL)//这一步必须在while (low < hight && iarr[low] <= iarr[origin])
																		  //                  low++；之前
			hight--;
		while (low < hight && iarr[low].sub.DL <= iarr[origin].sub.DL)
			low++;
		temp = iarr[hight];
		iarr[hight] = iarr[low];
		iarr[low] = temp;
	}
	temp = iarr[origin];
	iarr[origin] = iarr[low];
	iarr[low] = temp;
	low = origin;

	QuicksortDL(iarr, i_n, low, hight - 1);
	QuicksortDL(iarr, i_n, hight + 1, i_n - 1);

	return true;
}


bool QuicksortYY(struct Student* iarr, int i_n, int low, int hight)
{
	int origin = low;
	struct Student temp;
	if (low > hight)//这一步的存在，确保下一步while中不需要low >= 0 && hight < i_n
		return true;
	while (low != hight)
	{
		while (low < hight && iarr[hight].sub.YY >= iarr[origin].sub.YY)//这一步必须在while (low < hight && iarr[low] <= iarr[origin])
																		  //                  low++；之前
			hight--;
		while (low < hight && iarr[low].sub.YY <= iarr[origin].sub.YY)
			low++;
		temp = iarr[hight];
		iarr[hight] = iarr[low];
		iarr[low] = temp;
	}
	temp = iarr[origin];
	iarr[origin] = iarr[low];
	iarr[low] = temp;
	low = origin;

	QuicksortYY(iarr, i_n, low, hight - 1);
	QuicksortYY(iarr, i_n, hight + 1, i_n - 1);

	return true;
}


bool QuicksortGL(struct Student* iarr, int i_n, int low, int hight)
{
	int origin = low;
	struct Student temp;
	if (low > hight)//这一步的存在，确保下一步while中不需要low >= 0 && hight < i_n
		return true;
	while (low != hight)
	{
		while (low < hight && iarr[hight].sub.GL >= iarr[origin].sub.GL)//这一步必须在while (low < hight && iarr[low] <= iarr[origin])
																		  //                  low++；之前
			hight--;
		while (low < hight && iarr[low].sub.GL <= iarr[origin].sub.GL)
			low++;
		temp = iarr[hight];
		iarr[hight] = iarr[low];
		iarr[low] = temp;
	}
	temp = iarr[origin];
	iarr[origin] = iarr[low];
	iarr[low] = temp;
	low = origin;

	QuicksortGL(iarr, i_n, low, hight - 1);
	QuicksortGL(iarr, i_n, hight + 1, i_n - 1);

	return true;
}


bool QuicksortLS(struct Student* iarr, int i_n, int low, int hight)
{
	int origin = low;
	struct Student temp;
	if (low > hight)//这一步的存在，确保下一步while中不需要low >= 0 && hight < i_n
		return true;
	while (low != hight)
	{
		while (low < hight && iarr[hight].sub.LS >= iarr[origin].sub.LS)//这一步必须在while (low < hight && iarr[low] <= iarr[origin])
																		  //                  low++；之前
			hight--;
		while (low < hight && iarr[low].sub.LS <= iarr[origin].sub.LS)
			low++;
		temp = iarr[hight];
		iarr[hight] = iarr[low];
		iarr[low] = temp;
	}
	temp = iarr[origin];
	iarr[origin] = iarr[low];
	iarr[low] = temp;
	low = origin;

	QuicksortLS(iarr, i_n, low, hight - 1);
	QuicksortLS(iarr, i_n, hight + 1, i_n - 1);

	return true;
}


bool QuicksortSJ(struct Student* iarr, int i_n, int low, int hight)
{
	int origin = low;
	struct Student temp;
	if (low > hight)//这一步的存在，确保下一步while中不需要low >= 0 && hight < i_n
		return true;
	while (low != hight)
	{
		while (low < hight && iarr[hight].sub.SJ >= iarr[origin].sub.SJ)//这一步必须在while (low < hight && iarr[low] <= iarr[origin])
																  //                  low++；之前
			hight--;
		while (low < hight && iarr[low].sub.SJ <= iarr[origin].sub.SJ)
			low++;
		temp = iarr[hight];
		iarr[hight] = iarr[low];
		iarr[low] = temp;
	}
	temp = iarr[origin];
	iarr[origin] = iarr[low];
	iarr[low] = temp;
	low = origin;

	QuicksortSJ(iarr, i_n, low, hight - 1);
	QuicksortSJ(iarr, i_n, hight + 1, i_n - 1);

	return true;
}

//bool Quicksortage(struct Student* iarr, int i_n, int low, int hight)
//{
//	int origin = low;
//	struct Student temp;
//	if (low > hight)//这一步的存在，确保下一步while中不需要low >= 0 && hight < i_n
//		return true;
//	while (low != hight)
//	{
//		while (low < hight && iarr[hight].age >= iarr[origin].age)//这一步必须在while (low < hight && iarr[low] <= iarr[origin])
//																//                  low++；之前
//			hight--;
//		while (low < hight && iarr[low].age <= iarr[origin].age)
//			low++;
//		temp = iarr[hight];
//		iarr[hight] = iarr[low];
//		iarr[low] = temp;
//	}
//	temp = iarr[origin];
//	iarr[origin] = iarr[low];
//	iarr[low] = temp;
//	low = origin;
//
//	Quicksortage(iarr, i_n, low, hight - 1);
//	Quicksortage(iarr, i_n, hight + 1, i_n - 1);
//
//	return true;
//}
//
//bool QuicksortID(struct Student* iarr, int i_n, int low, int hight)
//{
//	int origin = low;
//	struct Student temp;
//	if (low > hight)//这一步的存在，确保下一步while中不需要low >= 0 && hight < i_n
//		return true;
//	while (low != hight)
//	{
//		while (low < hight && iarr[hight].Id >= iarr[origin].Id)//这一步必须在while (low < hight && iarr[low] <= iarr[origin])
//														  //                  low++；之前
//			hight--;
//		while (low < hight && iarr[low].Id <= iarr[origin].Id)
//			low++;
//		temp = iarr[hight];
//		iarr[hight] = iarr[low];
//		iarr[low] = temp;
//	}
//	temp = iarr[origin];
//	iarr[origin] = iarr[low];
//	iarr[low] = temp;
//	low = origin;
//
//	QuicksortID(iarr, i_n, low, hight - 1);
//	QuicksortID(iarr, i_n, hight + 1, i_n - 1);
//
//	return true;
//}


















#endif