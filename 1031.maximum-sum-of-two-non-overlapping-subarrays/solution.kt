import kotlin.math.max

class Solution {
    fun maxSumTwoNoOverlap(nums: IntArray, firstLen: Int, secondLen: Int): Int {
        return max(help(nums, firstLen, secondLen), help(nums, secondLen, firstLen))
    }

    private fun help(nums: IntArray, firstLen: Int, secondLen: Int): Int {
        var suml = 0
        for (i in 0 until firstLen) {
            suml += nums[i]
        }
        var maxSumL = suml
        var sumr = 0
        for (i in firstLen until firstLen + secondLen) {
            sumr += nums[i]
        }
        var res = maxSumL + sumr
        var j = firstLen
        for (i in (firstLen + secondLen) until nums.size) {
            suml += nums[j] - nums[j - firstLen]
            maxSumL = max(maxSumL, suml)
            sumr += nums[i] - nums[i - secondLen]
            res = max(res, maxSumL + sumr)
            j++
        }
        return res;
    }
}
