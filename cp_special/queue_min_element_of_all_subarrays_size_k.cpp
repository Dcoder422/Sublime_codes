#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i=0;i<n;i++)cin>> v[i];
	deque<int> st;
int mi_sum =0;
	for(int i=0;i<k;i++){
		if(st.empty())st.push_back(v[i]);
		else{
			while(!st.empty() && v[i]<st.back())st.pop_back();
			st.push_back(v[i]);
		}
	}
	mi_sum+=st.front();	cout << st.front() << endl;
	for(int i=k;i<n;i++){
		if(!st.empty() && st.front()==v[i-k])st.pop_front();
		if(st.empty())st.push_back(v[i]);
		else{
			while(!st.empty() && v[i]<st.back())st.pop_back();
			st.push_back(v[i]);
		}
		cout << st.front() << endl;
		mi_sum+=st.front();
	}
	cout << mi_sum;
}