class Solution {
    fun largestValsFromLabels(values: IntArray, labels: IntArray, numWanted: Int, useLimit: Int): Int {
        val id = MutableList(values.size) { it }
        id.sortByDescending { values[it] }
        var ans = 0
        var choose = 0
        val cnt = HashMap<Int, Int>()
        for (i in values.indices) {
            if (choose >= numWanted) break
            val label = labels[id[i]]
            if (cnt.getOrDefault(label, 0) == useLimit)
                continue
            ++choose
            ans += values[id[i]]
            cnt[label] = cnt.getOrDefault(label, 0) + 1
        }
        return ans
    }
}
