class Solution {
    fun smallestRepunitDivByK(k: Int): Int {
        var resid = 1 % k
        var len = 1
        val set = hashSetOf(resid)
        while (resid != 0) {
            resid = (resid * 10 + 1) % k
            len++
            if (resid in set) return -1
            set.add(resid)
        }
        return len
    }
}
