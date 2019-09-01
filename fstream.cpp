#include <fstream>
#include <iostream>
using namespace std;

int main(int argc,char* argv[])
{
	ifstream in("c.txt");
	char str[50];
	in.getline(str,50);
	cout << str << ",have " << in.gcount() << " characts" << endl;
	in.close();
	return 0;
}
