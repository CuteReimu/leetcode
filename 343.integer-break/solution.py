class Solution:
    def integerBreak(self, n: int) -> int:
        result = 0
        for i in range(2, n + 1):
            last = 0
            temp = 1
            for j in range(1, i + 1):
                cur = round(j * n / i)
                temp *= cur - last
                last = cur
            result = max(result, temp)
        return result
