//https://www.hackerearth.com/problem/algorithm/ordered-triplets/
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const int M= 1e9+7;
int v[N];
int main(){
    int n,a;
    cin >> n;
    for(int i =0;i<n;i++)
    {   cin >> a;
        v[a]++;
    }
    int ci,cj,ck1,ck2,k1,k2;
    long long sum=0;
    for(int i=1;i<N;i++){
    	if(v[i]==0) continue;// v.v. imp here
    	for(int j=1;j<N;j++){
    		if(v[j]==0) continue;
    		ci =v[i];

    		if(j==i)
    			cj=v[i]-1;
    		else cj=v[j];

    		k1 = i;
    		k2 = j-(i-j);
    		
    		
    			if((i!=j))
    			ck1=v[k1]-1;
    			else ck1=v[k1]-2;

    		if((k2==i||k2==j)){
    			if((i!=j))
    			ck2=v[k2]-1;
    			else ck2=0;
    		}
    		else if(k2>0 && k2<=1e3) ck2 = v[k2];
    		else ck2=0;
    		sum= (sum%M+(1LL*ci*cj*(ck1+ck2))%M)%M;// 1LL v.imp optherwise it may goto -ve side of int(i.e. exceed limit of int)
    		// cout << sum << endl;
    	}
    }
    cout << sum%M ;
}