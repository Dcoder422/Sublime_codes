#include<bits/stdc++.h>
using namespace std;
// int max(int a,int b){
// 	if(a>b)
// 	return a;
// 	return b;
// }

int main(){
int t;
cin >> t;
while(t--){
	long int n;
	long int a;
	long int ans=0;
	cin >> n >> a;
	int c[n+1],d[n+1],er[n+1];
	for(int i=1;i<n+1;i++){
		// int ci,di;
		cin >> c[i] >>d[i];
			er[i]=a-c[i]+er[i-1];}
		// d.push_back(di);
		// c.push_back(a-ci);}//profit
		for(int i=1;i<n+1 ;i++){
			long  int diff=0,dif=0;
			for(int j=i;j<n+1;j++){
				// sum+=c[j];
				// c2.push_back(sum);
				diff=abs(d[i]-d[j]);
				dif=max(dif,diff);
				ans=max(ans,er[j]-er[i-1]-dif*2);

			}
		}
		cout << ans << endl;
	}
}

