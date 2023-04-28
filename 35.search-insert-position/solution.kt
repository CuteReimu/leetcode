class Solution {
    fun searchInsert(nums: IntArray, target: Int): Int {
        var min = 0
        var max = nums.size
        var index = (min + max) / 2
        while (nums[index] != target) {
            if (nums[index] > target) {
                max = index
            } else {
                min = index + 1
            }
            if (min == max) return min
            index = (min + max) / 2
        }
        return index
    }
}
