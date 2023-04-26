class Solution {
    fun removeDuplicates(nums: IntArray): Int {
        var j = 0
        for (i in (1 until nums.size)) {
            if (nums[i] != nums[j]) nums[++j] = nums[i]
        }
        return j + 1
    }
}
