class Solution {
    fun miceAndCheese(reward1: IntArray, reward2: IntArray, k: Int): Int {
        if (k == 0) return reward2.sum()
        if (k == reward1.size) return reward1.sum()
        val reward12 = IntArray(reward1.size) { reward1[it] - reward2[it] }
        reward12.sortDescending()
        var sum = reward2.sum()
        for (i in 0 until k)
            sum += reward12[i]
        return sum
    }
}
