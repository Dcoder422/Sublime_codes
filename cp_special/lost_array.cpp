// this solution is not accepted
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        int a[n-1];
        int c=0,min_in=0;
        for(int i =0;i<n-1;i++){
            cin >> a[i];
            if(a[i]==1){
                c++;
            }
            if(a[i]==2){
                c--;
            }
            if(c<0){
                min_in=i+1;
                c=0;
            }
        }
        // cout << "min_index" << min_in << endl;
       arr[min_in]=1;
       for(int i=min_in;i<n-1;i++){
        if(a[i]==0)
            arr[i+1]=arr[i];
       if(a[i]==1)
        arr[i+1]=arr[i]+1;
        if(a[i]==2)
            arr[i+1]=arr[i]-1;
    }  
        for(int i=min_in;i>0;i--){
        if(a[i-1]==0)
            arr[i-1]=arr[i];
       if(a[i-1]==1)
        arr[i-1]=arr[i]-1;
        if(a[i-1]==2)
            arr[i-1]=arr[i]+1;
    }  
    for(int i=0;i<n ; i++)
    cout << arr[i]  <<" "; 
    cout << endl;
 }
}