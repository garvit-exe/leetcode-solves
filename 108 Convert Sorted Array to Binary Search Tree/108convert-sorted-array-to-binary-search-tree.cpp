/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size()==0) {
            return NULL;
        }
        return hi(nums, 0, nums.size()-1);
    }
    TreeNode* hi(vector<int>& nums, int left, int right) {
        if (left>right) {
            return NULL;
        }
        if (left==right) {
            TreeNode* k = new TreeNode(nums[left]);
            return k;
        }
        int middle=left+(right-left)/2;
        TreeNode* k = new TreeNode(nums[middle]);
        k->left=hi(nums, left, middle-1);
        k->right=hi(nums, middle+1, right);
        return k;
    }
};