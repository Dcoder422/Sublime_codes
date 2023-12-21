//https://www.codechef.com/problems/MINEAT?tab=statement


#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
vector<int> v(N);
bool bana(int mid,int n,int h){
    	for(int i=0;i<n;i++){
    		h-=ceil(v[i]*1.0/mid);
    		if(h<0)break;
    	}
    	return (h>=0);
    }
int main(){
    int t;
    cin >> t;
//fffttttt
    while(t--){
         int n,h;
         cin >> n >> h ;
         
         for(int i=0;i<n;i++){
         	cin >> v[i];
         }
           // cout << bana(2,4,5) ;
         int lo=1,hi=1e9,mid;
         while(hi-lo>1){
         	mid=(hi+lo)/2;
         	// cout<<"mi" << mid << n << h << endl;cout << bana(mid,n,h) << endl;
         	if(bana(mid,n,h))hi=mid;
         	else lo=mid+1;
         	// cout << lo << " " << hi << endl;
         }
     	cout << (bana(lo,n,h)?lo:hi)<< endl;
   // cout << bana(2,4,5) ;
    }   
 }
