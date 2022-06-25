class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i in range(len(nums)):
            d[nums[i]] = i
        for i in range(len(nums)):
            expect_num = target - nums[i]
            if expect_num in d and i != d[expect_num]:
                return [i, d[expect_num]]
