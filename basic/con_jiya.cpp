#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
    	int n,p=1,a;
         cin >> n;
         for(int i=1;i<=n;i++){
         	cin >> a;
         	p=p*a;
         } 
         cout << p<< endl;
         if(p%10==2 || p%10==3 || p%10==5  )
         	cout << "YES" << endl;
         else
         	cout << "NO" << endl;
    }   
 }
