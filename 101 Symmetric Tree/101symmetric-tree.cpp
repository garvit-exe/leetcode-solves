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
    bool isSymmetric(TreeNode* root) {
        // if (root == NULL) {
        //     return true;
        // }
        // if (root->left != NULL && root->right != NULL) {
        //     if ((root->left)->val == (root->right)->val) {
        //         isSymmetric(root->left);
        //         isSymmetric(root->right);
        //         return true;
        //     } else {
        //         return false;
        //     }
        // }
        // if (root->left != NULL || root -> right != NULL) {
        //     return false;
        // }
        // return true;

        // if (root == NULL) {
        //     return true;
        // }
        // if (root->left == NULL && root->right == NULL) {
        //     return true;
        // }
        // if (root->left == NULL || root->right->right == NULL) {
        //     return false;
        // }

        // TreeNode* l = root->left;
        // TreeNode* r = root->right;
        // bool ans;

        // hi(l, r, ans);

        // return ans;
        if (root == NULL) return true;
        return compare(root->left, root->right);

    }
    // void hi(TreeNode* a, TreeNode* b, bool& ans) {
    //     if (a != nullptr && b != nullptr) {
    //         if (a->val == b->val) {
    //             hi(a->left, b->right, ans);
    //             hi(a->right, b->left, ans);
    //             ans = true;
    //         } else {
    //             ans = false;
    //         }
    //     }
    // }

    bool compare(TreeNode* a, TreeNode* b) {
        if(a==NULL && b==NULL)
        return true;
        if(a==NULL || b==NULL)
        return false;

        if(a->val != b->val)
        return false;

        return compare(a->left, b->right) && compare(a->right, b->left);
    }
};