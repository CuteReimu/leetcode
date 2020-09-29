/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int DiameterOfBinaryTree(TreeNode root) {
        return DiameterOfBinaryTree2(root)[0];
    }

    private int[] DiameterOfBinaryTree2(TreeNode root) {
        if (root == null)
            return new int[]{0, 0};
        int[] left = DiameterOfBinaryTree2(root.left);
        int[] right = DiameterOfBinaryTree2(root.right);
        return new int[]{Math.Max(left[1] + right[1], Math.Max(left[0], right[0])), Math.Max(left[1], right[1]) + 1};
    }
}
