class Solution {
    fun queryString(s: String, n: Int): Boolean {
        fun help(s: String, k: Int, mi: Int, ma: Int): Boolean {
            val set = HashSet<Int>()
            var t = 0
            for (r in s.indices) {
                t = t * 2 + (s[r] - '0')
                if (r >= k) {
                    t -= (s[r - k] - '0') shl k
                }
                if (r >= k - 1 && t >= mi && t <= ma) {
                    set.add(t)
                }
            }
            return set.size == ma - mi + 1
        }

        if (n == 1) {
            return '1' in s
        }
        var k = 30;
        while ((1 shl k) >= n) {
            --k
        }
        if (s.length < (1 shl (k - 1)) + k - 1 || s.length < n - (1 shl k) + k + 1) {
            return false
        }
        return help(s, k, 1 shl (k - 1), (1 shl k) - 1) && help(s, k + 1, 1 shl k, n)
    }
}
