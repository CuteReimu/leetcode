import kotlin.math.abs

class Solution {
    fun maxValueAfterReverse(nums: IntArray): Int {
        var value = 0
        val n = nums.size
        for (i in 0 until n - 1) {
            value += abs(nums[i] - nums[i + 1])
        }
        var mx1 = 0
        for (i in 1 until n - 1) {
            mx1 = maxOf(mx1, abs(nums[0] - nums[i + 1]) - abs(nums[i] - nums[i + 1]))
            mx1 = maxOf(mx1, abs(nums[n - 1] - nums[i - 1]) - abs(nums[i] - nums[i - 1]))
        }
        var mx2 = Int.MIN_VALUE
        var mn2 = Int.MAX_VALUE
        for (i in 0 until n - 1) {
            val x = nums[i]
            val y = nums[i + 1]
            mx2 = maxOf(mx2, minOf(x, y))
            mn2 = minOf(mn2, maxOf(x, y))
        }
        return value + maxOf(mx1, 2 * (mx2 - mn2))
    }
}
