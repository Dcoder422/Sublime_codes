#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> h(N);
int dp[N];

int jump(int n){
	if(n==1)return 0;
	if(dp[n]!=-1)return dp[n];
	int ans=INT_MAX ;
	if(n-2>0)
	ans = jump(n-2)+ abs(h[n-2]-h[n]);
	if(n-1>0)
	ans = min(ans,jump(n-1)+abs(h[n-1]-h[n]));
	return dp[n]=ans;
}
// O(n)
int main(){
	memset(dp,-1,sizeof(dp));
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}
	cout << jump(n) ;
}