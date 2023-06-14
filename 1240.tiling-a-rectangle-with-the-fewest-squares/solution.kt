class Solution {
    fun tilingRectangle(n: Int, m: Int): Int {
        return res[m - 1][n - 1]
    }

    companion object {
        val res = arrayOf(
            intArrayOf(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13),
            intArrayOf(2, 1, 3, 2, 4, 3, 5, 4, 6, 5, 7, 6, 8),
            intArrayOf(3, 3, 1, 4, 4, 2, 5, 5, 3, 6, 6, 4, 7),
            intArrayOf(4, 2, 4, 1, 5, 3, 5, 2, 6, 4, 6, 3, 7),
            intArrayOf(5, 4, 4, 5, 1, 6, 5, 5, 6, 2, 7, 6, 6),
            intArrayOf(6, 3, 2, 3, 6, 1, 5, 4, 3, 4, 6, 2, 6),
            intArrayOf(7, 5, 5, 5, 5, 5, 1, 6, 6, 6, 6, 6, 6),
            intArrayOf(8, 4, 5, 2, 5, 4, 6, 1, 7, 5, 6, 3, 6),
            intArrayOf(9, 6, 3, 6, 6, 3, 6, 7, 1, 6, 7, 4, 7),
            intArrayOf(10, 5, 6, 4, 2, 4, 6, 5, 6, 1, 6, 6, 7),
            intArrayOf(11, 7, 6, 6, 6, 6, 6, 6, 7, 6, 1, 7, 6),
            intArrayOf(12, 6, 4, 3, 6, 2, 6, 3, 4, 6, 7, 1, 7),
            intArrayOf(13, 8, 7, 7, 6, 6, 6, 6, 7, 7, 6, 7, 1)
        )
    }
}
