#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int INF = 1e9+10;
vector<pair<int,int>> g[N];
vector<int> lev(N, INF);
void bfs(){
	deque <int> q;
	lev[1]=0;
	q.push_back(1);
	while(!q.empty()){
		int cv = q.front();
		q.pop_front();
		for( auto child : g[cv]){
			if(lev[cv]+child.second<lev[child.first]){
				lev[child.first]=lev[cv]+child.second;
				if(child.second==0)q.push_front(child.first);
				else q.push_back(child.first);
			}
			
		}
	}
}

int main(){
        int n, m;
        cin >> n >> m;
        for(int i=0;i<m ;i++){
         	int x,y;
         	cin >> x >> y;
         	if(x==y)continue;
         	g[x].push_back({y,0});
         	g[y].push_back({x,1});
         }
         bfs();
         cout << (lev[n]!=INF?lev[n]:-1) << endl; 
       
 }
