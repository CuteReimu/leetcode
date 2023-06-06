class Solution {
    fun maxArea(height: IntArray): Int {
        var i = 0
        var j = height.size - 1
        var res = 0
        while (i < j)
            res = res.coerceAtLeast((j - i) * if (height[i] < height[j]) height[i++] else height[j--])
        return res
    }
}
