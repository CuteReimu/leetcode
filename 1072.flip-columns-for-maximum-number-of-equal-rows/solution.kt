class Solution {
    fun maxEqualRowsAfterFlips(matrix: Array<IntArray>): Int {
        val set = HashMap<intArray, Int>()
        for (a in matrix) {
            if (a[0] != 0)
                for (i in a.indices)
                    a[i] = 1 - a[i]
            set.compute(intArray(a)) { _, v -> (v ?: 0) + 1 }
        }
        var max = 0
        for (count in set.values)
            max = maxOf(max, count)
        return max
    }

    private class intArray(private val a: IntArray) {
        private val hash: Int

        init {
            var hash = 0
            for (i in a)
                hash = hash shl 1 or i
            this.hash = hash
        }

        override fun hashCode(): Int {
            return hash
        }

        override fun equals(other: Any?): Boolean {
            if (other !is intArray) return false
            return other.a.contentEquals(a)
        }
    }
}
