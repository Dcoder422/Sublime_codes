//https://codeforces.com/contest/1245/problem/D

#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<pair<long long,pair<int,int>>> wt;
vector<pair<int,int>> con;
vector<int> c0;
int par[N],si[N];
void make(int v){
	par[v]=v;
	si[v]=1;
}
int find(int v){
	if(v==par[v])return v;
	return par[v]=find(par[v]);
}

void Union(int a , int b){
	a=find(a);
	b=find(b);
	if(a!=b){
		if(si[a]<si[b])swap(a,b);
		par[b]=a;
		si[a]+=si[b];
	}
}
int main(){
	int n;
	cin >> n ;
	vector<pair<int,int>> v;
	long long x,y,w;
	for(int i=0;i< n;i++){
		cin >> x >> y ;
		v.push_back({x,y});
	}
	vector<int> k(n+1);
	
	for(int i=0;i< n;i++){
		int x;
		cin >> x;
		wt.push_back({x,{i+1,0}});
	}
	for(int i=0;i< n;i++){
		cin >> k[i+1];
	}
	
	for(int i=0;i<=n;i++){
		make(i);
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			wt.push_back({(k[i]+k[j])*1LL*(abs(v[i-1].first-v[j-1].first)+abs(v[i-1].second-v[j-1].second)),{i,j}});
		}
	}
	sort(wt.begin(),wt.end());
	long long cost=0;
	for(auto &g : wt){
		w=g.first;
		x=g.second.first;
		y=g.second.second;
		if(find(x)==find(y))continue;
		Union(x,y);
		cost+=w;
		if(y==0)c0.push_back(x);
		else con.push_back({x,y});
		// cout << x << " " << y << endl;
	}
	cout << cost << endl;
	cout << c0.size() << endl;
	for(auto i : c0)cout << i << " ";cout<<endl;
	cout << con.size() << endl;
	for(auto i : con)cout << i.first << " " << i.second << endl;	
}