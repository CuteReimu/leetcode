import kotlin.math.min

class Solution {
    fun kthSmallest(mat: Array<IntArray>, k: Int): Int {
        val m = mat.size
        var prev = mat[0]
        for (i in 1 until m) {
            prev = merge(prev, mat[i], k)
        }
        return prev[k - 1]
    }

    private fun merge(f: IntArray, g: IntArray, k: Int): IntArray {
        var k = k
        var left = f.first() + g.first()
        var right = f.last() + g.last()
        var thres = 0
        k = min(k, f.size * g.size)
        while (left <= right) {
            val mid = (left + right) / 2
            var rptr = g.size - 1
            var cnt = 0
            for (i in f) {
                while (rptr >= 0 && i + g[rptr] > mid) {
                    --rptr
                }
                cnt += rptr + 1
            }
            if (cnt >= k) {
                thres = mid
                right = mid - 1
            } else {
                left = mid + 1
            }
        }
        val list = ArrayList<Int>()
        for (j in f) {
            for (value in g) {
                val sum = j + value
                if (sum < thres) {
                    list.add(sum)
                } else {
                    break
                }
            }
        }
        while (list.size < k) {
            list.add(thres)
        }
        list.sort()
        return list.toIntArray()
    }
}
