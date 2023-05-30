/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class Solution {
    fun delNodes(root: TreeNode?, to_delete: IntArray): List<TreeNode?> {
        val toDeleteSet = to_delete.toSet()
        val roots = ArrayList<TreeNode>()

        fun dfs(node: TreeNode?, isRoot: Boolean): TreeNode? {
            if (node == null) return null
            val deleted = node.`val` in toDeleteSet
            node.left = dfs(node.left, deleted)
            node.right = dfs(node.right, deleted)
            if (deleted) {
                return null
            } else {
                if (isRoot) {
                    roots.add(node)
                }
                return node
            }
        }

        dfs(root, true)
        return roots
    }
}
