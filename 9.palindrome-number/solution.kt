class Solution {
    fun isPalindrome(x: Int): Boolean {
        return x.toString().run { this == reversed() }
    }
}
