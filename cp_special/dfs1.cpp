#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> g[N];
bool vis[N];void dfs(int vertex){
    //1.take action on the vertex after entering the vertex
    vis[vertex]=true;
    cout << vertex << endl;
    for(int child : g[vertex]){
        cout << "p " << vertex<<"  c " << child << endl;
        //2.take action on child before entering the child
        if(vis[child])continue;
        dfs(child);
        //3.take action on child after exiting the child(jb vapis aa rhe honge)
    }
    //4.take action on vertex before exiting the vertex
} //O(v+e)
int main(){
       int n , m,x,y;
       cin >> n>> m;
       for(int i=0;i<m;i++){
           cin >> x >> y;
           g[x].push_back(y);
           g[y].push_back(x);
       }
       dfs(1);
 }
