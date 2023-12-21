#include<bits/stdc++.h>
using namespace std;


void dfs(int vertex,int par,vector<int> &A,vector<int> g[],vector<int> &su){
    su[vertex]+=A[vertex-1];
    for(auto child : g[vertex]){
        if(child==par)continue;
        dfs(child,vertex,A,g,su);
        su[vertex]+=su[child];
    }
    // cout << vertex << " " << su[vertex] << endl;
}
int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    int M=1e9+7;
    vector<int> g[A.size()+1];
    vector<int> su(A.size()+1,0);
    for(auto edge : B){
        g[edge[0]].push_back(edge[1]);
        g[edge[1]].push_back(edge[0]);
    }
    dfs(1,0,A,g,su);
    long long  ans=0;
    for(int i=2;i<=A.size();i++){
       int p1 = su[i];
       int p2 = su[1]-p1;
       ans = max(ans,((p1*1LL*p2)));
    }
    return ans%M;
}
int main(){
    vector<int> A={};
    vector<vector<int> > B={};
    // cout << accumulate(A.begin(),A.end(),0)<< endl;
    cout << deleteEdge(A,B);
 }
