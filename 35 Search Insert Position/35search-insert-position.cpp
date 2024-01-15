class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // int a;
        // int indexl = 0;
        // int indexr = nums.size() - 1;
        // int mid = (indexl + indexr) / 2;
        // if (nums[indexl] == target) return indexl;        
        // else if (nums[indexr] == target) return indexr;
        // else if (nums[indexl] > target) return indexl;
        // else if (nums[indexr] < target) return indexr + 1;
        // while (indexl < indexr) {
        //     if (nums[mid] == target) return mid;
        //     else if (nums[mid] > target) {
        //         a = mid;
        //         indexr = mid - 1;
        //         mid = (indexl + indexr) / 2;
        //     }
        //     else {
        //         a = indexr;
        //         indexl = mid + 1;
        //         mid = (indexl + indexr) / 2;
        //     }
        // }
        // return a;

        int l=0;
        int r=nums.size()-1;
        while(l<=r) {
            int mid=l+(r-l)/2;
            if (nums[mid]==target)
            return mid;

            if (l==r) {
                if (nums[l] > target)
                return l;
                else return l+1;
            }

            if (nums[mid]<target)
            l=mid+1;
            else
            r=mid;
        }

        return -1;
    }
};