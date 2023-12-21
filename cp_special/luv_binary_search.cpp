// Binary Search is for monotonic function
// predicate function 
// FFFTTTTTT
// TTTTTFFFF
#include<bits/stdc++.h>
using namespace std;
int lower_bound(vector<int> &v,int ele){
    int lo=0,hi=v.size()-1;
    int mid;
    while(hi-lo>1){
        mid=(hi+lo)/2;
        if(v[mid]<ele)lo=mid+1;
        else hi= mid;
    }
    if(v[lo]>=ele)cout<< v[lo];
    else if(v[hi]>=ele)cout << v[hi];
    else cout << -1;
}
// int upper_bound(vector<int> &v,int ele){
//     int lo=0,hi=v.size()-1;
//     int mid;
//     while(hi-lo>1){
//         mid=(hi+lo)/2;
//         if(v[mid]<ele)lo=mid+1;
//         else hi= mid;
//     }
//     if(v[lo]>ele)cout<< v[lo];
//     else if(v[hi]>ele)cout << v[hi];
//     else if(hi!=v.size()-1)cout << v[hi+1];
//     else cout << -1;
// }

//or 

int upper_bound(vector<int> &v,int ele){
    int lo=0,hi=v.size()-1;
    int mid;
    while(hi-lo>1){
        mid=(hi+lo)/2;
        if(v[mid]<=ele)lo=mid+1; //
        else hi= mid;
    }
    if(v[lo]>ele)cout<< v[lo];//
    else if(v[hi]>ele)cout << v[hi];//
    else cout << -1;
}



int main(){
    int n;cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin >> v[i];
    int to_find;
    cin >> to_find;
    lower_bound(v,to_find);
    cout << 98*1.0/130 ;
    // binary search

    // int lo=0,hi=n-1;
    // int mid;
    // while(hi-lo>1){
    // 	mid = (hi+lo)/2;
    // 	if(v[mid]<to_find)
    // 		lo=mid+1;
    // 	else hi = mid;
    // }  if(v[lo]==to_find)cout << lo;
    // else if(v[hi]==to_find)cout << hi;
    // else cout << "not found";
 }
// O(logn)