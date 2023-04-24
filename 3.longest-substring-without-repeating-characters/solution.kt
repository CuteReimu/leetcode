class Solution {
    fun lengthOfLongestSubstring(s: String): Int {
        val count = IntArray(256)
        var maxLen = 0
        var i = 0
        for (j in s.indices) {
            val c = s[j].toInt()
            if (count[c]++ == 0) {
                maxLen = (j - i + 1).coerceAtLeast(maxLen)
            } else {
                var c1: Int
                do {
                    c1 = s[i++].toInt()
                    count[c1]--
                } while (c1 != c)
            }
        }
        return maxLen
    }
}
