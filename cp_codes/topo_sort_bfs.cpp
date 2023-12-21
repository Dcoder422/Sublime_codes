ll n,m;
vector<ll> g[N];
ll indegree[N];
vi ans;
void bfs(){
    queue<ll> q;
    For(i,0,n)if(!indegree[i]) // see no of starting node
    q.push(i);
    while(!q.empty()){
        ll cur_v = q.front();
        q.pop();
        ans.pb(cur_v);
        for(ll child : g[cur_v]){
            indegree[child]--;
            if(!indegree[child])
                q.push(child);   
        }
    }
    pv(ans); // id ans.size()!=n => cycle present
}

int main(){
    fastio();
    // freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    cin >> n >> m;
    for(ll i=0;i<m ;i++){
        ll a,b;
        cin >> a >> b;
        g[a].push_back(b);
        indegree[b]++;
    }
    bfs();
 }