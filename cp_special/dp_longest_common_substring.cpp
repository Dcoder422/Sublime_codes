
    int dp[1001][1001];
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int ma=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(S1[i]==S2[j]){
                    if(i-1>=0 && j-1>=0)
                    dp[i][j]=1+dp[i-1][j-1];
                    else dp[i][j]=1;
                    ma=max(ma,dp[i][j]);
                }
                else dp[i][j]=0;
            }
        }
        return ma;
    }