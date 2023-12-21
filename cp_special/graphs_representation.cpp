#include<bits/stdc++.h>
using namespace std;

//adjacency matrix
//v.large space complexity-O(N^2)....not possible for N>1e4to1e3
// v x v -> v -> no. of vertices, e-> no. edges

// i,j connected ? i,j > wt ? O(1)

// const int N=1e3;
// int arr[N][N];
// int main(){
//       int n,m;
//       cin >> n >> m;
//       int x,y,wt;
//       for(int i=0;i<n ;i++){
//           cin >> x >> y;
//           arr[x-1][y-1]=arr[y-1][x-1]=wt;
//       }
//  }


//adjacency list -- O(v+e) no. of vertices, e-> no. edges
// usually no.of edges < 1e7 
// i,j connected ? i,j > wt ? O(v)
//mostly used

vector<int> gr[N];
// vector<pair<int,int>> gr[N]; -- for weighted
int main(){
      int n,m;
      cin >> n >> m;
      int x,y,wt;
      for(int i=0;i<n ;i++){
          cin >> x >> y >> wt;
          g[x-1].push_back(y);
          g[y-1].push_back(x);
          // g[x-1].push_back({y,wt});
          // g[y-1].push_back({x,wt});
      }
 }


