class Solution {
    fun applyOperations(nums: IntArray): IntArray {
        for (i in 0 until nums.size - 1) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2
                nums[i + 1] = 0
            }
        }
        var i = -1
        return IntArray(nums.size) {
            while (++i < nums.size) {
                if (nums[i] != 0) return@IntArray nums[i]
            }
            0
        }
    }
}
