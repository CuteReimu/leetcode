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
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        List<Integer> list = new ArrayList<>();
        treeToList(list, root1);
        treeToList(list, root2);
        Collections.sort(list);
        return list;
    }
    
    private void treeToList(List<Integer> list, TreeNode root) {
        if (root == null) return;
        list.add(root.val);
        treeToList(list, root.left);
        treeToList(list, root.right);
    }
}
