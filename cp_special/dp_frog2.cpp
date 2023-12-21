#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> h(N);
int dp[N];
int k;
int jump(int n){
	if(n==1)return 0;
	if(dp[n]!=-1)return dp[n];
	int ans=INT_MAX ;
	for(int i=1;i<=k ;i++){
		if(n-i>0)
	ans = min(ans,jump(n-i)+abs(h[n-i]-h[n]));
	}
	
	return dp[n]=ans;
}
// O(n*k)
int main(){
	memset(dp,-1,sizeof(dp));
	int n;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}
	cout << jump(n) ;
}