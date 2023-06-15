class TreeAncestor(n: Int, parent: IntArray) {
    private var ancestors: Array<IntArray>

    init {
        ancestors = Array(n) { IntArray(LOG) { -1 } }
        for (i in 0 until n) {
            ancestors[i][0] = parent[i]
        }
        for (j in 1 until LOG) {
            for (i in 0 until n) {
                if (ancestors[i][j - 1] != -1) {
                    ancestors[i][j] = ancestors[ancestors[i][j - 1]][j - 1]
                }
            }
        }
    }

    fun getKthAncestor(node: Int, k: Int): Int {
        var node = node
        for (j in 0 until LOG) {
            if (k shr j and 1 != 0) {
                node = ancestors[node][j]
                if (node == -1) {
                    return -1
                }
            }
        }
        return node
    }

    companion object {
        const val LOG = 16
    }
}


/**
 * Your TreeAncestor object will be instantiated and called as such:
 * var obj = TreeAncestor(n, parent)
 * var param_1 = obj.getKthAncestor(node,k)
 */
