#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
vector<int > g[N];
bool vis[N];
vector<vector<int>> cc;
    vector<int> cs;
void dfs(int vertex){
    vis[vertex]=1;
    cs.push_back(vertex);
    for(auto child : g[vertex]){
        if(vis[child])continue;
        dfs(child);
    }
}
int main(){
    int n,e,x,y;
    cin >> n >> e ;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }int c=0;

    for(int i=1;i<=n ;i++){
             if(!vis[i]){
                dfs(i);c++;
                cc.push_back(cs);
                cs.clear();
             }
         }     
     cout << c ;
     for( auto i : cc){
        for(auto j : i) cout << j << " ";cout << endl;
     }
     }
