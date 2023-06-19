class Solution {
    fun numberOfCuts(n: Int): Int {
        return if (n % 2 == 0) n / 2 else if (n == 1) 0 else n
    }
}
