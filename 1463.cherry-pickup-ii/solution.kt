class Solution {
    fun cherryPickup(grid: Array<IntArray>): Int {
        val m = grid.size
        val n = grid[0].size
        var f = Array(n){IntArray(n){-1}}
        var g = Array(n){IntArray(n){-1}}
        f[0][n-1] = grid[0][0] + grid[0][n-1]
        for (i in 1 until m) {
            for (j1 in 0 until n) {
                for (j2 in 0 until n) {
                    g[j1][j2] = (j1-1..j1+1).maxOf { dj1 ->
                        (j2-1..j2+1).maxOf { dj2 ->
                            if (dj1 !in 0 until n || dj2 !in 0 until n) -1
                            else if (f[dj1][dj2] == -1) -1
                            else {
                                f[dj1][dj2] + if(j1 == j2) grid[i][j1] else grid[i][j1] + grid[i][j2]
                            }
                        }
                    }
                }
            }
            val temp = f
            f = g
            g = temp
        }

        return (0 until n).maxOf { j1 ->
            (0 until n).maxOf { j2 -> f[j1][j2] }
        }
    }
}
