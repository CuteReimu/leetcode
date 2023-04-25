class Solution {
    fun convert(s: String, numRows: Int): String {
        if (numRows == 1) return s
        val m = Array(numRows) { CharArray(s.length) }
        var up = false
        var i = 0
        var j = 0
        for (c in s) {
            m[i][j] = c
            if (!up) {
                if (++i == numRows - 1)
                    up = true
            } else {
                j++
                if (--i == 0)
                    up = false
            }
        }
        val sb = StringBuilder()
        for (n in m) {
            for (k in n) {
                if (k != '\u0000') sb.append(k)
            }
        }
        return sb.toString()
    }
}
