ll n ,m,vis[N];
vector<int> g[N],ad[N];
stack<int> st;

void dfs(int s){
    // out s e;
    vis[s]=1;
    for(auto ch : g[s]){
        if(vis[ch])continue;
        dfs(ch);
    }
    st.push(s);
}


void dfsn(int s){
    vis[s]=1;
    for(auto ch : ad[s]){
        if(vis[ch])continue;
        dfsn(ch);
    }
}

void solve(){
    in n;
    in m;

    For(i,0,m){
        int aa,b;
        in aa >> b;
        g[aa].pb(b);
    }
    For(i,1,n+1)if(!vis[i])
    dfs(i);
    For(i,1,n+1){
        vis[i]=0;
        rep(ch,g[i])ad[ch].pb(i);
    }
    while(!st.empty()){
        int to = st.top();
        st.pop();
        if(vis[to])continue;
        dfsn(to);
    }
}