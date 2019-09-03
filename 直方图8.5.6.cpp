#include <iostream>
#include <stddef.h> 
#include <memory.h>
using namespace std;

class CHistogram{
	public:
		CHistogram(ptrdiff_t min,size_t g,size_t num);//num代表区间个数
		~CHistogram(){delete[] parr;}
		void record(ptrdiff_t value);
		void Output();
		
	private:
		ptrdiff_t minvalue;
		ptrdiff_t maxvalue;
		size_t gap;
		size_t low_num;
		size_t high_num;
		size_t* parr;
}; 

CHistogram :: CHistogram(ptrdiff_t min,size_t g,size_t num): minvalue(min),maxvalue(min+num*g),gap(g){
	low_num = 0;
	high_num = 0;
	parr = new size_t[num];
	memset(parr,0,num*sizeof(size_t));
}

void CHistogram :: record(ptrdiff_t value)
{
	if(value < minvalue)
	{
		++low_num;
		return;
	}
	else if(value > maxvalue)
	{
		++high_num;
		return;
	}
	else
	{
		++parr[(value-minvalue)/gap];
		return;
	}
}

void CHistogram :: Output()
{
	cout << "lownum:" << low_num << " highnum:" << high_num << endl;
	cout << "between " << minvalue << " and " << maxvalue << "have:" << endl;
	for(ptrdiff_t i = minvalue;i < maxvalue;i += gap)
	{
		cout << "[" << i << "," << i+gap-1 << "]:" << parr[(i-minvalue)/gap] << endl;
	}
}

int main(int argc,char* argv[])
{
	CHistogram histogram(-1,2,9);
	int icount;
	cin >> icount;
	for(int i = 0;i < icount;++i)
	{
		int ui;
		cin >> ui;
		histogram.record(ui);
	}
	histogram.Output();
	
	return 0;
}

