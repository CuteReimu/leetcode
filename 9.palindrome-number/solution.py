class Solution:
    def isPalindrome(self, x: int) -> bool:
        return x >= 0 and x == self.reverse(x)

    def reverse(self, x: int) -> int:
        y = 0
        while x > 0:
            y = y * 10 + x % 10
            x //= 10
        return y
