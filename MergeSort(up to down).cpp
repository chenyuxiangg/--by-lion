#include <iostream>
using namespace std;

void display(int* arr,int size){
	for(int i = 0;i < size;++i){
		cout << arr[i] << " ";
	}
	cout << endl;
}
/*
low high mid都代表下标 
*/ 
void Merge(int* a,int low,int mid,int high){
	int i = low,j = mid + 1;
	int k = 0;
	int* tmp = new int[high - low + 1];
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
/*
low high都代表下标 
*/ 
void MergeSort(int* a,int low,int high){
	if(low < high){
		int mid = (low+high)/2;
		MergeSort(a,low,mid);
		MergeSort(a,mid+1,high);
		Merge(a,low,mid,high);
	}
}

int main(int argc,char* argv[]){
	int n;
	int* arr;
	cout << "please input n:";
	cin >> n;
	arr = new int[n];
	cout << "please input " << n << " nums:";
	for(int i = 0;i < n;++i){
		cin >> arr[i];
	}
	MergeSort(arr,0,n-1);
	display(arr,n);
	delete[] arr;
	return 0;
}
