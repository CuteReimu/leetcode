class Solution {
    fun isValid(s: String): Boolean {
        val stk = StringBuilder()
        for (i in s.indices) {
            val c = s[i]
            stk.append(c)
            if (stk.length >= 3 && stk.substring(stk.length - 3) == "abc")
                stk.delete(stk.length - 3, stk.length)
        }
        return stk.isEmpty()
    }
}
