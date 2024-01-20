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
    int minDepth(TreeNode* root) {
        if (root==NULL) {
            return 0;
        }
        if (root->left==nullptr && root->right==nullptr) {
            return 1;
        }
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        if (root->left==nullptr) {
            return r+1;
        }
        else if (root->right==nullptr) {
            return l+1;
        }
        else {
            return min(l, r)+1;
        }
    }
};