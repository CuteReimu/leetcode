class Solution {
    fun modifiedGraphEdges(
        n: Int,
        edges: Array<IntArray>,
        source: Int,
        destination: Int,
        target: Int
    ): Array<IntArray> {
        fun dijkstra(adjMatrix: Array<IntArray>): Long {
            val dist = LongArray(adjMatrix.size) { (Int.MAX_VALUE / 2).toLong() }
            val used = BooleanArray(adjMatrix.size)
            dist[source] = 0
            for (round in 0 until adjMatrix.size - 1) {
                var u = -1
                for (i in adjMatrix.indices) {
                    if (!used[i] && (u == -1 || dist[i] < dist[u])) {
                        u = i
                    }
                }
                used[u] = true
                for (v in adjMatrix.indices) {
                    if (!used[v] && adjMatrix[u][v] != -1) {
                        dist[v] = minOf(dist[v], dist[u] + adjMatrix[u][v])
                    }
                }
            }
            return dist[destination]
        }

        fun construct(idx: Long): Array<IntArray> {
            var idx = idx
            val adjMatrix = Array(n) { IntArray(n) { -1 } }
            for (e in edges) {
                val u = e[0]
                val v = e[1]
                val w = e[2]
                if (w != -1) {
                    adjMatrix[v][u] = w
                    adjMatrix[u][v] = adjMatrix[v][u]
                } else {
                    if (idx >= target - 1) {
                        adjMatrix[v][u] = target
                        adjMatrix[u][v] = adjMatrix[v][u]
                        idx -= (target - 1).toLong()
                    } else {
                        adjMatrix[v][u] = (1 + idx).toInt()
                        adjMatrix[u][v] = adjMatrix[v][u]
                        idx = 0
                    }
                }
            }
            return adjMatrix
        }

        val k = edges.count { it[2] == -1 }
        if (dijkstra(construct(0)) > target) {
            return arrayOf()
        }
        if (dijkstra(construct(k.toLong() * (target - 1))) < target) {
            return arrayOf()
        }
        var left = 0L
        var right = k.toLong() * (target - 1)
        var ans = 0L
        while (left <= right) {
            val mid = (left + right) / 2
            if (dijkstra(construct(mid)) >= target) {
                ans = mid
                right = mid - 1
            } else {
                left = mid + 1
            }
        }
        for (e in edges) {
            if (e[2] == -1) {
                if (ans >= target - 1) {
                    e[2] = target
                    ans -= (target - 1).toLong()
                } else {
                    e[2] = (1 + ans).toInt()
                    ans = 0
                }
            }
        }
        return edges
    }
}
