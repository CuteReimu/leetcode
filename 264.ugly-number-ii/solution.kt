class Solution {
    fun nthUglyNumber(n: Int): Int {
        val dp = IntArray(n + 1)
        dp[1] = 1
        var p2 = 1
        var p3 = 1
        var p5 = 1
        for (i in 2..n) {
            val num2 = dp[p2] * 2
            val num3 = dp[p3] * 3
            val num5 = dp[p5] * 5
            dp[i] = minOf(num2, num3, num5)
            if (dp[i] == num2) p2++
            if (dp[i] == num3) p3++
            if (dp[i] == num5) p5++
        }
        return dp[n]
    }
}
