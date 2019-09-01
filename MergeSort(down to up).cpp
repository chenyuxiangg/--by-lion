/*
归并排序，自底向上 
*/
#include <iostream>
using namespace std;
void display(int* arr,int size){
	for(int i = 0;i < size;++i){
		cout << arr[i] << " ";
	}
	cout << endl;
} 

void Merge(int* a,int low,int mid,int high){
	int i = low,j = mid+1;
	int* tmp = new int[high-low+1];
	int k = 0;
	while(i <= mid && j <= high){
		if(a[i] < a[j]){
			tmp[k++] = a[i++];
		}
		else{
			tmp[k++] = a[j++];
		}
	}
	
	while(i <= mid){
		tmp[k++] = a[i++];
	}
	
	while(j <= high){
		tmp[k++] = a[j++];
	}
	k = 0;
	for(int id = low;id <= high;++id){
		a[id] = tmp[k++];
	}
	delete[] tmp;
}

void MergePass(int* a,int length,int n){
	int i;
	for(i = 0;i + 2*length-1 < n;i = i+2*length){
		Merge(a,i,i+length-1,i+2*length-1);
	}
	if(i + length -1 < n){
		Merge(a,i,i+length-1,n-1);
	}
}

void MergeSort(int* a,int n){
	for(int len = 1;len < n;len = len*2){
		MergePass(a,len,n);
	}
}

int main(int argc,char* argv[]){
	int n;
	int* arr;
	cout << "please input n:";
	cin >> n;
	arr = new int[n];
	cout << "please input " << n << "nums:";
	for(int i = 0;i < n;++i){
		cin >> arr[i];
	}
	MergeSort(arr,n);
	display(arr,n);
	return 0;
}
