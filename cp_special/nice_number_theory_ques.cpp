//https://www.codechef.com/problems/CHMOD?tab=statement

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
vector<int> v[N];
int arr[N][101];
int hp[N];
int binE(int a,int b,int m){
	int ans =1;
	while(b){
		if(b&1)ans=(ans*1LL*a)%m;
		a=(a*1LL*a)%m;
		b>>=1;
	}
	return ans;
}
int main(){
	for(int i=2;i<N;i++){
		if(hp[i]==0){
		for(int j=i;j<N;j+=i){
			hp[j]=i;
		}
	}
	}
	int n;cin >> n;
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		while(x>1){
			if(x%hp[x]==0){
				arr[i][hp[x]]++;
				x/=hp[x];
			}
		}
	}
	for(int j=0;j<101;j++)
	{
		for(int i=1;i<N;i++){
			arr[i][j]+=arr[i-1][j];
		}
	}
	// for(int i=1;i<=n;i++){
	// 	for(int j=2;j<7;j++){
	// 		cout << arr[i][j] << " ";
	// 	}cout << endl;
	// }
    int t;
    cin >> t;
    while(t--){
         int l,r,m;
         cin >> l >> r >> m;
         long long ans=1;
         for(int i=2;i<101;i++){
         	// cout << i << " " << (arr[r][i]-arr[l-1][i]) << endl;
         	ans=(ans*binE(i,(arr[r][i]-arr[l-1][i]),m))%m;
         }
         cout << ans << endl;
    }   
 }
