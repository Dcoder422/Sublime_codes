#include<bits/stdc++.h>
using namespace std;

//in subtree sum value of a node , its value is also included
const int N=1e5+5;
vector<int> g[N];
vector<int> h(N,0),d(N,0);
vector<int> sum(N),ev(N);
void dfs(int vertex,int par){
    for(auto child : g[vertex]){
        if(child==par)continue;
        dfs(child,vertex);
        sum[vertex]+=sum[child];
        
        ev[vertex]+=ev[child]; 
    }sum[vertex]+=vertex;
    if(vertex%2==0)ev[vertex]++;

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
        cout << sum[i] << " ";
    }
    cout  << endl;
    for(int i=1;i<=13 ;i++){
        cout << i << " ";
    }
    cout  << endl;
    for(int i=1;i<=13 ;i++){
        cout << ev[i] << " ";
    }
    
}