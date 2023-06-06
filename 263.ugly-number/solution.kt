class Solution {
    fun isUgly(n: Int): Boolean {
        var n = n
        while (true) {
            n /= when {
                n <= 0 -> return false
                n == 1 -> return true
                n % 2 == 0 -> 2
                n % 3 == 0 -> 3
                n % 5 == 0 -> 5
                else -> return false
            }
        }
    }
}
