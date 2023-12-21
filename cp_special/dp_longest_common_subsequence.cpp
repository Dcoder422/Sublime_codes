int dp[1001][1001];
    int solve(string &s1, string &s2, int i1,int i2,int ans){
        if(i1<0 || i2<0)return 0;
        if(dp[i1][i2]!=-1)return dp[i1][i2];
        if(s1[i1]==s2[i2])
        ans = 1+solve(s1,s2,i1-1,i2-1,0);
        else{
            ans=solve(s1,s2,i1-1,i2-1,0);
            ans=max(ans,solve(s1,s2,i1-1,i2,0));
            ans=max(ans,solve(s1,s2,i1,i2-1,0));
        }
        return dp[i1][i2]= ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return solve(text1,text2,text1.size()-1,text2.size()-1,0);
    }

    //luv way
    int solve(string &s1, string &s2, int i1,int i2){
        if(i1<0 || i2<0)return 0;
        if(dp[i1][i2]!=-1)return dp[i1][i2];
 
        int ans = solve(s1,s2,i1-1,i2);
        ans=max(ans,solve(s1,s2,i1,i2-1));
        ans=max(ans,solve(s1,s2,i1-1,i2-1)+(s1[i1]==s2[i2]));
        return dp[i1][i2]= ans;
    }