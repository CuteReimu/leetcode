class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return '1'
        n = self.countAndSay(n - 1)
        last = '0'
        s = str(n)
        cnt = 0
        result = ''
        for i in range(len(s)):
            if s[i] == last:
                cnt += 1
            else:
                if cnt > 0:
                    result += str(cnt) + last
                cnt = 1
                last = s[i]
        return result + str(cnt) + last
