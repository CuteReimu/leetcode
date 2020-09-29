/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int diameterOfBinaryTree(TreeNode root) {
        return diameterOfBinaryTree2(root)[0];
    }

    private int[] diameterOfBinaryTree2(TreeNode root) {
        if (root == null)
            return new int[]{0, 0};
        int[] left = diameterOfBinaryTree2(root.left);
        int[] right = diameterOfBinaryTree2(root.right);
        return new int[]{Math.max(left[1] + right[1], Math.max(left[0], right[0])), Math.max(left[1], right[1]) + 1};
    }
}
