class Solution:
    cache = {"2": ["a", "b", "c"], "3": ["d", "e", "f"], "4": ["g", "h", "i"], "5": ["j", "k", "l"], "6": ["m", "n", "o"], "7": ["p", "q", "r", "s"], "8": ["t", "u", "v"], "9": ["w", "x", "y", "z"]}
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0:
            return []
        if len(digits) == 1:
            return Solution.cache[digits]
        list0 = self.letterCombinations(digits[0])
        list1 = self.letterCombinations(digits[1:])
        result = []
        for s0 in list0:
            for s1 in list1:
                result.append(s0 + s1)
        return result
