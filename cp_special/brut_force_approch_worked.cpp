//https://www.hackerrank.com/challenges/recursive-digit-sum/problem

// brut force approach worked ...no need to optimise code
//ignored constraints
// had to catch pattern from given sample cases


#include<bits/stdc++.h>
using namespace std;
long long my(long long int n){
	if(n<10)
		return n;
	long long si=0;
	while(n>0){
		si+=n%10;
		n=n/10;
	}
	return my(si);
}
int superDigit(string n, int k) {
	long long sum =0;
	for(int i=0;i<n.size();i++){
		sum+= n[i]-'0';
	}
	sum = my(sum);
	int ans = my(sum*k);
	return ans;
}
int main(){
cout << superDigit("123",3);
    
}