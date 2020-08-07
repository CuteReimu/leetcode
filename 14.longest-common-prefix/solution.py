class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        result = ""
        i = 0
        while True:
            if i >= len(strs[0]):
                break
            j = 1
            while j < len(strs):
                if i >= len(strs[j]) or strs[j][i] != strs[0][i]:
                    return result
                j += 1
            result += strs[0][i]
            i += 1
        return result
