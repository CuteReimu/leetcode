class Solution {
    fun numTilePossibilities(tiles: String): Int {
        val m = HashMap<Char, Int>()
        for (c in tiles)
            m.compute(c) { _, v -> (v ?: 0) + 1 }
        val tile = m.keys

        fun dfs(i: Int): Int {
            if (i == 0) return 1
            var res = 1
            for (t in tile) {
                if (m[t]!! > 0) {
                    m.computeIfPresent(t) { _, v -> v - 1 }
                    res += dfs(i - 1)
                    m.computeIfPresent(t) { _, v -> v + 1 }
                }
            }
            return res
        }

        return dfs(tiles.length) - 1
    }
}
