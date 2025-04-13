#include<bits/stdc++.h>
using namespace std;
string isBalanced(string s) {
	unordered_map<char,int> m;
	m={{'[',1},{')',-3},{'(',3},{'{',2},{'}',-2},{']',-1}};
	stack<char> st;

	for(auto i : s){
		if(m[i]>0)
			st.push(i);
		else{
			if(!st.empty() && (m[i]+m[st.top()])==0)
				st.pop();
			else
				return "NO";
		}
	

	}
		if(st.empty())
		return "YES";
		else
			return "NO";
}
int main(){
cout << isBalanced("{{[[(())]]}}");
cout << 2*3/2 << 2*(3/2);
}

