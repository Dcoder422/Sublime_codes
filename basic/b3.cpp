#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	if(n%2==0){
		if((n/2)%2==1)
			cout << n/4 << endl;
		else 
			cout << n/4-1 << endl;
	}
	else
		cout << 0 << endl;
	}