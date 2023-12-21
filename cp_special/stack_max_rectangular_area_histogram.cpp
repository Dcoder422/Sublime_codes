#include <bits/stdc++.h>
using namespace std;
int main(){
	int n ;
	cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++)cin >> v[i];
		vector<int> nsf(n,n),nsb(n,-1);
	stack<int> st;
	for(int i=0;i<n;i++){
		if(st.empty()){st.push(i);}
		else{
			while(!st.empty() && v[i]<v[st.top()]){nsf[st.top()]=i;st.pop();}
			st.push(i);
		}
	}
	for(int i=n-1;i>=0;i--){
		if(st.empty()){st.push(i);}
		else{
			while(!st.empty() && v[i]<v[st.top()]){nsb[st.top()]=i;st.pop();}
			st.push(i);
		}
	}
	// for(int i=0;i<n;i++){
	// 	cout << i << " " << nsb[i] << " "<<nsf[i] << endl;
	// }
	int mx=0;
	for(int i=0;i<n;i++){
		// cout << i << " " << nsf[i]-nsb[i]-1 << endl;
		mx=max(mx,v[i]*(nsf[i]-nsb[i]-1));
	}
	cout << mx;
}