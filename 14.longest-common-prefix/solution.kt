class Solution {
    fun longestCommonPrefix(strs: Array<String>): String {
        val sb = StringBuilder()
        var i = 0
        while (true) {
            var c: Char? = null
            for (s in strs) {
                if (i >= s.length) return sb.toString()
                if (c == null) c = s[i]
                else if (c != s[i]) return sb.toString()
            }
            sb.append(c)
            i++
        }
    }
}
