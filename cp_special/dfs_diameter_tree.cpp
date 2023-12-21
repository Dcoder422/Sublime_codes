#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
vector<int> g[N];
vector<int> h(N,0),d(N,0);
void dfs(int vertex,int par=-1){ // default value  
    for(auto child : g[vertex]){
        if(child==par)continue;
        d[child]=1+d[vertex];
        dfs(child,vertex);  
    }

}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m ;i++){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    int r = max_element(d.begin(),d.end())-d.begin();
    // cout << r <<     endl;
    for(int i=1;i<=n ;i++){
        // cout << d[i] << endl;
        d[i]=0;
    }
    dfs(r);
    cout << *max_element(d.begin(),d.end());
}