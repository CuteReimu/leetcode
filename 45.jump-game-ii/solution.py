class Solution:
    def jump(self, nums: List[int]) -> int:
        l = [0] * len(nums)
        k = 1
        for i in range(len(nums) - 1):
            for j in range(max(i + 1, k), min(i + nums[i] + 1, len(nums))):
                l[j] = l[i] + 1
                k = j + 1
        return l[len(nums) - 1]
