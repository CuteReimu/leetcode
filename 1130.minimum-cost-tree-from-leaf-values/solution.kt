class Solution {
    fun mctFromLeafValues(arr: IntArray): Int {
        var res = 0;
        val stk = ArrayDeque<Int>()
        for (x in arr) {
            while (stk.isNotEmpty() && stk.peek() <= x) {
                val y = stk.pop()
                if (stk.isEmpty() || stk.peek() > x) {
                    res += y * x
                } else {
                    res += stk.peek() * y
                }
            }
            stk.push(x)
        }
        while (stk.size >= 2) {
            val x = stk.pop()
            res += stk.peek() * x
        }
        return res
    }
}
