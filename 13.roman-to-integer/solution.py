class Solution:
    def romanToInt(self, s: str) -> int:
        result = 0
        i = 0
        while i < len(s):
            if i+1 < len(s):
                if s[i:i+2] == 'IV':
                    result += 4
                    i += 2
                    continue
                elif s[i:i+2] == 'IX':
                    result += 9
                    i += 2
                    continue
                elif s[i:i+2] == 'XL':
                    result += 40
                    i += 2
                    continue
                elif s[i:i+2] == 'XC':
                    result += 90
                    i += 2
                    continue
                elif s[i:i+2] == 'CD':
                    result += 400
                    i += 2
                    continue
                elif s[i:i+2] == 'CM':
                    result += 900
                    i += 2
                    continue
            if s[i] == 'I':
                result += 1
            elif s[i] == 'V':
                result += 5
            elif s[i] == 'X':
                result += 10
            elif s[i] == 'L':
                result += 50
            elif s[i] == 'C':
                result += 100
            elif s[i] == 'D':
                result += 500
            elif s[i] == 'M':
                result += 1000
            i += 1
        return result
