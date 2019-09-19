/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Result {
    int result;
    boolean found;
    Result(int result, boolean found) {
        this.result = result;
        this.found = found;
    }
}

class Solution {
    public int kthSmallest(TreeNode root, int k) {
        return find(root, k).result;
    }
    public Result find(TreeNode root, int k) {
        int K = k;
        if (root.left != null) {
            Result result = find(root.left, k);
            if (result.found) return result;
            k -= result.result;
        }
        if (k == 1) return new Result(root.val, true);
        k--;
        if (root.right != null) {
            Result result = find(root.right, k);
            if (result.found) return result;
            k -= result.result;
        }
        return new Result(K - k, false);
    }
}
