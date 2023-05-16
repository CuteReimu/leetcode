class Solution {
    fun findMaxK(nums: IntArray): Int {
        val map = HashSet<Int>()
        var max = -1
        nums.forEach {
            if (map.contains(-it)) {
                max = Math.max(max, Math.abs(it))
            }
            map.add(it)
        }
        return max
    }
}
