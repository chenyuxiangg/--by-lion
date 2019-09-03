#include <iostream>
#include "Myqeueu.h"
using namespace std;

int main(int argc,char * argv[])
{
	//Myqeueu qeueu(4);
	Myqeueu * qeueu = new Myqeueu(4);
	qeueu->input(10);
	qeueu->input(20);
	qeueu->input(30);
	qeueu->input(40);
	//qeueu.input(50);

	qeueu->getmylength();
	int e = 0;
	qeueu->Delete(e);
	qeueu->getmylength();
	qeueu->traverse();
	cout << endl;
	qeueu->input(90);
	qeueu->traverse();
	qeueu->clear();
	cout << endl;
	qeueu->traverse();

	delete qeueu;
	qeueu = NULL;

	system("pause");
	return 0;
}