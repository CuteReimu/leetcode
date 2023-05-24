class Solution {
    fun frogPosition(n: Int, edges: Array<IntArray>, t: Int, target: Int): Double {
        val G = Array(n + 1) { ArrayList<Int>() }
        for (e in edges) {
            G[e[0]].add(e[1])
            G[e[1]].add(e[0])
        }
        val seen = BooleanArray(n + 1)

        fun dfs(i: Int, t: Int): Double {
            val nxt = if (i == 1) G[i].size else G[i].size - 1
            if (t == 0 || nxt == 0)
                return if (i == target) 1.0 else 0.0
            seen[i] = true
            var ans = 0.0
            for (j in G[i]) {
                if (!seen[j])
                    ans += dfs(j, t - 1)
            }
            return ans / nxt
        }

        return dfs(1, t)
    }
}
