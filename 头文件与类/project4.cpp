// project4.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"  //ֻ��VC���ܱ���
#include "iostream"
#include "A.h"

int _tmain(int argc,_TCHAR* argv[])
{
	A a;    //������  int a������һ�����α���һ����ֻ��int ����û����A���Ƶĳ�Ա����������int ��a�Ͳ��ܵ���
	a.Print();
    return 0;
}

/*
ͷ�ļ�  A�Ķ���
#pragma once
//#include "iostream"
//using namespace std;  //���ڴ˴����������У����ڱ���project4.cppʱ����Ҫ��д����ռ�
class A
{
public:
void Print()  //��������Ա����
{
cout << "���ǻ�ӭ������" << endl; //�˴�����ȱ��  <iostream> ���Լ� ����ռ�std
//������ֱ��ʹ�ô�ͷ�ļ�ʱ����ֱ������
}
};


�ܽᣬ��һ��ͷ�ļ�������һ����������ռ䣬��ֻҪ�õ���ͷ�ļ��ĳ����ж���������д��ͬ������ռ�
*/

