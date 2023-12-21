#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		s = 0;
		while(n>0){
			r = n%10;
			s+=r;
			n/=10;
		}
		cout << s<< endl;
	}
}