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
    public List<String> binaryTreePaths(TreeNode root) {
        if (root == null) return Collections.emptyList();
        List<String> list = new ArrayList<String>();
        binaryTreePaths("", root, list);
        return list;
    }
    
    public void binaryTreePaths(String s, TreeNode root, List<String> list) {
        if (!s.isEmpty()) {
            s += "->";
        }
        s += root.val;
        if (root.left == null && root.right == null) list.add(s);
        if (root.left != null) binaryTreePaths(s, root.left, list);
        if (root.right != null) binaryTreePaths(s, root.right, list);
    }
}
