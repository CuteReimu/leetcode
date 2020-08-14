class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        nearest = 100000
        for i in range(len(nums)):
            target2 = target - nums[i]
            j = 0
            k = len(nums) - 1
            if j == i:
                j += 1
            if k == i:
                k -= 1
            nearest2 = 100000
            while j < k:
                sum2 = nums[j] + nums[k]
                if sum2 == target2:
                    return target
                if abs(sum2 - target2) < abs(nearest2 - target2):
                    nearest2 = sum2
                if sum2 < target2:
                    j += 1
                    if j == i:
                        j += 1
                else:
                    k -= 1
                    if k == i:
                        k -= 1
            if abs(nearest2 + nums[i] - target) < abs(nearest - target):
                nearest = nearest2 + nums[i]
        return nearest
