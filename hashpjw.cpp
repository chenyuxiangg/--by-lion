#include <iostream>
using namespace std;

const int PRIME = 211;
const int EOS = '\0';
int hashpjw(const char* s);

int main(int args,char* argv[]){
	int x = hashpjw("asdhfkglhl;cmvb,xzwertyuqiop[]");
	cout << x << endl;
	
	return 0;
} 

int hashpjw(const char* s){
	const char* p = s;
	size_t h = 0;
	size_t g = 0;
	
	for(p;*p != EOS;++p){
		h = (h << 4)+(*p);
		if(g = h&0xf0000000)
		{
			h = h^(g>>24);
			h = h^g;
		}
	}
	return h%PRIME;
}
