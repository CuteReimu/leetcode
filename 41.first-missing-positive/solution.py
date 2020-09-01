class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            while True:
                if nums[i] <= 0 or nums[i] > len(nums) or nums[i] - 1 == i or nums[i] == nums[nums[i] - 1]:
                    break
                tmp = nums[nums[i] - 1]
                nums[nums[i] - 1] = nums[i]
                nums[i] = tmp
        for i in range(len(nums)):
            if i != nums[i] - 1:
                return i + 1
        return len(nums) + 1
