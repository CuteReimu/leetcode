class Solution {
    fun generateParenthesis(n: Int): List<String> {
        if (n == 1) return listOf("()")
        return generateParenthesis(n - 1).flatMap { s ->
            (0..s.length).map { s.replaceRange(it, it, "()") }
        }.distinct()
    }
}
