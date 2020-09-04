class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if len(nums) == 1:
            return True
        j = 0
        for i in range(len(nums)):
            if j >= len(nums) - 1:
                return True
            if i > j:
                return False
            j = max(j, i + nums[i])
