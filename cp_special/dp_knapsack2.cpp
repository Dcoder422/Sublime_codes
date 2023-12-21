#include <bits/stdc++.h>
using namespace std;

const int N=105;
long long dp[N][100005],w[N],v[N];

long long knap(int i,int va){
	if(va==0) return 0;
	if(i<0)return 1e15;
	if(dp[i][va]!=-1) return dp[i][va];
	long long ans=0;
	ans = knap(i-1,va);
	if(va-v[i]>=0)
	ans=min(ans,knap(i-1,va-v[i])+w[i]+0LL);
	return dp[i][va]=ans;
}

int main(){
	memset(dp,-1,sizeof(dp));
	int n,wt;
	cin >> n >> wt;
	for(int i=0;i<n;i++){
		cin >> w[i] >> v[i];
	}
	int i;
	for(i=1e5+1;i>=0;i--){
		if(wt>=knap(n-1,i))
			break;
	}
	cout << (i!=-1?i:0);

}