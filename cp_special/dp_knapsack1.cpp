#include <bits/stdc++.h>
using namespace std;

const int N=105;
long long dp[N][100005],w[N],v[N];

long long knap(int i,int wt){
	if(wt==0) return 0;
	if(i<0)return 0;
	if(dp[i][wt]!=-1) return dp[i][wt];
	long long ans=0;
	ans = knap(i-1,wt);
	if(wt-w[i]>=0)
	ans=max(ans,knap(i-1,wt-w[i])+v[i]+0LL);
	return dp[i][wt]=ans;
}

int main(){
	memset(dp,-1,sizeof(dp));
	int n,wt;
	cin >> n >> wt;
	for(int i=0;i<n;i++){
		cin >> w[i] >> v[i];
	}
	cout << knap(n-1,wt);
}