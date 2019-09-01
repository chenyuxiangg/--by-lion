#include <iostream>
#include <vector>
using namespace std;

#define N 30
int count = 0;

typedef struct UnitObj{
	int name;
	int start;
}Obj;

typedef struct Schedule_Unit{
	int time;
	vector<Obj> arr;
}Sch;

bool handle(vector<Obj>& objarr,vector<Sch>& res,const int& day); 
void myprint(const vector<Sch>& res);

int main(int argc,char* argv[]){
	int day = 0;
	vector<Sch> result;
	vector<Obj> objarr;
	bool flag = true;
	while(flag){
		day++;
		flag = handle(objarr,result,day);
	}
	myprint(result);
	return 0;
}

bool handle(vector<Obj>& objarr,vector<Sch>& res,const int& day){
	if(objarr.empty()){
		int name = ++count;
		Obj obj;
		obj.name = name;
		obj.start = day;
		objarr.push_back(obj);
		Sch sch;
		sch.time = day;
		sch.arr.push_back(obj);
		return true;
	}
	int n = objarr.size();
	int sch_count = 0;
	int i;
	Sch sch;
	sch.time = day;
	for(i = 0;i < n || sch_count < 2;++i){
		int d = day - objarr[i].start;
		switch(d){
			case 1:case 2:case 4:case 7:case 15:{
				sch.arr.push_back(objarr[i]);
				sch_count++;
				if(d == 15){
					objarr.erase(objarr.begin()+i);
				}
				break;
			default:
				break;
			}
		}
	}
	if(i < 2){
		Obj obj;
		count++;
		if(count <= N){
			obj.name = count;
			obj.start = day;
			objarr.push_back(obj);
			sch.arr.push_back(obj);
		}
	}
	res.push_back(sch);
	if(objarr.empty())
		return false;
	return true;
}

void myprint(const vector<Sch>& res){
	cout << "时间" << "--------" << "计划" << endl;
	int n = res.size();
	for(int i = 0;i < n;++i){
		cout << res[i].time << "        ";
		int j = res[i].arr.size();
		for(int k = 0;k < j;++k){
			cout << res[i].arr[k].name << " ";
		} 
		cout << endl;
	}
}
