// https://cses.fi/problemset/task/1696/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ff first
#define ss second
 
const ll N=500,M=1e3,INF=1e17;
int n,m,k,mt[N],vis[N];
struct edge{
    int a,b,cap,rev;
} e[4*M];

vector<int> adj[N];

bool dfs(int u){
    vis[u]=1;
    for(auto v1 : adj[u]){
        if(mt[v1]<0 or (!vis[mt[v1]] and dfs(mt[v1]))){
            mt[v1]=u;
            return 1;
        }
    }
    return 0;
}

void solve(){
    
    cin >> n >>m >> k;
    for(int i=0;i<k;i++){
        int a,b;
        cin >> a >> b ;
        a--,b--;
        adj[a].push_back(b);
    }
    memset(mt,-1,sizeof(mt));  // mathing (idx)girl->boys 
    int f=0;
    for(int i=0;i<n;i++){
        memset(vis,0,sizeof(vis));
        f+=dfs(i);
    }
    cout << f << endl;
    for(int i=0;i<m;i++){
        if(~mt[i]){
            cout << mt[i]+1 << " " << i+1 << endl;
        }
    }

}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    // cin >> t; []                                                               
    t=1;
    while(t--)
        solve();
}