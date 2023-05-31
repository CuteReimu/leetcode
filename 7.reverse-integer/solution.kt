class Solution {
    fun reverse(x: Int): Int {
        if (x == 0) return 0
        var s = x.toString()
        if (x > 0) {
            s = s.reversed()
            if (Int.MAX_VALUE.toString().run {
                s.length > length || s.length == length && s > this
            }) return 0
            return s.toInt()
        } else {
            s = "-" + s.substring(1).reversed()
            if (Int.MIN_VALUE.toString().run {
                s.length > length || s.length == length && s > this
            }) return 0
            return s.toInt()
        }
    }
}
