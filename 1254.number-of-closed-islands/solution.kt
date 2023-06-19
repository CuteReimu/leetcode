class Solution {
    fun closedIsland(grid: Array<IntArray>): Int {
        val m = grid.size
        val n = grid[0].size
        val uf = UnionFind(m * n)
        for (i in grid.indices) {
            if (grid[i][0] == 0) {
                uf.uni(i * n, 0)
            }
            if (grid[i][n - 1] == 0) {
                uf.uni(i * n + n - 1, 0)
            }
        }
        for (j in 1 until n - 1) {
            if (grid[0][j] == 0) {
                uf.uni(j, 0)
            }
            if (grid[m - 1][j] == 0) {
                uf.uni((m - 1) * n + j, 0)
            }
        }
        for (i in grid.indices) {
            for (j in grid[0].indices) {
                if (grid[i][j] == 0) {
                    if (i > 0 && grid[i - 1][j] == 0) {
                        uf.uni(i * n + j, (i - 1) * n + j)
                    }
                    if (j > 0 && grid[i][j - 1] == 0) {
                        uf.uni(i * n + j, i * n + j - 1)
                    }
                }
            }
        }
        val cnt = HashSet<Int>()
        for (i in grid.indices) {
            for (j in grid[0].indices) {
                if (grid[i][j] == 0) {
                    cnt.add(uf.find(i * n + j))
                }
            }
        }
        var total = cnt.size
        if (cnt.contains(uf.find(0))) {
            total--
        }
        return total
    }


    private class UnionFind(n: Int) {
        private val parent = IntArray(n) { it }
        private val rank = IntArray(n)

        fun uni(x: Int, y: Int) {
            val rootx = find(x)
            val rooty = find(y)
            if (rootx != rooty) {
                if (rank[rootx] > rank[rooty]) {
                    parent[rooty] = rootx
                } else if (rank[rootx] < rank[rooty]) {
                    parent[rootx] = rooty
                } else {
                    parent[rooty] = rootx
                    rank[rootx]++
                }
            }
        }

        fun find(x: Int): Int {
            if (parent[x] != x) {
                parent[x] = find(parent[x])
            }
            return parent[x]
        }
    }
}
