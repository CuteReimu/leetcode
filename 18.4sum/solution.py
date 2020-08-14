class Solution:
    def fourSum(self, nums: List[int], target) -> List[tuple]:
        cache = {}
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                sum_i_j = nums[i] + nums[j]
                if sum_i_j not in cache:
                    cache[sum_i_j] = [(i, j)]
                else:
                    cache[sum_i_j].append((i, j))
        result = set()
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                kval = target-nums[i]-nums[j]
                tmp = cache.get(kval)
                if tmp is not None:
                    for t in tmp:
                        if t[0] != i and t[1] != j and t[0] != j and t[1] != i:
                            result.add(tuple(sorted([nums[i], nums[j], nums[t[0]], nums[t[1]]])))
        return list(result)
