class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int x = nums[0];
        nums.erase(nums.begin());
        sort(nums.begin(), nums.end());
        return x+nums[0]+nums[1];
    }
};