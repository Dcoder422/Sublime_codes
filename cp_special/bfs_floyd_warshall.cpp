#include <bits/stdc++.h>
using namespace std;

// multiple source multiple destination
// all pair shortest path algo

//works for directed as well as undirected graph
//example is a directed graph

//1.handles negative weight of edges
//2.does not handle negative weighted cycle 

const int N =510;
const int INF = 1e9+10;

int dist[N][N];

int main(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N ;j++){
			if(i==j)dist[i][j]=0;
			else dist[i][j]=INF;
		}
	}
	int n,m;
	cin >> n >> m;

	for(int i=0;i<m;i++){
		int x,y,w;
		cin >> x >> y >> w;
		dist[x][y]=w;
	}
	for(int k=1;k<=n ;k++){
		for(int i=1;i<=n;i++){
		for(int j=1;j<=n ;j++){
			dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
		}
	}
	}
}

// 6 9
// 1 2 1
// 1 3 5
// 2 3 2
// 2 4 2
// 2 5 1
// 3 5 2 
// 4 6 1
// 4 5 3
// 5 6 2
