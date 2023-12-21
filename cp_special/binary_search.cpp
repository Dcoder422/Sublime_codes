#include <bits/stdc++.h>
using namespace std;
int cc(int start,int end,int arr[],int x){
        int a,b;
        if(end==start){
            if(x==arr[end])
            return 1;
            else return 0;
        }
        int mid = (end+start)/2;
        if(x<=arr[mid])
        a = cc(start,mid,arr,x);else a=0;
        if(x>=arr[mid+1])
        b= cc(mid+1,end,arr,x);else b=0;
        return a+b;
            
        }
int count(int arr[], int n, int x) {
        // code here
        
       
        return cc(0,n-1,arr,x);
    }
int main() {
    int arr[]={8,9,10,12,13,14};
    int n=6;
    int x=12;
    cout<< count(arr,n,x);
}