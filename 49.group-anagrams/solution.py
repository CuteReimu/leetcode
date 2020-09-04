class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dict = {}
        for s in strs:
            k = ''.join(sorted(list(s)))
            if k not in dict:
                dict[k] = [s]
            else:
                dict[k].append(s)
        return list(dict.values())
