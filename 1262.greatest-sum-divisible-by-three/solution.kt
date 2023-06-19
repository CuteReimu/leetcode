class Solution {
    fun maxSumDivThree(nums: IntArray): Int {
        val rem1 = ArrayList<Int>()
        val rem2 = ArrayList<Int>()
        for (num in nums) {
            when (num % 3) {
                1 -> rem1.add(num)
                2 -> rem2.add(num)
            }
        }
        rem1.sort()
        rem2.sort()
        val sum = nums.sum()
        return when (sum % 3) {
            0 -> sum
            1 -> {
                var m = 0
                if (rem1.size >= 1) m = maxOf(m, sum - rem1[0])
                if (rem2.size >= 2) m = maxOf(m, sum - rem2[0] - rem2[1])
                m
            }
            2 -> {
                var m = 0
                if (rem2.size >= 1) m = maxOf(m, sum - rem2[0])
                if (rem1.size >= 2) m = maxOf(m, sum - rem1[0] - rem1[1])
                m
            }
            else -> 0
        }
    }
}
