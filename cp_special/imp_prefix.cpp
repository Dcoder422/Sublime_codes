//https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbGRxcFhtMWtRSV9GU1BBWHRmemVKRTR2UE9jd3xBQ3Jtc0ttTmxpbHh3TFprYW9UVW93YTFDbkY2bTZsdnlKa2RfVy0xNlBFRDRSbGZ1cHllcWF0YkdubW51QV9NSGFQQ1ZSWERhSlBwek01OWI0Y2lkakJYT25hMEFUaE5BeGZCWURqMW9yVG1Bamptb2pTb0RiOA&q=https%3A%2F%2Fwww.codechef.com%2Fproblems%2FGCDQ&v=e3qhRh4UOug


#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
    	int n,q;
    	cin >> n >> q;
    	int arr[n+1],a_f[n+1],a_b[n+2];
    	a_f[0]=a_b[n+1]=0;
    	for(int i=1;i<n+1;i++){
    		cin >> arr[i];
    		a_f[i]=__gcd(arr[i],a_f[i-1]);
    	}
    	for(int i=n;i>0;i--)
    		a_b[i]=__gcd(arr[i],a_b[i+1]);
    	while(q--){
    		int l,r;
    		cin >> l >> r;
    		cout << __gcd(a_f[l-1],a_b[r+1]) << endl;
    	}
    }
    
}