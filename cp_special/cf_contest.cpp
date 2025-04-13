#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ff first
#define ss second
#define ld long double

const ll N=1e5+4,INF=1e18,B=61;


ll dp[B][B];

// void solve(){
    

int main(){
    int t;
    cin >> t;
    cout << "hi" << t << endl;
    return 0;
    // t=1;
    // for(int i=0;i<B;i++)
    //     for(int j=0;j<B;j++)
    //         dp[i][j]=INF;

    // dp[0][0]=0;

    // for(int x=1;x<B;x++){
    //     for(int i=B-1;i>=0;i--){
    //         for(int j=B-1;j>=0;j--){
    //             if(dp[i][j]==INF)
    //                 continue;
    //             if(i+x<B)dp[i+x][j]=min(dp[i+x][j],dp[i][j]+1ll<<x);
    //             if(j+x<B)dp[i][j+x]=min(dp[i][j+x],dp[i][j]+1ll<<x);
    //         }
    //     }
    // }

    // while(t--)
    //     solve();
}