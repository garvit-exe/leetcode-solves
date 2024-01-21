class Solution {
public:

    // int findsum(vector<int> &nums, int i, vector<int> &dp) {
    //     if (i==nums.size()-1)
    //     return dp[i]=nums[i];

    //     if (i==nums.size()-2)
    //     return dp[i]=max(nums[i], nums[i+1]);

    //     if(dp[i]!=-1)
    //     return dp[i];

    //     int val1=nums[i]+findsum(nums, i+2, dp);
    //     int val2=findsum(nums, i+1, dp);
    //     return dp[i]=max(val1, val2);

    // }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n==1)
        return nums[0];

        if (n==2)
        return max(nums[0], nums[1]);

        vector<int> dp(n, -1);

        dp[n-1] = nums[n-1];
        dp[n-2] = max(nums[n-1], nums[n-2]);

        for(int i=n-3;i>=0;i--)
        {
            dp[i]=max(nums[i]+dp[i+2], dp[i+1]);
        }

        return dp[0];

    }
};