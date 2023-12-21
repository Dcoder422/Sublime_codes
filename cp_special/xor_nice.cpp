//https://codeforces.com/problemset/problem/1421/A

//beautifuly used property of xor

//ans is simply the xor of a and b

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
         int a,b;
         cin >> a >> b;

         // int c=0;
         // for(int i=0;i<32;i++){
         // 	if((((a>>i)&1)!=0) && (((b>>i)&1)!=0))
         // 		c|=(1<<i);
         // }
         //  cout << c << endl;
         // cout << ((a^c) + (b^c)) << endl;
         
         cout << (a^b) << endl;
    }   
 }
