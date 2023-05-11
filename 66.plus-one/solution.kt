class Solution {
    fun plusOne(digits: IntArray): IntArray {
        for (i in (digits.size-1) downTo 0) {
            if (++digits[i] == 10)
                digits[i] = 0
            else
                break
        }
        if (digits[0] == 0) return intArrayOf(1) + digits
        return digits
    }
}
