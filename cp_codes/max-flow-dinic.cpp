// https://www.youtube.com/watch?v=M6cm8UeeziI&t=454s

// https://www.youtube.com/watch?v=_SdF4KK_dyM

// for time complexity ->cp algorithm

// https://cses.fi/problemset/task/1694/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ff first
#define ss second
 
const ll N=500,M=1e3,INF=1e17;
int n,m,lvl[N],nxt[N];
struct edge{
    int a,b,cap,rev;
} e[2*M];
 
vector<int> adj[N];

ll dfs(int v, ll mf){
    // cout << v+1 << " " << mf << endl;
    if(v==n-1) return mf;
    for(nxt[v];nxt[v]<adj[v].size();nxt[v]++){
        int i=adj[v][nxt[v]];
        // cout << e[i].a+1 << " " << e[i].b+1 << " " << e[i].cap << endl;
        if(e[i].cap and lvl[e[i].b]>lvl[v]){
            ll new_mf = dfs(e[i].b,min(mf,0ll+e[i].cap));
            if(new_mf){
                e[i].cap-=new_mf;
                e[e[i].rev].cap+=new_mf;
                return new_mf;
            }
        }
    }
    return 0;
}
 
void solve(){
    
    cin >> n >>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--,b--;
        e[2*i]={a,b,c,2*i+1};
        e[2*i+1]={b,a,0,2*i};
        adj[a].push_back(2*i);
        adj[b].push_back(2*i+1);
    }
    ll mf=0;
    while(1){
        // bfs
        memset(lvl,0,sizeof(lvl));
        queue<int> q;
        q.push(0);
        lvl[0]=1;
        while(!q.empty()){
            int cv = q.front();
            q.pop();
            if(cv==n-1)
                break;
            for(int i : adj[cv]){
                edge ed = e[i];
                if(ed.cap>0 and !lvl[ed.b]){
                    lvl[ed.b]=lvl[ed.a]+1; 
                    q.push(ed.b);
                }
            }
        }
        if(!lvl[n-1])break;     

        // for pruning blocking flow after each dfs
        memset(nxt,0,sizeof(nxt));

        // dfs
        for(ll f=1;f;f=dfs(0,INF),mf+=f);
    }
    cout << mf;
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
