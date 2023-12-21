//https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbTlPMEtFYjlqOEt6U0VQc2ZaMFFCUUgtZHItZ3xBQ3Jtc0ttMlRxQjJuWWNfQjc5ZnFoYzk4cWlPdWdRRmtCb0hZTG5vOHVEWjBqa1BJUVlfUFJxdFowZW5FXy1QdXpnZnZIUEVUNjFLbmtVOEt2aVFuQmNkX28tay1MdUlfVVMyRHI2NWFKUGFzalNkaG9EMkRDUQ&q=https%3A%2F%2Fwww.spoj.com%2Fproblems%2FNAKANJ%2F&v=WOV3LYhPews

#include<bits/stdc++.h>
using namespace std;

int vis[8][8],level[8][8];

vector<pair<int,int>> movements={{-1,2},{-2,1},{-2,-1},{-1,-2},
{1,2},{2,1},{2,-1},{1,-2}};

bool isvalid(int x , int y){
    return (x>=0 && y>=0 && x<8 && y<8);
}
void zero(){
    for(int i=0;i<8 ;i++){
            for(int j=0;j<8 ;j++){
                vis[i][j]=0;
                level[i][j]=0;
            }
        }
}
void bfs(int sx , int sy ){
    vis[sx][sy]=1;
    queue<pair<int,int>> q;
    q.push({sx,sy});
    while(!q.empty()){
        auto cur_v = q.front();
        q.pop();
        for(auto m : movements){
            int x= m.first + cur_v.first;
            int y = m.second + cur_v.second;
            if(!isvalid(x,y))continue;
            if(!vis[x][y]){
                q.push({x,y});
                vis[x][y]=1;
                level[x][y]=level[cur_v.first][cur_v.second]+1;
            }
        }
    }
}
//O(V+2*E)
// O(V+E)
int main(){
    int t;
    cin >> t;
    while(t--){
        string s1,s2;
        cin >> s1 >> s2;
        int sx,sy,dx,dy;
        sx = s1[0]-'a';
        sy = s1[1]-'1';
        dx = s2[0]-'a';
        dy = s2[1]-'1';
        // cout << sx << sy << dx << dy << endl;
        bfs(sx,sy);
        // for(int i=0;i<8 ;i++){
        //     for(int j=0;j<8 ;j++){
        //         cout << level[i][j] << " ";
        //     }cout << endl;
        // }
        cout << level[dx][dy] << endl;
        zero();

    }
    
 }
