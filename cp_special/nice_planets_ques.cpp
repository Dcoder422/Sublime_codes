// https://www.codechef.com/problems/ICL1905?tab=statement



#include<bits/stdc++.h>
using namespace std;

// *** no need ***

// int max(int a,int b){
// 	if(a>b)
// 	return a;
// 	return b;
// }

int main(){
long int t;
cin >> t;
while(t--){
	long int n,a;// **** not writing long here was giving runtime error**
	long int ans=0;
	cin >> n >> a;
	vector<long int> c,d;
	for(long int i=0;i<n;i++){
		long int ci,di;
		cin >> ci >>di;
		d.push_back(di);
		c.push_back(a-ci);}//profit
		for(long int i=0;i<n ;i++){
			 long int sum=0,diff=0,dif=0;
			 long int dmax = INT_MIN;
	    	long int dmin = INT_MAX;
			for(long int j=i;j<n;j++){
				sum+=c[j];
				dmax = max(dmax, d[j]);
                dmin = min(dmin, d[j]);
                int gap = (dmax - dmin)*(dmax - dmin);
				// c2.push_back(sum);
				//logic wrong here*****

				// diff=(d[i]-d[j])*(d[i]-d[j]); // this wasnt considerind gap for indeices in between 
				//every right indices was compared to left most indices--> d[i] , not all btw L and R 
				// dif=max(dif,diff);
				ans=max(ans,sum-gap);

			}
		}
		cout << ans << endl;
	}
}

