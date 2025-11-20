class Solution {
public:
    // vector<int> dp;
    // Solution() {
    //     for(int i=0;i<46;i++)
    //     dp.push_back(-1);
    // }
    int climbStairs(int n) {
        // if (n == 0 || n == 1) {
        //     return 1;
        // }
        // if (dp[n] != -1) {
        //     return dp[n];
        // }
        // return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
        vector<int> dp(46, -1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }

        return dp[n];
    }
};