int my(int price[],int n,int j,int dp[1005][1005] ){
        if(n==0)return 0;
        if(j>n)return -1e9;
        if(dp[n][j]!=-1)return dp[n][j];
        int ans=0;
        for(int i=0;i<=n;i+=j){
            ans=max(ans,my(price,n-i,j+1,dp)+(i/j)*price[j-1]);
        }
        return dp[n][j]=ans;
    }
    int cutRod(int price[], int n) {
        int dp[1005][1005];
        memset(dp,-1,sizeof(dp));
        return my(price,n,1,dp);
    }

//luv way
int dp[1005];
int func(int len,vector<int> &prices){
    if(len==0)return 0;
    if(dp[len]!=-1) return dp[len];
    int ans=0;
    for(int cut=1;cut<=prices.size();++cut){
        if(len-cut>=0)
            ans=max(ans,func(len-cut,prices)+prices[cut-1]);
    }
    return dp[len]=ans;
} 
int cutRod(int price[], int n) {
        memset(dp,-1,sizeof(dp));
        vector<int> prices(price,price+n);
        return func(n,prices);
    }
