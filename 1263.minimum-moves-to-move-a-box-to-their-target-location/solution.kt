class Solution {
    fun minPushBox(grid: Array<CharArray>): Int {
        val m = grid.size
        val n = grid[0].size
        fun Array<CharArray>.contains(x: Int, y: Int): Boolean =
            x in 0 until m && y in 0 until n && this[x][y] != '#'

        var sx = -1
        var sy = -1
        var bx = -1
        var by = -1
        for (x in grid.indices) {
            for (y in grid[x].indices) {
                if (grid[x][y] == 'S') {
                    sx = x
                    sy = y
                } else if (grid[x][y] == 'B') {
                    bx = x
                    by = y
                }
            }
        }

        val d = intArrayOf(0, -1, 0, 1, 0)

        val dp = Array(m * n) { IntArray(m * n) { Int.MAX_VALUE } }
        var queue = ArrayDeque<IntArray>()
        dp[sx * n + sy][bx * n + by] = 0
        queue.addLast(intArrayOf(sx * n + sy, bx * n + by))
        while (queue.isNotEmpty()) {
            val queue1 = ArrayDeque<IntArray>()
            while (queue.isNotEmpty()) {
                val arr = queue.removeFirst()
                val s1 = arr[0]
                val b1 = arr[1]
                val sx1 = s1 / n
                val sy1 = s1 % n
                val bx1 = b1 / n
                val by1 = b1 % n
                if (grid[bx1][by1] == 'T')
                    return dp[s1][b1]
                for (i in 0 until 4) {
                    val sx2 = sx1 + d[i]
                    val sy2 = sy1 + d[i + 1]
                    val s2 = sx2 * n + sy2
                    if (!grid.contains(sx2, sy2))
                        continue
                    if (bx1 == sx2 && by1 == sy2) {
                        val bx2 = bx1 + d[i]
                        val by2 = by1 + d[i + 1]
                        val b2 = bx2 * n + by2
                        if (!grid.contains(bx2, by2) || dp[s2][b2] <= dp[s1][b1] + 1)
                            continue
                        dp[s2][b2] = dp[s1][b1] + 1
                        queue1.addLast(intArrayOf(s2, b2))
                    } else {
                        if (dp[s2][b1] <= dp[s1][b1])
                            continue
                        dp[s2][b1] = dp[s1][b1]
                        queue.addLast(intArrayOf(s2, b1))
                    }
                }
            }
            queue = queue1
        }
        return -1
    }
}
