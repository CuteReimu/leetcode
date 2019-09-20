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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        Queue<TreeNode> queue = new LinkedList<>();
        Map<TreeNode, TreeNode> parentMap = new HashMap<>();
        queue.offer(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node.left != null) {
                queue.offer(node.left);
                parentMap.put(node.left, node);
            }
            if (node.right != null) {
                queue.offer(node.right);
                parentMap.put(node.right, node);
            }
        }
        Set<TreeNode> set = new HashSet<>();
        while (p != null) {
            set.add(p);
            p = parentMap.get(p);
        }
        while (q != null) {
            if (set.contains(q)) return q;
            q = parentMap.get(q);
        }
        return null;
    }
}
