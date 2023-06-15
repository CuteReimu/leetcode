class Solution {
    fun canMakePaliQueries(s: String, queries: Array<IntArray>): List<Boolean> {
        var pre = 0
        val count = IntArray(s.length + 1) {
            if (it == 0) 0
            else {
                pre = pre xor (1 shl s[it - 1].toInt() - 'a'.toInt())
                pre
            }
        }
        val res = ArrayList<Boolean>()
        for (query in queries) {
            val l = query[0]
            val r = query[1]
            val k = query[2]
            var bits = 0
            var x = count[r + 1] xor count[l]
            while (x > 0) {
                x = x and x - 1
                bits++
            }
            res.add(bits <= k * 2 + 1)
        }
        return res
    }
}
