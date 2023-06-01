class Solution {
    fun maximumTastiness(price: IntArray, k: Int): Int {
        fun check(tastiness: Int): Boolean {
            var prev = Int.MIN_VALUE / 2
            var cnt = 0
            for (p in price) {
                if (p - prev >= tastiness) {
                    cnt++
                    prev = p
                }
            }
            return cnt >= k
        }
        
        price.sort()
        var left = 0
        var right = price.last() - price.first()
        while (left < right) {
            val mid = (left + right + 1) / 2
            if (check(mid))
                left = mid
            else
                right = mid - 1
        }
        return left
    }
}
