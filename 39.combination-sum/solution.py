class Solution:
    def __init__(self):
        self.dict = {}

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        return self.combinationSum2(candidates, target)

    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        if target in self.dict:
            return self.dict[target]
        result = []
        for i in range(len(candidates) - 1, -1, -1):
            if candidates[i] < target:
                resulti = self.combinationSum(candidates, target - candidates[i])
                for l in resulti:
                    if l[len(l) - 1] > candidates[i]:
                        continue
                    l2 = l.copy()
                    l2.append(candidates[i])
                    result.append(l2)
            elif candidates[i] == target:
                result.append([target])
        self.dict[target] = result
        return result
