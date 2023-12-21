ll n,m;
vector<ll> g[N];
ll vis[N],level[N];

void bfs(ll source){
    vis[source]=1;
    queue<ll> q;
    q.push(source);
    while(!q.empty()){
        ll cur_v = q.front();
        q.pop();
        for(ll child : g[cur_v]){
            if(!vis[child]){
                q.push(child);
                vis[child]=1;
                level[child]=level[cur_v]+1;
            }
        }
    }
}

int main(){
    fastio();
    // freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    cin >> n >> m;
    for(ll i=0;i<m ;i++){
        ll a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs(1);
 }