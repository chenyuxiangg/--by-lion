// project4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"  //只在VC中能编译
#include "iostream"
#include "A.h"

int _tmain(int argc,_TCHAR* argv[])
{
	A a;    //类似于  int a；定义一个整形变量一样，只是int 类型没有与A类似的成员函数，所以int 的a就不能调用
	a.Print();
    return 0;
}

/*
头文件  A的定义
#pragma once
//#include "iostream"
//using namespace std;  //若在此处加上这两行，则在编译project4.cpp时不需要再写命令空间
class A
{
public:
void Print()  //类的输出成员函数
{
cout << "我们欢迎您！！" << endl; //此处由于缺少  <iostream> 库以及 命令空间std
//所以在直接使用此头文件时会出现编译错误
}
};


总结，当一个头文件中任意一个包含命令空间，则只要用到此头文件的程序中都不用重新写相同的命令空间
*/

