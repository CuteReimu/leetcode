/**
 * The rand7() API is already defined in the parent class SolBase.
 * fun rand7(): Int {}
 * @return a random integer in the range 1 to 7
 */
class Solution : SolBase() {
    fun rand10(): Int {
        var a: Int
        while (true) {
            a = rand7()
            if (a <= 6) {
                a %= 2
                break
            }
        }

        var b: Int
        while (true) {
            b = rand7()
            if (b <= 5) break
        }

        return a * 5 + b
    }
}
