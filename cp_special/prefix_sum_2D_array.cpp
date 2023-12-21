

//prefix sum in 2D Array
//find sum of no.s in rectangle (a,b) and (c,d)
// N<=10^3
// Q<=10^5
//a[i][j]<=10^9
// a,b,c,d <=N
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
long long arr[N][N];
int main(){
    	int n;
    	cin >> n;
    	for(int i=1;i<n+1;i++){
			   for(int j=1;j<n+1 ;j++){
			   		cin >> arr[i][j];
			   		arr[i][j]+=arr[i][j-1]+arr[i-1][j]-arr[i-1][j-1];
			   		cout << arr[i][j] << " ";
			   		}
			cout << endl;   				
    	}
    	int q;
    	cin  >> q;
    	while(q--){
    		int a,b,c,d;
    		cin >> a >> b >> c >> d;
    		cout << arr[c][d]-arr[a-1][d]-arr[c][b-1]+arr[a-1][b-1];

    	}
 }

			
