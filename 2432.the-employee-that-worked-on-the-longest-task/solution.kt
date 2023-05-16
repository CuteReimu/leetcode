class Solution {
    fun hardestWorker(n: Int, logs: Array<IntArray>): Int {
        var ans = logs[0][0]
        var maxcost = logs[0][1]
        for (i in 1 until logs.size) {
            val idx = logs[i][0]
            val cost = logs[i][1] - logs[i - 1][1]
            if (cost > maxcost || (cost == maxcost && idx < ans)) {
                ans = idx
                maxcost = cost
            }
        }
        return ans
    }
}
