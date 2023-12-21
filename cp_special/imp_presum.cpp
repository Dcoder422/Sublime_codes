

//https://codeforces.com/contest/1426/problem/D

#include<bits/stdc++.h>
using namespace std;
int main(){
    	int n;
    	cin >> n;
    	int arr[n];
    	set<long long > s;
    	s.insert(0);
    	for(int i=0;i<n;i++){
			   cin >> arr[i]; 		
    	}
    	long long  c=0,d=0;
    	for(int i=0;i<n;i++){
			c+=arr[i];
			int si = s.size();
			s.insert(c);
			if(s.size()==si){
				d++;
				c=arr[i];
				s.clear();
				s.insert(c);
				s.insert(0);
			}
    	}

    	cout << d;
 }

			
