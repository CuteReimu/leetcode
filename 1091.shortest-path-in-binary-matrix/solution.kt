class Solution {
    fun shortestPathBinaryMatrix(grid: Array<IntArray>): Int {
        if (grid[0][0] == 1)
            return -1
        val n = grid.size
        val dist = Array(n) { IntArray(n) { Int.MAX_VALUE } }
        val queue = ArrayDeque<Pair<Int, Int>>()
        queue.offer(Pair(0, 0))
        dist[0][0] = 1
        while (queue.isNotEmpty()) {
            val arr = queue.poll()
            val x = arr.first
            val y = arr.second
            if (x == n - 1 && y == n - 1)
                return dist[x][y]
            for (dx in -1..1) {
                for (dy in -1..1) {
                    if (x + dx < 0 || x + dx >= n || y + dy < 0 || y + dy >= n)
                        continue
                    if (grid[x + dx][y + dy] == 1 || dist[x + dx][y + dy] <= dist[x][y] + 1)
                        continue
                    dist[x + dx][y + dy] = dist[x][y] + 1
                    queue.offer(Pair(x + dx, y + dy))
                }
            }
        }
        return -1
    }
}
