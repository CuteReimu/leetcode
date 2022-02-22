class Solution {
    fun sumOfThree(num: Long): LongArray {
        if (num % 3 != 0L) return longArrayOf()
        return longArrayOf(num/3-1, num/3, num/3+1)
    }
}
