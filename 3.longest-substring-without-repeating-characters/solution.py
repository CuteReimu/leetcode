class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        count = {}
        start = 0
        max_len = 0
        for i in range(len(s)):
            c = count.get(s[i])
            if c is None or c == 0:
                count[s[i]] = 1
                if i - start + 1 > max_len:
                    max_len = i - start + 1
            else:
                count[s[i]] += 1
                while True:
                    ch = s[start]
                    count[ch] -= 1
                    start += 1
                    if ch == s[i]:
                        break
        return max_len
