class Solution {
    fun oddString(words: Array<String>): String {
        fun oddString(s: String): List<Int> =
            (0 until s.length-1).map { s[it + 1] - s[it] }
        
        val diff0 = oddString(words[0])
        val diff1 = oddString(words[1])
        if (diff0 == diff1) {
            for (i in 2 until words.size) {
                if (diff0 != oddString(words[i])) {
                    return words[i]
                }
            }
        }
        return if (diff0 == oddString(words[2])) words[1] else words[0]
    }
}
