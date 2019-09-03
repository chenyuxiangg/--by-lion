#pragma once
#include "iostream"
using namespace std;
class A
{
public:
void Print()  //类的输出成员函数
{
	cout << "我们欢迎您！！" << endl; //此处由于缺少  <iostream> 库以及 命令空间std
	                                //所以在直接使用此头文件时会出现编译错误
}
};