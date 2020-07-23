class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) < len(nums2):
            tmp = nums1
            nums1 = nums2
            nums2 = tmp
        result, found = self.doFindMedianSortedArrays(nums1, nums2)
        if found:
            return result
        result, found = self.doFindMedianSortedArrays(nums2, nums1)
        return result

    def doFindMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> (float, bool):
        left = 0
        right = len(nums1)
        while True:
            p = (left + right) // 2
            mid = nums1[p]
            pos = binarySearch(nums2, mid)
            left_count = p + pos
            right_count = len(nums1) - p - 1 + len(nums2) - pos
            if left_count == right_count:
                return mid, True
            elif left_count == right_count + 1:
                if pos - 1 < 0:
                    return (mid + nums1[p - 1]) / 2, True
                if p - 1 < 0:
                    return (mid + nums2[pos - 1]) / 2, True
                return (mid + (max(nums1[p - 1], nums2[pos - 1]))) / 2, True
            elif left_count + 1 == right_count:
                if pos >= len(nums2):
                    return (mid + nums1[p + 1]) / 2, True
                if p + 1 >= len(nums1):
                    return (mid + nums2[pos]) / 2, True
                return (mid + (min(nums1[p + 1], nums2[pos]))) / 2, True
            if left_count < right_count:
                left = p + 1
            else:
                right = p
            if left >= right:
                return 0.0, False

def binarySearch(nums: List[int], num: int) -> int:
    start = 0
    end = len(nums)
    while True:
        if start >= end:
            return start
        mid = (start + end) // 2
        if nums[mid] == num:
            return mid
        elif num < nums[mid]:
            end = mid
        else:
            start = mid + 1
