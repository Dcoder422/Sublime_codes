ll n;
vector<ll> g[N];
bool vis[N];
void dfs(ll v){
    vis[v]=true;
    out v e;

    for(auto ch : g[v]){
        if(vis[ch])continue;

        dfs(ch);

        }

    } 
void solve(){
    in n ;
    For(i,0,n-1){
        ll a ,b;
        in a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
}








vector<int> g[N];
bool vis[N];
void dfs(int vertex){
    vis[vertex]=true;
    // cout << vertex << endl;
    for(int child : g[vertex]){
        // cout << "p " << vertex<<"  c " << child << endl;
         if(vis[child])continue;
        dfs(child);
        }
    } 
------------------------------------------------------


int n , m , g[1001][1001],vis[1001][1001];

vector<pii> moves={
    {1,0},{0,1},{-1,0},{0,-1}
    // ,{1,1},{-1,-1},{-1,1},{1,-1}
};

bool isval(int r , int c){
    return (r>=0 && r<n && c>=0 && c<m && !vis[r][c]);
}

void dfs(int r , int c){

    rep(mo,moves){
        int xx = r+mo.x;
        int yy = mo.y+c;
        if(isval(xx,yy))
            dfs(xx,yy);
    }
}    