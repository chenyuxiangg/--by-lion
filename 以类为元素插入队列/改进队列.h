#pragma once
#include "Circle.h"
class Myqeueu
{
public:
	Myqeueu(int capcity);//���캯��������һ������������
	~Myqeueu();          //��������
	void getmylength();  //��ȡ���ȵĺ���
	void clear();        //��պ���
	bool qeueuempty();   //�пպ���
	bool qeueufull();    //��������
	bool Delete(Circle& element);       //�˶Ӻ���
	bool input(Circle element);        //��Ӻ���
	void traverse();     //��������
private:
	int Mycapcity;       //��������
	int Mylength;        //�������г���
	Circle * myqeueu;       //����ָ��
	int qhead;           //����ͷ
	int qtail;           //����β
};