class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if (um.find(x) != um.end() && i - um[x] <= k) return true;

            um[x] = i;
        }

        return false;
    }
};