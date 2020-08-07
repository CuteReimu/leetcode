class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        i = 0
        j = 0
        while True:
            if i == len(p):
                return j == len(s)
            elif i > len(p):
                return False
            if i + 1 < len(p) and p[i + 1] == '*':
                jj = j
                while jj < len(s) and (p[i] == '.' or s[jj] == p[i]):
                    if self.isMatch(s[jj+1:], p[i+2:]):
                        return True
                    jj += 1
                i += 2
            else:
                if j >= len(s):
                    return False
                if p[i] != '.' and p[i] != s[j]:
                    return False
                i += 1
                j += 1
