//https://leetcode.com/problems/number-of-islands/description/

#include<bits/stdc++.h>
using namespace std;
void dfs(int r,int c,vector<vector<char>>& grid){
    int rn=grid.size();
    int cn = grid[0].size();
    if(r<0 | c<0 | r>rn-1 | c>cn-1)return ;
    if(grid[r][c]=='2' || grid[r][c]=='0' )return;
    grid[r][c]='2';
    dfs(r+1,s);
    dfs(r,s+1);
    dfs(r-1,s);
    dfs(r,s-1);
}

int numIslands(vector<vector<char>>& grid) {
    int c=0;
     int rn=grid.size();
    int cn = grid[0].size();
    for(int i=0;i<rn;i++){
        for(int j=0;j<cn;j++){
            if(grid[i][j]=='1'){
                dfs(i,j,grid);
                c++;
            }
    }
    }
        return c;
    }
int main(){
      
 }
