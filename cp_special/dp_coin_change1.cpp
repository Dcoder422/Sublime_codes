int dp[N];
int func(int amount , vector<int> &coins){
    if(amount ==0)return 0;
    int ans=INT_MAX;
    if(dp[amount]!=-1)return dp[amount];
    for(int coin : coins){
        if(amount-coin>=0)
        ans=min(ans+0LL,func(amount-coin,coins)+1LL);
    }
    return dp[amount]= ans;
}