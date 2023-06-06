class Solution {
    fun equalPairs(grid: Array<IntArray>): Int {
        val random = kotlin.random.Random(1)
        val r = IntArray(grid.size) { random.nextInt() }
        var count = 0
        val cache = HashMap<Int, Int>()
        grid.indices.forEach { i ->
            var hash = 0
            grid.indices.forEach { j -> hash += grid[i][j] * r[j] }
            cache.compute(hash) { _, v -> (v ?: 0) + 1 }
        }
        grid.indices.forEach { i ->
            var hash = 0
            grid.indices.forEach { j -> hash += grid[j][i] * r[j] }
            count += cache[hash] ?: 0
        }
        return count
    }
}
