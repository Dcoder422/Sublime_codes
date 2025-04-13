if you want to find the lowest x
 satisfying f(x)
:
int l=lowest_possible_value-1,r=highest_possible_value,m;
while(r-l>1)
{
    m=l+(r-l)/2;if(f(m))r=m;else l=m;
}
return r;

and vice versa if you want to find the highest x
 satisfying g(x)
:

int l=lowest_possible_value,r=highest_possible_value+1,m;
while(r-l>1)
{
    m=l+(r-l)/2;if(g(m))l=m;else r=m;
}
return l;



//https://www.spoj.com/problems/EKO/



Nice binary search : N+1 is invalid value(need to be handled in check() 
function), so r will always have a value that is not the answer, 
hence always l will be the answer  
int l = 0, r = n+1;
while(r - l > 1){
   int mid = (l+r)/2;
   if(check(mid))
      l = mid;
   else
      r = mid;
}



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


void solve(){
    ll n,k;in n >> k;
    ll a[n]; inv(a,n);
    ll l=0,h=2,mid; 
    while(1){
       ll su=0;
        For(i,0,n)su+=h/a[i]; 
        if(su>=k)break; 
        else h*=2;
    }
    while(h-l>1){
        mid = (l+h)/2; 
        ll su=0;
        For(i,0,n)su+=mid/a[i];
        if(su>=k)h=mid;
        else l=mid;
    }
    out h e;
}