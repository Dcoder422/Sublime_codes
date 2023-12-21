 int my(vector<int>& coins,int amount,int dp[5005][305],int in){
        if(amount==0)return 1;
        if(in<0) return 0;
        if(dp[amount][in]!=-1)return dp[amount][in];
        int ways=0;
        for(int i=0;i<=amount;i+=coins[in]){
            ways+=my(coins,amount-i,dp,in-1);
        }
        return dp[amount][in]=ways;
    }
    int change(int amount, vector<int>& coins) {
        int dp[5005][305];
        memset(dp,-1,sizeof(dp));
        return my(coins,amount,dp,coins.size()-1);
    }