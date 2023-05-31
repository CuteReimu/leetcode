import kotlin.math.max
import kotlin.math.min
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
    class SubTree(val isBST: Boolean, val minValue: Int, val maxValue: Int, val sumValue: Int)

    fun maxSumBST(root: TreeNode?): Int {
        var res = 0
        fun dfs(root: TreeNode?): SubTree {
            if (root == null)
                return SubTree(true, INF, -INF, 0)
            val left = dfs(root.left)
            val right = dfs(root.right)
            return if (left.isBST && right.isBST && root.`val` > left.maxValue && root.`val` < right.minValue) {
                val sum = root.`val` + left.sumValue + right.sumValue
                res = max(res, sum)
                SubTree(true, min(left.minValue, root.`val`), max(root.`val`, right.maxValue), sum)
            } else {
                SubTree(false, 0, 0, 0)
            }
        }
        dfs(root)
        return res
    }

    companion object {
        const val INF = 0x3f3f3f3f
    }
}
