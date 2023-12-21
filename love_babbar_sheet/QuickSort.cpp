#include<bits/stdc++.h>
using namespace std;
vector<int> v(100001);
int n;
int split(int st,int en){
    int c1 =0;
    for(int i=st;i<=en;i++){
        if(v[i]<v[st])c1++;
    }
    swap(v[c1+st],v[st]);int j=c1+1;
    for(int i=st;i<c1;i++){
        while(v[i]>v[c1]){
            swap(v[j],v[i]);
            j++;
        }
    }
    // for(int i=st;i<=en;i++)cout << v[i] << " ";
    return c1+st;

} 
void QuickSort(int st , int en){
    if(st>=en)return ;

    int i=split(st,en);
        
    QuickSort(st,i-1);   
    QuickSort(i+1,en);
}
int main(){
    
    cin >> n;
    
    for(int i=0;i<n;i++)cin >> v[i];
    QuickSort(0,n-1);
    for(int i=0;i<n;i++)cout << v[i] << " ";    
 }
// av. -> O(nlogn)
// worst -> O(n^2) when all elements are same