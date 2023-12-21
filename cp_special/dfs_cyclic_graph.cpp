#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
vector<bool> vis(N);
vector<vector<int>> g(N); // no. of rows
bool dfs(int ver,int par){
    vis[ver]=true;
    bool ans =false;
    for(auto child : g[ver]){
        if(vis[child] && child!=par)
            {ans|=true;break;}
        if(!vis[child])
            ans|=dfs(child,ver);

    }
    return ans;
}

int solve(int A, vector<vector<int> > &B) {
    vis.clear();
    g.clear();
// cout << vis.size(); 
    for(auto i : B){
        g[i[0]].push_back(i[1]);
        g[i[1]].push_back(i[0]);

    }
    bool ans = false;
    for(int i=1;i<=A;i++){
        if(vis[i])continue;
        ans |= dfs(i,0);
        if(ans==true)break;
        
    }
    return ((ans)?1:0);
}

int main(){
    int A=4;
    vector<vector<int> > B = {{1,2},{1,3},{5,4},{3,4}};
      cout << solve(A,B);
    }

// bool dfs(int ver,int par,vector<vector<int>> &g,vector<bool> &vis ){
//     vis[ver]=true;
//     bool ans =false;
//     if(g[ver].size()==0)return false;
//     for(auto child : g[ver]){
//         if(vis[child] && child!=par)
//             {ans|=true;break;}
//         if(!vis[child])
//             ans|=dfs(child,ver,g,vis);

//     }
//     return ans;
// }


// int Solution::solve(int A, vector<vector<int> > &B) {
//    vector<bool> vis(A+1,false);
// vector<vector<int>> g(A+1);
//     for(auto i : B){
//         g[i[0]].push_back(i[1]);
//         g[i[1]].push_back(i[0]);

//     }
//     bool ans = false;
//     for(int i=1;i<=A;i++){
//         if(vis[i])continue;
//         ans |= dfs(i,0,g,vis);
        
//     }
//     return ((ans)?1:0);
// }
