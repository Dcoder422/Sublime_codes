#include <bits/stdc++.h>
using namespace std;

//below function returns the length of longest 
//increasing subsequence ***which ends at i*** 
// or in which i is included as the last element

int func(int i,vector<int> &a,int dp[] ){
	int ans=1;
	if(dp[i]!=-1)return dp[i];
	for(int j=0;j<i;j++){
		if(a[i]>a[j])
			ans=max(ans,func(j,a,dp)+1 );
	}
	return dp[i]=ans;
}

int lengthOfLIS(vector<int>& nums) {
	int ans=1;
	int dp[nums.size()];
	memset(dp,-1,sizeof(dp));
        for (int i = 0; i < nums.size(); ++i)
        {
        	ans=max(ans,func(i,nums,dp));
        }
        return ans;
    }

int main(){
	vector<int> nums={7,7,7,7,7,7,7};
	cout << lengthOfLIS(nums);
}    