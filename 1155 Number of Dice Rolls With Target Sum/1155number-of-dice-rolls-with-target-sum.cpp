class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD=1e9+7;
        vector<vector<long long int>> dp(n+1 , vector<long long int> (target+1, 0));
        
        for(int j=1;j<=min(target, k);j++)
        {
            dp[1][j]=1;
        }
        
        for(int i=2;i<=n;i++)
        {
                for(int l=1;l<=target;l++)
                {
                    for(int j=1;j<=min(l,k);j++)
                    {
                    
                        dp[i][l]=((dp[i][l]%MOD)+(dp[i-1][l-j]%MOD))%MOD;
                    }
                    
                }
        }
         return dp[n][target]%MOD;
    }
};