#pragma once
//ͷ�ļ��о�������ţ�
/*
���ݶ���
���溯������
�ۼ�������
�������ֿռ�
������ģ�嶨��
*/
#include <cstring>
#include <string>
#include <map>
using namespace std;

//ö��
enum FLAG {
	NAME, NUMBER, END, MERROR,
	ADD = '+', MUN = '-', MULTI = '*', DEV = '/',
	PRINT = ';', EQUL = '=', MLP = '(', MRP = ')',
};

//ȫ�ֺ���
double Gexpr(bool bget);
double Gterm(bool bget);
double Gprim(bool bget);
FLAG Ggetvalue(char* &pch);