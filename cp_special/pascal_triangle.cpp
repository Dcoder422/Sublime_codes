#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
		int n,ro;
		cin >> n;
		
	
         for(int i=0;i<n;i++){
		 	long long int c=1;
         //  cout << c << " ";
			 for(int r=1;r<=i+1;r++){
                 cout << c << " ";
                 c=c*(i-r+1)/r;
		 }
        cout << endl;
		 }
        
    }   

 }
