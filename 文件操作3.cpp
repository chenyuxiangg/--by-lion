#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct info{
	string id;
	double hour_mony;
	int hour_of_week;
};

int main(int argc,char* argv[])
{
	ifstream infile("./info.txt",ios::in);
	double all_mony = 0.0;
	int count = 0;
	string str;
	if(!infile.is_open())
	{
		cout << "文件打开失败！" << endl;
		return 0;
	}
	else{
		while(!infile.eof())
		{
			count++;
			getline(infile,str);
			istringstream s(str);
			info someone;
			s >> someone.id >> someone.hour_mony >> someone.hour_of_week;
			if(someone.hour_of_week > 40)
			{
				someone.hour_mony *= 1.5;
			}
			double all = someone.hour_of_week * someone.hour_mony;
			all_mony += all;
			cout << "工号：" << someone.id << "  总工资：" << all << endl;
		}
		cout << "所有员工的工资为：" << all_mony << "," << "平均工资为：" << all_mony/count << endl;
		
	}
	infile.close();
	return 0;
 } 
