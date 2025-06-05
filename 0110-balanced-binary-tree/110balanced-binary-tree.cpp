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
    bool isBalanced(TreeNode* root) {
        if (root==NULL) {
            return true;
        }
        pair<int, bool> a = hi(root);
        return a.second;
    }
    pair<int, bool> hi(TreeNode* root) {
        if (root==NULL) {
            return {0, true};
        }
        pair<int, bool> l = hi(root->left);
        pair<int, bool> r = hi(root->right);
        int height = max(l.first, r.first) + 1;
        if (l.second && r.second && (abs(l.first-r.first)==0 || abs(l.first-r.first)==1)) {
            return {height, true};
        }
        return {height, false};
    }
};