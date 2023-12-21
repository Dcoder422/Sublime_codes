#include<bits/stdc++.h>
using namespace std;

queue<pair<int,int>> q;
int n,m;
int lev[505][505],vis[505][505];
void reset(){
	for(int i=0;i<n;i++){
         	for(int j=0;j<m;j++){
         		lev[i][j]=0;
         		vis[i][j]=0;
         	}
         }
}
vector<pair<int,int>> movements={{1,1},{-1,-1},{-1,1},{1,-1},
{0,1},{1,0},{0,-1},{-1,0}};

bool isvalid(int x,int y){
	return (x>=0 && y>=0 && x<n && y<m );
}
int bfs(){
	int ans =0;
	while(!q.empty()){
		auto cv = q.front();
		q.pop();
		for(auto mov : movements){
			int x = cv.first+mov.first;
			int y = cv.second + mov.second;
			if(!isvalid(x,y))continue;
			if(vis[x][y])continue;
			lev[x][y]=1+lev[cv.first][cv.second];
			vis[x][y]=1;
			q.push({x,y});
			ans = max(ans,lev[x][y]);
		} 
	}
	return ans;
}
int main(){
    int t;
    cin >> t;
    while(t--){       
         cin >> n >> m;
         int g[n][m];
         int ma=0;
         for(int i=0;i< n;i++){
         	for(int j=0;j<m;j++){
         		cin >> g[i][j];
         		ma=max(ma,g[i][j]);
         	}
         }
        
         for(int i=0;i< n;i++){
         	for(int j=0;j<m;j++){
         		if(g[i][j]==ma){
         			q.push({i,j});
         			vis[i][j]=1;}
         			}
         }
         cout << bfs() << endl;
         reset();
    }   
 }






