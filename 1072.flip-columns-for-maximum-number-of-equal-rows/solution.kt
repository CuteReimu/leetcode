class Solution {
    fun maxEqualRowsAfterFlips(matrix: Array<IntArray>): Int {
        val set = HashMap<String, Int>()
        for (a in matrix) {
            if (a[0] != 0)
                for (i in a.indices)
                    a[i] = 1 - a[i]
            val ch = ByteArray(a.size) { i -> (48 + a[i]).toByte() }
            set.compute(String(ch)) { _, v -> (v ?: 0) + 1 }
        }
        var max = 0
        for (count in set.values)
            max = maxOf(max, count)
        return max
    }
}
