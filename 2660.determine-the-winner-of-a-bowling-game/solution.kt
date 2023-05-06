class Solution {
    fun isWinner(player1: IntArray, player2: IntArray): Int {
        val s1 = player1.calScore()
        val s2 = player2.calScore()
        if (s1 > s2) return 1
        if (s1 < s2) return 2
        return 0
    }
    
    private fun IntArray.calScore(): Int {
        var total = 0
        for (i in indices) total +=
            if (i >= 2 && this[i-2] == 10 || i >= 1 && this[i-1] == 10) this[i] * 2
            else this[i]
        return total
    }
}
