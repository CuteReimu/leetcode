class Solution {
    fun distinctAverages(nums: IntArray): Int {
        val set = HashSet<Int>()
        nums.sort()
        var i = 0
        var j = nums.size - 1
        while (i < j) {
            set.add(nums[i] + nums[j])
            i++
            j--
        }
        return set.size
    }
}
