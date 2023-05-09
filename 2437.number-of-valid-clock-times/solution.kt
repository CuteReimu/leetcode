class Solution {
    fun countTime(time: String): Int {
        val a =
            if (time[0] != '?') 1
            else when (time[1]) {
                '?' -> 1
                '0', '1', '2', '3' -> 3
                else -> 2
            }
        val b =
            if (time[1] != '?') 1
            else when (time[0]) {
                '?' -> 24
                '2' -> 4
                else -> 10
            }
        val c =
            if (time[3] == '?') 6
            else 1
        val d =
            if (time[4] == '?') 10
            else 1
        return a * b * c * d
    }
}
