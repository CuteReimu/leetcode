class Solution {
    fun maxTotalFruits(fruits: Array<IntArray>, startPos: Int, k: Int): Int {
        val n = fruits.size
        val sum = IntArray(n + 1)
        val indices = IntArray(n)

        fun lowerBound(v: Int): Int {
            var left = 0
            var right = n - 1
            var res = right + 1
            while (left <= right) {
                val mid = left + (right - left) / 2
                if (indices[mid] >= v) {
                    res = mid
                    right = mid - 1
                } else {
                    left = mid + 1
                }
            }
            return res
        }

        fun upeerBound(v: Int): Int {
            var left = 0
            var right = n - 1
            var res = right + 1
            while (left <= right) {
                val mid = left + (right - left) / 2
                if (indices[mid] > v) {
                    res = mid
                    right = mid - 1
                } else {
                    left = mid + 1
                }
            }
            return res
        }

        for (i in fruits.indices) {
            sum[i + 1] = sum[i] + fruits[i][1]
            indices[i] = fruits[i][0]
        }
        var ans = 0
        for (x in 0..(k/2)) {
            var y = k - 2 * x
            var left = startPos - x
            var right = startPos + y
            var start = lowerBound(left)
            var end = upeerBound(right)
            ans = maxOf(ans, sum[end] - sum[start])
            y = k - 2 * x
            left = startPos - y
            right = startPos + x
            start = lowerBound(left)
            end = upeerBound(right)
            ans = maxOf(ans, sum[end] - sum[start])
        }
        return ans
    }
}
