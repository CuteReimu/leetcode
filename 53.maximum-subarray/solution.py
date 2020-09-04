class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sums = [0] * len(nums)
        sums[0] = nums[0]
        for i in range(1, len(nums)):
            if sums[i - 1] < 0:
                sums[i] = nums[i]
            else:
                sums[i] = sums[i - 1] + nums[i]
        return max(sums)
