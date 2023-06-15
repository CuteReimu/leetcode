class Solution {
    fun numSmallerByFrequency(queries: Array<String>, words: Array<String>): IntArray {
        fun String.f(): Int {
            var cnt = 0
            var ch = 'z'
            for (c in this) {
                if (c < ch) {
                    ch = c
                    cnt = 1
                } else if (c == ch) {
                    cnt++
                }
            }
            return cnt
        }

        val count = IntArray(12)
        for (s in words) {
            count[s.f()]++
        }
        for (i in 9 downTo 1) {
            count[i] += count[i + 1]
        }
        return IntArray(queries.size) {
            count[queries[it].f() + 1]
        }
    }
}
