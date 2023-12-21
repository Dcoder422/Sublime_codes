int dp[20005][205];
    bool my( vector<int>& nums,int sum,int in){
        if(sum==0) return true;
        if(in<0)return false;
        if(dp[sum][in]!=-1)return dp[sum][in];
        bool ans = false;
        ans|=my(nums,sum,in-1);
        if(sum-nums[in]>=0)
        ans|=my(nums,sum-nums[in],in-1);
        return dp[sum][in]=ans;
    }

    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1)return false;
        return my(nums,sum/2,nums.size()-1);
    }