#pragma once
#include "Circle.h"
class Myqeueu
{
public:
	Myqeueu(int capcity);//构造函数，传入一个参数：容量
	~Myqeueu();          //析构函数
	void getmylength();  //获取长度的函数
	void clear();        //清空函数
	bool qeueuempty();   //判空函数
	bool qeueufull();    //判满函数
	bool Delete(Circle& element);       //退队函数
	bool input(Circle element);        //入队函数
	void traverse();     //遍历函数
private:
	int Mycapcity;       //队列容量
	int Mylength;        //队列现有长度
	Circle * myqeueu;       //数组指针
	int qhead;           //队列头
	int qtail;           //队列尾
};