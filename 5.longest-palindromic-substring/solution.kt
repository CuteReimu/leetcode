class Solution {
    fun longestPalindrome(s: String): String {
        var longestString = s.substring(0, 1)
        val s2 = s.toCharArray().joinToString(separator = "#")
        var r = 0
        for (i in s2.indices) {
            var r1 = 1
            while (true) {
                if (i - r1 < 0) break
                if (i + r1 >= s2.length) break
                if (s2[i - r1] != s2[i + r1]) break
                if (r1 > r) {
                    r = r1
                    longestString = s2.substring(i - r1, i + r1 + 1)
                } else if (r1 == r && s2[i - r1] != '#' && longestString[0] == '#') {
                    longestString = s2.substring(i - r1, i + r1 + 1)
                }
                r1++
            }
        }
        return longestString.replace("#", "")
    }
}
