class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        val map = HashMap<Int, Int>()
        for ((i, num) in nums.withIndex()) {
            val j = map[target - num]
            if (j != null && i != j) return intArrayOf(i, j)
            map[num] = i
        }
        return intArrayOf()
    }
}
