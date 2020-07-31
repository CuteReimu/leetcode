class Solution:
    def findMagicIndex(self, nums: List[int]) -> int:
        i = 0
        max_len = len(nums)
        while i < max_len:
            val = nums[i]
            if val == i:
                return i
            elif val > i:
                i = val
            else:
                i += 1
        return -1
