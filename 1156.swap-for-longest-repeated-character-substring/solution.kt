class Solution {
    fun maxRepOpt1(text: String): Int {
        val count = HashMap<Char, Int>()
        for (c in text) {
            count[c] = count.getOrDefault(c, 0) + 1
        }
        var res = 0
        var i = 0
        while (i < text.length) {
            var j = i
            while (j < text.length && text[j] == text[i]) {
                j++
            }
            val curCnt = j - i

            if (curCnt < count.getOrDefault(text[i], 0) && (j < text.length || i > 0)) {
                res = maxOf(res, curCnt + 1)
            }

            var k = j + 1
            while (k < text.length && text[k] == text[i]) {
                k++
            }
            res = maxOf(res, minOf(k - i, count.getOrDefault(text[i], 0)))
            i = j
        }
        return res
    }
}
