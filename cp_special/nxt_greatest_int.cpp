// not valid for array containing repeated elements

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n; 
	cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin >> v[i];
	stack<int> st;
	unordered_map<int,int> m;
	for(int i=0;i<n;i++){
		if(st.empty())
			st.push(v[i]);
		else{
			while((!st.empty()) && st.top()<v[i] ){
			m[st.top()]=v[i];
			st.pop();
		}
		st.push(v[i]);
	}
	}
	while(!st.empty()){
		m[st.top()]=-1;
		st.pop();
	}
	for(int i =0;i<n;i++)
		cout << v[i] << " " << m[v[i]] << endl;
}

//or

// int main(){
// 	int n;
// 	cin >> n;
// 	vector<int> v1(n);
// 	unordered_map<int,int> m;
// 	stack<int> s1;
// 	for(int i=0;i<n;i++){
// 		cin >> v1[i];
// 		// s.push(v1[i]);
// 	}
// 	for(int i=0;i<n;i++){
// 		if(i==0)
// 			m[v1[n-1-i]]=-1;
// 		else{
// 			while(!s1.empty() && s1.top()<v1[n-1-i] )
// 				s1.pop();
// 			if(s1.empty())
// 				m[v1[n-1-i]]=-1;
// 			else
// 			m[v1[n-1-i]]=s1.top();
// 		}
// 		s1.push(v1[n-1-i]);
// 		// // s.pop();
// 	}
// 	for(int i=0;i<n;i++){
// 		cout << v1[i] << " "<< m[v1[i]] << endl;
// 	}
//  }
