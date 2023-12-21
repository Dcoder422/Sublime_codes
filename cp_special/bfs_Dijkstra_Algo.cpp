#include <bits/stdc++.h>
using namespace std;

// one source - multiple destination
const int N=1e3;
const int INF=1e9+10;
int dis[N],vis[N];
vector<pair<int,int>> g[N];
set<pair<int,int>> q;
void reset(){
	for(int i=0;i<N;i++){
		vis[i]=0;
		dis[i]=INF;
	}
}

void dji(int source){
	q.insert({0,source});
	dis[source]=0;
	while(!q.empty()){
		auto cn = *q.begin();
		vis[cn.second]=1;
		q.erase(q.begin());
		for(auto child : g[cn.second]){
			if(vis[child.second])continue;
			if((child.first+dis[cn.second])<dis[child.second]){
				dis[child.second]=(child.first+dis[cn.second]);
				q.insert({(child.first+dis[cn.second]),child.second});  //O(logV)
			}
		}
	}
}
// O(V + ElogV)

int main(){
	int n;
	cin >> n;//nodes
	reset();	
	for(int i=0;i<9;i++){
		int x , y, d;
		cin >> x >> y >> d;
		g[x].push_back({d,y});
	}
	dji(1);
	for(int i=1;i<=n;i++){
		cout << dis[i] << endl;
	}
}
// 6
// 1 2 1
// 1 3 5
// 2 3 2
// 2 4 2
// 2 5 1
// 3 5 2 
// 4 6 1
// 4 5 3
// 5 6 2




