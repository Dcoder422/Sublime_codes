#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
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
	int n,m;
	cin >> n >> m;
	vector<pair<int,pair<int,int>>> v;
	int x,y,w;
	for(int i=0;i< m;i++){
		cin >> x >> y >> w;
		v.push_back({w,{x,y}});
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
		make(i+1);
	}
	int cost=0;
	for(auto &g : v){
		w=g.first;
		x=g.second.first;
		y=g.second.second;
		if(find(x)==find(y))continue;
		Union(x,y);
		cost+=w;
		cout << x << " " << y << endl;
	}
	cout << cost << endl;
}