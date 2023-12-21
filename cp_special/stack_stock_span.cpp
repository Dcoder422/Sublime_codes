#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<pair<int,int>> v;
	int x;
	for(int i=0;i<n;i++){cin >> x;v.push_back({x,1});}
	stack<int> st;
	for(int i=0;i<n;i++){
		if(st.empty()){st.push(i);continue;}
		else {
			while(!st.empty() && v[st.top()].first<v[i].first){v[i].second+=v[st.top()].second;st.pop();}
			st.push(i);
		}
	}	
	for(int i=0;i<n;i++)cout<<v[i].second<< " ";
}