class Solution {
    fun firstCompleteIndex(arr: IntArray, mat: Array<IntArray>): Int {
        val row = IntArray(mat.size)
        val col = IntArray(mat[0].size)
        val cache = Array<Pair<Int, Int>?>(arr.size) { null }
        for (i in mat.indices) {
            for (j in mat[i].indices) {
                cache[mat[i][j] - 1] = Pair(i, j)
            }
        }
        for (i in arr.indices) {
            val p = cache[arr[i] - 1]!!
            if (++row[p.first] == mat[0].size) return i
            if (++col[p.second] == mat.size) return i
        }
        return -1
    }
}
