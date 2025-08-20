class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> um;

        for (int i : nums) {
            um[i]++;
            if (um[i] > nums.size() / 2) return i;
        }

        return -1;
    }
};