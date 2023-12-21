

//ep_16 luv problem

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int arr[N][26];
int main(){
    int t;
    cin >> t;
    while(t--){
         int n,q;
         cin >> n >> q;
         string s;
         cin >> s;
         for(int i=0;i<26;i++){
         	for(int j=1;j<=n;j++){
         		arr[j][i]=0;
         		if((s[j-1]-'a')==i)
         			arr[j][i]=1;
         		arr[j][i]+=arr[j-1][i];
         	}
         }

         // for(int i=0;i<26;i++){
         // 	for(int j=1;j<=n;j++){
         // 		cout << arr[j][i] << " ";

         // 	}
         // 	cout << endl;
         // }
         while(q--){
         	int l,r,c=0;
         	cin >> l >> r;
         	for(int i=0;i<26;i++){
         		if((arr[r][i]-arr[l-1][i])%2==1)c++;
         	}
         	if(c>1)cout << "NO" << endl;
         	else
         		cout << "YES" << endl;


         }
    }   
 }

			
