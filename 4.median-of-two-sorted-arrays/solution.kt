import kotlin.math.min

class Solution {
    fun findMedianSortedArrays(nums1: IntArray, nums2: IntArray): Double {
        val totalLength = nums1.size + nums2.size
        return if (totalLength % 2 == 1) {
            val midIndex = totalLength / 2
            getKthElement(nums1, nums2, midIndex + 1).toDouble()
        } else {
            val midIndex1 = totalLength / 2 - 1
            val midIndex2 = totalLength / 2
            (getKthElement(nums1, nums2, midIndex1 + 1) + getKthElement(nums1, nums2, midIndex2 + 1)) / 2.0
        }
    }

    private fun getKthElement(nums1: IntArray, nums2: IntArray, k0: Int): Int {
        var k = k0
        var index1 = 0
        var index2 = 0
        while (true) {
            if (index1 == nums1.size)
                return nums2[index2 + k - 1]
            if (index2 == nums2.size)
                return nums1[index1 + k - 1]
            if (k == 1)
                return min(nums1[index1], nums2[index2])
            val newIndex1 = min(index1 + k / 2, nums1.size) - 1
            val newIndex2 = min(index2 + k / 2, nums2.size) - 1
            if (nums1[newIndex1] <= nums2[newIndex2]) {
                k -= (newIndex1 - index1 + 1)
                index1 = newIndex1 + 1
            } else {
                k -= (newIndex2 - index2 + 1)
                index2 = newIndex2 + 1
            }
        }
    }
}
