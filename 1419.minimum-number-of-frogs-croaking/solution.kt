class Solution {
    fun minNumberOfFrogs(croakOfFrogs: String): Int {
        var c = 0
        var r = 0
        var o = 0
        var a = 0
        var k = 0
        for (ch in croakOfFrogs) {
            when (ch) {
                'c' -> c++
                'r' -> {
                    if (r >= c) return -1
                    r++
                }   
                'o' -> {
                    if (o >= r) return -1
                    o++
                }
                'a' -> {
                    if (a >= o) return -1
                    a++
                }
                'k' -> {
                    if (a == 0) return -1
                    k = maxOf(c, k)
                    c--
                    r--
                    o--
                    a--
                }
            }
        }
        return if (c > 0) -1 else k
    }
}
