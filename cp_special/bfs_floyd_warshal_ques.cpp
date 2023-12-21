#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n ;
	int d[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n ;j++){
			cin >> d[i][j];
		}
	}
	vector<int> vo(n);
	for(int i=0;i<n;i++){
		cin >> vo[i];
		vo[i]--;
	}
	reverse(vo.begin(),vo.end());
	vector<long long> ans;
	for(int k=0;k<n ;k++){
		int v=vo[k];
		for(int i=0;i<n;i++){
			for(int j=0;j<n ;j++){
				d[i][j]=min(d[i][j],(d[i][v]+d[v][j]));
			}
		}
		long long sum=0;
		for(int i=0;i<=k;i++){
			for(int j=0;j<=k;j++){
				sum+=d[vo[i]][vo[j]];
			}
		}
		ans.push_back(sum);
	}
	reverse(ans.begin(),ans.end());
	for(auto i : ans)cout << i << " ";
}