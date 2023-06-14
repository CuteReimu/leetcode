class Solution {
    fun unequalTriplets(nums: IntArray): Int {
        var count = 0
        for (i in 0 until nums.size-2) {
            for (j in i+1 until nums.size-1) {
                for (k in j+1 until nums.size) {
                    if (nums[i] != nums[j] && nums[i] != nums[k] && nums[j] != nums[k]) {
                        count++
                    }
                }
            }
        }
        return count
    }
}
