class Solution {
    fun minDifficulty(jobDifficulty: IntArray, d: Int): Int {
        val n = jobDifficulty.size
        if (n < d)
            return -1
        val dp = Array(d + 1) { IntArray(n) { 0x3f3f3f3f } }
        var ma = 0
        for (i in 0 until n) {
            ma = maxOf(ma, jobDifficulty[i])
            dp[0][i] = ma
        }
        for (i in 1 until d) {
            for (j in i until n) {
                ma = 0
                for (k in j downTo i) {
                    ma = maxOf(ma, jobDifficulty[k])
                    dp[i][j] = minOf(dp[i][j], ma + dp[i - 1][k - 1])
                }
            }
        }
        return dp[d - 1][n - 1]
    }
}
