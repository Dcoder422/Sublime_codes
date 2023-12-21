//https://codeforces.com/problemset/problem/816/A

#include<iostream>
int n,m,i;int main(){scanf("%d:%d",&n,&m);for(;n!=m%10*10+m/10;i++){++m%=60,m?0:++n%=24;}std::cout<<i;}


// #include<bits/stdc++.h>
// using namespace std;
// int h,m;
// char c;

// int main(){
// 	cin>>h>>c>>m;
// 	for(int i=0;i<=1000000;i++){
// 		if(m==60)h++,m=0;
// 		if(h==24)h=0;
// 		int z=(m%10)*10+m/10;
// 		if(z==h){cout<<i<<endl;break;}
// 		m++;
// 	}
// }

