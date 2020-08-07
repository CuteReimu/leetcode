class Solution:
    def threeSum(self, nums0: List[int]) -> List[List[int]]:
        cache = {}
        nums = []
        for i in nums0:
            tmp = cache.get(i)
            if i not in cache:
                cache[i] = 1
            else:
                cache[i] += 1
            if cache[i] < 3:
                nums.append(i)
        result = set()
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                kval = -nums[i]-nums[j]
                tmp = cache.get(kval)
                if tmp is not None:
                    if nums[i] == kval and nums[j] == kval:
                        if tmp >= 3:
                            result.add(tuple(sorted([nums[i], nums[j], kval])))
                    elif nums[i] == kval or nums[j] == kval:
                        if tmp >= 2:
                            result.add(tuple(sorted([nums[i], nums[j], kval])))
                    else:
                        result.add(tuple(sorted([nums[i], nums[j], kval])))
        return list(result)
