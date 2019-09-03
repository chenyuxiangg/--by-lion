#pragma once
//头文件中绝不允许放：
/*
数据定义
常规函数定义
聚集量定义
无名名字空间
导出的模板定义
*/
#include <cstring>
#include <string>
#include <map>
using namespace std;

//枚举
enum FLAG {
	NAME, NUMBER, END, MERROR,
	ADD = '+', MUN = '-', MULTI = '*', DEV = '/',
	PRINT = ';', EQUL = '=', MLP = '(', MRP = ')',
};

//全局函数
double Gexpr(bool bget);
double Gterm(bool bget);
double Gprim(bool bget);
FLAG Ggetvalue(char* &pch);