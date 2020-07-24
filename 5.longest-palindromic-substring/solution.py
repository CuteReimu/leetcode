class Solution:
    def longestPalindrome(self, s: str) -> str:
        ss = "#" + "#".join(list(s)) + "#"
        max_len = 0
        val = ""
        for i in range(len(ss)):
            j = 1
            while i - j >= 0 and i + j < len(ss) and ss[i - j] == ss[i + j]:
                j += 1
            if max_len < j - 1:
                max_len = j - 1
                val = ss[i - j + 1:i + j]
        return val.replace("#", "")
