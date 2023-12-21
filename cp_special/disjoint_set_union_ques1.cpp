//https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-campers/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int par[N],si[N];
	multiset<int> s;
void make(int s){
	par[s]=s;
	si[s]=1;
}
int find(int v){
	if(v==par[v])return v;
	return par[v]=find(par[v]);
}

void merge(int a,int b){
	s.erase(s.find(si[a]));
	s.erase(s.find(si[b]));
	s.insert(si[a]+si[b]);
}
void Union(int a , int b){
	a=find(a);
	b=find(b);
	if(a!=b){
		if(si[a]<si[b])swap(a,b);
		par[b]=a;
		merge(a,b);
		si[a]+=si[b];
	}
}

int main(){
	int n,q;
	cin >> n >> q;

	for(int i=1;i<=n;i++){
		make(i);
		s.insert(1);
	}

	while(q--){
		int x,y;
		cin >> x >> y;
		Union(x,y);
		cout << *(--s.end())-*s.begin() << endl;
	}

}