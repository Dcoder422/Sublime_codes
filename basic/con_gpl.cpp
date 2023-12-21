#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
         int n;
         cin >> n;
         string s;
         cin >> s;
         long long int sum=0;
         for(int i=0;i<n;i++){
         	sum+= pow(2,n-1-i)*(s[i]-48);
         }
         cout << sum << endl;
    }  
    long long int n_fac=1,r_fac=1;
    for(int j=0;j<19;j++){
                     n_fac*=21-j;
                        r_fac*=19-j;
		 }
		 cout << n_fac<<" "<< r_fac << " ";
         cout << n_fac/r_fac << " ";
 }
