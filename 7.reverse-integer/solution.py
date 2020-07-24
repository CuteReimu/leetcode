class Solution:
    def reverse(self, x: int) -> int:
        result = f(x) if x > 0 else -f(-x)
        return result if result < 2147483648 and result >= -2147483648 else 0

def f(x: int) -> int:
    re = 0
    while x > 0:
        re = re * 10 + x % 10
        x //= 10
    return re
