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
    fun sufficientSubset(root: TreeNode?, limit: Int): TreeNode? {
        fun checkSufficientLeaf(node: TreeNode?, sum: Int, limit: Int): Boolean {
            if (node == null) return false
            if (node.left == null && node.right == null) return node.`val` + sum >= limit
            val haveSufficientLeft = checkSufficientLeaf(node.left, sum + node.`val`, limit)
            val haveSufficientRight = checkSufficientLeaf(node.right, sum + node.`val`, limit)
            if (!haveSufficientLeft) node.left = null
            if (!haveSufficientRight) node.right = null
            return haveSufficientLeft || haveSufficientRight
        }

        return if(checkSufficientLeaf(root, 0, limit)) root else null
    }
}
