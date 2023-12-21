// Nth root of a number using binary search

#include<bits/stdc++.h>
using namespace std;
double eps = 1e-6;
double multiply(double mid,int n){
	double ans=1; 
	while(n--)ans*=mid;
	return ans;
}
int main(){
	    double x;
    cin >> x;
    double lo=1,hi=x,mid;
    int n;cin >> n;
    while(hi-lo>eps)
{
	mid=(lo+hi)/2;
	// cout << mid;
	if(multiply(mid,n)<x)lo=mid;
	else hi = mid;
 }
 cout << lo ;// both low and high will be precise upto 5 decimal places
}
// pth root of Number N with d decimal accuracy

//O(p*log(N*(10^d)))