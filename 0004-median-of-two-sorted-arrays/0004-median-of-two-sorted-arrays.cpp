class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int n = nums1.size() + nums2.size();
        for (int i : nums1) v.push_back(i);
        for (int i : nums2) v.push_back(i);

        sort(v.begin(), v.end());

        if (n % 2 != 0) return v[(n - 1) / 2];
        else return ((double)v[n / 2] + v[n / 2 - 1]) / 2;
    }
};