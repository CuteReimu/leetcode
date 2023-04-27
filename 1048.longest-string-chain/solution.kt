import kotlin.math.max

class Solution {
    fun longestStrChain(words: Array<String>): Int {
        val cnt = HashMap<String, Int>()
        words.sortBy { it.length }
        var res = 0
        for (word in words) {
            cnt[word] = 1
            for (i in word.indices) {
                val prev = word.substring(0, i) + word.substring(i + 1)
                if (cnt.containsKey(prev)) {
                    cnt[word] = max(cnt[word]!!, cnt[prev]!! + 1)
                }
            }
            res = max(res, cnt[word]!!)
        }
        return res
    }
}
