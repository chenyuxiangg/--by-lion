#pragma once
class Myqeueu
{
public:
	Myqeueu(int capcity);//���캯��������һ������������
	~Myqeueu();          //��������
	void getmylength();  //��ȡ���ȵĺ���
	void clear();        //��պ���
	bool qeueuempty();   //�пպ���
	bool qeueufull();    //��������
	bool Delete(int& element);       //�˶Ӻ���
	bool input(int element);        //��Ӻ���
	void traverse();     //��������
private:
	int Mycapcity;       //��������
	int Mylength;        //�������г���
	int * myqeueu;       //����ָ��
	int qhead;           //����ͷ
	int qtail;           //����β
};