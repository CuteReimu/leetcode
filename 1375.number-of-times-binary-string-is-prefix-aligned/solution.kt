class Solution {
    fun numTimesAllBlue(flips: IntArray): Int {
        var ans = 0
        var right = 0
        for (i in flips.indices) {
            right = maxOf(right, flips[i])
            if (right == i + 1)
                ans++
        }
        return ans
    }
}
