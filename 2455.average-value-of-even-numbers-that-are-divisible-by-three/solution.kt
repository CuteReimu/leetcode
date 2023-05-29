class Solution {
    fun averageValue(nums: IntArray): Int {
        return nums.filter { it % 6 == 0 }.run {
            if (size == 0) return 0
            else sum() / size
        }
    }
}
