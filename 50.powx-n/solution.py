class Solution:
    def __init__(self):
        self.cache = {}

    def myPow(self, x: float, n: int) -> float:
        if n == 1:
            return x
        if n == 0:
            return 1
        if n == -1:
            return 1 / x
        if n in self.cache:
            return self.cache[n]
        p = self.myPow(x, n // 2) * self.myPow(x, n - n // 2)
        self.cache[n] = p
        return p
