#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
vector<int> g[N];
vector<int> p(N,0);
void dfs(int vertex,int par=-1){
    p[vertex]=par;  
    for(auto child : g[vertex]){
        if(child==par)continue;        
        dfs(child,vertex);  
    }
}

vector<int > path(int v){
    vector<int> ans;
    ans.push_back(v);
    while(p[v]!=-1){ 
        ans.push_back(p[v]);
        v=p[v];
    }
    reverse(ans.begin(),ans.end());
    return ans;

}
int main(){
    int n,m;int x,y;
    cin >> n >> m;
    for(int i=0;i<m ;i++){
        
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cin >> x >> y; 
    dfs(1);
    vector<int> v1=path(x);
    vector<int> v2=path(y);
    int v1s = v1.size(),v2s=v2.size();
    int s = min(v1s,v2s),i=0;
    for( i=0;i<s;i++){
        if(v1[i]==v2[i])continue;
        else
            break;
    }

    cout << v1[i-1];
    
 }    