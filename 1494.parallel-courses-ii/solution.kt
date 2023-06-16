class Solution {
    fun minNumberOfSemesters(n: Int, relations: Array<IntArray>, k: Int): Int {
        val dp = IntArray(1 shl n) { Int.MAX_VALUE }
        val need = IntArray(1 shl n)
        for (edge in relations) {
            need[1 shl edge[1] - 1] = need[1 shl edge[1] - 1] or (1 shl edge[0] - 1)
        }
        dp[0] = 0
        for (i in 1 until (1 shl n)) {
            need[i] = need[i and i - 1] or need[i and -i]
            if (need[i] or i != i)
                continue
            val valid = i xor need[i]
            if (Integer.bitCount(valid) <= k) {
                dp[i] = minOf(dp[i], dp[i xor valid] + 1)
            } else {
                var sub = valid
                while (sub > 0) {
                    if (Integer.bitCount(sub) <= k)
                        dp[i] = minOf(dp[i], dp[i xor sub] + 1)
                    sub = sub - 1 and valid
                }
            }
        }
        return dp[(1 shl n) - 1]
    }
}
