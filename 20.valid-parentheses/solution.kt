class Solution {
    fun isValid(s: String): Boolean {
        var stack = ArrayList<Char>()
        for (ch in s) {
            when (ch) {
                '(' -> stack.add('(')
                ')' -> if (stack.isEmpty() || '(' != stack.removeAt(stack.size - 1)) return false
                '[' -> stack.add('[')
                ']' -> if (stack.isEmpty() || '[' != stack.removeAt(stack.size - 1)) return false
                '{' -> stack.add('{')
                '}' -> if (stack.isEmpty() || '{' != stack.removeAt(stack.size - 1)) return false
            }
        }
        return stack.isEmpty()
    }
}
