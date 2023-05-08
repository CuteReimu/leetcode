class Solution {
    fun numPairsDivisibleBy60(time: IntArray): Int {
        val map = IntArray(60)
        var count = 0
        for (t in time) {
            count += map[(60 - t % 60) % 60] ?: 0
            map[t % 60]++
        }
        return count
    }
}
