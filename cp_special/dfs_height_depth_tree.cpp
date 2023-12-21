#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
vector<int> g[N];
vector<int> h(N,0),d(N,0);
void dfs(int vertex,int par){
    for(auto child : g[vertex]){
        if(child==par)continue;
        // cout << vertex << " " << child << endl;
        d[child]=1+d[vertex];
        // cout << d[child] << endl;
        dfs(child,vertex);
        h[vertex]=max(1+h[child],h[vertex]);
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
    dfs(1,0);
    for(int i=1;i<=13 ;i++){
        cout << d[i] << " ";
    }
    cout  << endl;
    for(int i=1;i<=13 ;i++){
        cout << i << " ";
    }
    cout  << endl;
    for(int i=1;i<=13 ;i++){
        cout << h[i] << " ";
    }
    
}