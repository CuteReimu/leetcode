class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        if self.nextPermutation2(nums, 0) is not None:
            nums.sort()

    def nextPermutation2(self, nums: List[int], pos: int) -> int or None:
        if pos == len(nums) - 1:
            return nums[pos]
        max_next = self.nextPermutation2(nums, pos + 1)
        if max_next is not None:
            if nums[pos] >= max_next:
                return nums[pos]
            for j in range(len(nums)-1, -1, -1):
                if nums[j] > nums[pos]:
                    tmp = nums[j]
                    nums[j] = nums[pos]
                    nums[pos] = tmp
                    break
            self.reverse(nums, pos + 1, len(nums) - 1)

    def reverse(self, nums: List[int], i: int, j: int) -> None:
        while i < j:
            tmp = nums[i]
            nums[i] = nums[j]
            nums[j] = tmp
            i += 1
            j -= 1
