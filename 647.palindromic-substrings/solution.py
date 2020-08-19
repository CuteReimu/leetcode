class Solution:
    def countSubstrings(self, s: str) -> int:
        result = 0
        for i in range(len(s)):
            j = 0
            while True:
                if i + j >= len(s) or i - j < 0 or s[i + j] != s[i - j]:
                    break
                result += 1
                j += 1
        for i in range(len(s) - 1):
            j = 0
            while True:
                if i + j + 1 >= len(s) or i - j < 0 or s[i + j + 1] != s[i - j]:
                    break
                result += 1
                j += 1
        return result
