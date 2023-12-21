//https://www.spoj.com/problems/EKO/

#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
vector<int> v(N);
bool wood(int h,int n,int m){
	long long sum=0;
	for(int i=0;i<n;i++){
		if(v[i]>h)sum+=v[i]-h;
	}
	return sum>=m;
}
int main(){
    int n , m ; cin >> n >> m ;
    
    for(int i=0;i<n ;i++){
       	cin >> v[i];
       }   
       int lo=0,hi=1e9,mid;
       while(hi-lo>1){
       	mid=(lo+hi)/2;
       	if(wood(mid,n,m))lo=mid;
       	else hi=mid-1;
       }
       cout << ((wood(hi,n,m))?hi : lo )<<endl;
 }
