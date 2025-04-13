// https://cses.fi/problemset/task/1694/


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ff first
#define ss second
 
const ll N=500,M=1e3,INF=1e17;
int n,m,pa[N],vis[N];
struct edge{
    int a,b,cap,rev;
} e[2*M];

vector<int> adj[N];

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
    ll f=0;
    while(1){
        memset(vis,0,sizeof(vis));
        queue<int> q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int cv = q.front();
            q.pop();
            if(cv==n-1)
                break;
            for(int i : adj[cv]){
                edge ed = e[i];
                if(ed.cap>0 and !vis[ed.b]){
                    pa[ed.b]=i;
                    vis[ed.b]=1; 
                    q.push(ed.b);
                }
            }
        }
        if(!vis[n-1]) 
            break;

        ll mf=INF;
        int x=n-1;

        while(x){
            int pe = pa[x];
            mf = min(mf,0ll+e[pe].cap);
            x=e[pe].a;
        }
              
        x=n-1;
        while(x){
            int pe = pa[x];
            e[pe].cap-=mf;
            e[e[pe].rev].cap+=mf;
            x=e[pe].a;
        }
        f+=mf;
    }
    cout << f;
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