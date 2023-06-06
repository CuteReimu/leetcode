class Solution {
    fun threeSum(nums: IntArray): List<List<Int>> {
        nums.sort()
        val ans = ArrayList<List<Int>>()
        for (first in nums.indices) {
            if (first > 0 && nums[first] == nums[first - 1])
                continue
            var third = nums.size - 1
            val target = -nums[first]
            for (second in first + 1 until nums.size) {
                if (second > first + 1 && nums[second] == nums[second - 1])
                    continue
                while (second < third && nums[second] + nums[third] > target)
                    third--
                if (second == third)
                    break
                if (nums[second] + nums[third] == target)
                    ans.add(listOf(nums[first], nums[second], nums[third]))
            }
        }
        return ans
    }
}
