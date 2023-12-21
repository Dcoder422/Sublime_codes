#include <bits/stdc++.h>
using namespace std;

//2 ways of doing 1st optimization
// 1.size
// 2.rank - depth

//2nd optimization
// path compression - puri depth k nodes ko direct parent se jodlo
const int N=1e5+10;
int parent[N],size[N];
void make(int v){
	parent[v]=v;
	size[v]=1;
}
int find(int v){
	if(v==parent[v])return v;//true when v is root of a tree
	// Path compression
	return parent[v]=find(parent[v]);
}	
void Union(int a , int b){
	a=find(a);
	b=find(b);
	if(a!=b){
		// Union by size
		if(size[a]<size[b])swap(a,b);
		parent[b]=a;
		 size[a]+=size[b];
	}
}

//O(a(n))  [amorterized time complexity -- as no.of calls increases
// time complexity becomes almost constant ]
// hence its time complexity can be almost assumed to be constant

// a(n)-> reverse Ackerman function
//its value increases v slowly 

//for even resonably large value of n a(n) does not exeed 4

int main(){
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n ;i++){
		make(i);
	}
	for(int i=0;i<k;i++){
		int x,y;
		cin >> x >> y;
		Union(x,y);
	}
	int connected_ct = 0;
	for(int i=1;i<=n ;i++){
		if(find(i)==i)
			connected_ct++;
	}
	cout << connected_ct ;
}