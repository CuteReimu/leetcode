class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        result = s[0::(numRows-1)*2]
        max_len = len(s)
        for i in range(1,numRows-1):
            j1 = i
            j2 = (numRows-1)*2 - i
            while True:
                if j1 >= max_len:
                    break
                result += s[j1]
                if j2 >= max_len:
                    break
                result += s[j2]
                j1 += (numRows-1)*2
                j2 += (numRows-1)*2
        result += s[(numRows-1)::(numRows-1)*2]
        return result
