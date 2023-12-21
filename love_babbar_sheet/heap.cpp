#include <bits/stdc++.h>
using namespace std;


class heap(){
	int arr[100];
	int size =0;

	void insert(int val){
		
		size++;
		int in = size;
		arr[in]=val;
		
		while(in>1){
			if(arr[in/2]<arr[in]){
				swap(arr[in/2],arr[in]);
				in = in/2;
			}
			else return;
		}
	}

	void dele(){
		if(size==0)return;

		arr[1]=arr[size];
		size--;
		int in = 1;
		while(in<size){
			if(2*in<=size && arr[in]<arr[2*in] && arr[2*in]>arr[2*in+1]){
				swap(arr[2*in],arr[in]);
				in = 2*in;
			}
			else if((2*in+1)<=size && arr[in]<arr[2*in+1] && arr[2*in+1]>arr[2*in]){
				swap(arr[2*in+1],arr[in]);
				in = 2*in+1;
			}
			else return;
		}
	}

	//take the index as root and make its tree a heap
	void heapify(int i){
		int in = i;
		while(in<size){
			if(2*in<=size && arr[in]<arr[2*in] && arr[2*in]>arr[2*in+1]){
				swap(arr[2*in],arr[in]);
				in = 2*in;
			}
			else if((2*in+1)<=size && arr[in]<arr[2*in+1] && arr[2*in+1]>arr[2*in]){
				swap(arr[2*in+1],arr[in]);
				in = 2*in+1;
			}
			else return;
		}
	}

}
int main(){

}