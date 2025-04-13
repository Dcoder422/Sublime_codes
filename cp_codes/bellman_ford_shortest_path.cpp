// single source
// negative weights
//O(V*E)
//https://www.youtube.com/watch?v=0vVofAhAYjc&t=1470s

V-> no. of vertices
S->Source
vector<int> dist(V,1e8);
dist[S]=0
for (int i=0;i<V;i++){
	for(auto it : edges){
		int u=it[0];
		int v=it[1];
		int wt=it[2];
		if (dist[u] !=1e8 && dist[u]+wt<dist[v])
			dist[v]=dist[u]+wt;
	}
}
