/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int preorderIndex = 0;

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return build(preorder, inorder, 0, inorder.length-1);
    }

    private TreeNode build(int[] preorder, int[] inorder, int start, int end) {
        if (start > end) return null;

        TreeNode root = new TreeNode(preorder[preorderIndex++]);
        int mid = start;

        while (mid <= end && inorder[mid] != root.val) mid++;

        root.left = build(preorder, inorder, start, mid-1);
        root.right = build(preorder, inorder, mid+1, end);

        return root;
    }
}