class Solution {
    fun numOfMinutes(n: Int, headID: Int, manager: IntArray, informTime: IntArray): Int {
        val m = manager.withIndex().groupBy { it.value }
        fun time(id: Int): Int {
            var t = 0
            for (i in m[id] ?: return 0)
                t = maxOf(t, time(i.index))
            return informTime[id] + t
        }
        return time(m[-1]!!.first().index)
    }
}
