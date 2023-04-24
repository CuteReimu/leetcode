import kotlin.math.max

class Solution {
    fun lastSubstring(s: String): String {
        var i = 0
        var j = 1
        while (j < s.length) {
            val k = ((j until s.length).find { s[i + it - j] != s[it] } ?: s.length) - j
            if (j + k < s.length && s[i + k] < s[j + k]) {
                val t = i
                i = j
                j = max(j + 1, t + k + 1)
            } else {
                j += k + 1
            }
        }
        return s.substring(i)
    }
}
