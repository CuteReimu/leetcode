class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        cache = {}
        for i in range(len(nums)):
            tmp = cache.get(nums[i])
            if cache.get(nums[i]) == None:
                tmp = []
                cache[nums[i]] = tmp
            tmp.append(i)
        for i in range(len(nums)):
            for j in cache.get(target - nums[i], []):
                if i != j:
                    return [i, j]
        return []
