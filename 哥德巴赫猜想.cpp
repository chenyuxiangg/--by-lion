#include<iostream>
using namespace std;
int const MAX_VALUE=100010;
bool isPrime[MAX_VALUE];
void filtratePrime(int n){
	for(int i=0;i<=n;i++){
		isPrime[i]=true;
	}
	isPrime[1]=false;
	isPrime[2]=true;
	for(int i=2;i<=n;i++){
		if(isPrime[i]){
			for(int j=2*i;j<=n;j+=i){
				isPrime[j]=false;
			}
		}
	}
}
int main(){
	int M;
	cin>>M;
	filtratePrime(M);
	int A;
	int B;
	for(int i=2;i<=M/2;i++){
		if(isPrime[i]){
			if(isPrime[M-i]){
				A=i;
				B=M-i;
			}
		}
	}
	cout<<A<<' '<<B<<endl;
	return 0;
}

