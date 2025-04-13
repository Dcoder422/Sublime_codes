//https://www.youtube.com/watch?v=oib-XsjFa-M

class TreeAncestor {
public:
    
    int depth[50004],dp[50004][17];
    TreeAncestor(int n, vector<int>& parent) {
        memset(dp,0,sizeof(dp));

        // can also do following part in a dfs

        depth[0]=0;
        for(int i=1;i<n;i++)dp[i][0]=parent[i];
        for(int i=1;i<17;i++){
            for(int j=1;j<n;j++){
                depth[j]=depth[parent[j]]+1;
                dp[j][i]=dp[dp[j][i-1]][i-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if(k>depth[node])return -1;
        int ans=node,j=0;
        while(k){
            if(k&1)ans=dp[ans][j];
            k>>=1;
            j++;
        }
        return ans;
    }
};