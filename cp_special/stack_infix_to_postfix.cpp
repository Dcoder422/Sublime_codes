#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	map<char,int> m ={{'+',2},{'-',2},{'*',3},{'/',3},{'^',4},{'(',1},{')',-1}};
	stack<char> st;
	for(auto i : s){
		if(m[i]==0)cout << i ;
		else{
			if(st.empty()){st.push(i);}
			else if(i=='(')st.push(i);
			else if(i==')'){
				while(st.top()!='(')
					{cout << st.top();st.pop();}
				st.pop();
			}
			else if(i=='^'){
				while(!st.empty() && m[i]<m[st.top()]){cout<<st.top();st.pop();}
				st.push(i);
			}
			else {
				while(!st.empty() && m[i]<=m[st.top()]){cout<<st.top();st.pop();}
				st.push(i);
			}

		}
	}
	while(!st.empty()){cout << st.top();st.pop();}

}