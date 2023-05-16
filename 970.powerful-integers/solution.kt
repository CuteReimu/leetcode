class Solution {
    fun powerfulIntegers(x: Int, y: Int, bound: Int): List<Int> {
        val set = HashSet<Int>()
        var value1 = 1
        for (i in 0..20) {
            var value2 = 1
            for (j in 0..20) {
                val value = value1 + value2
                if (value <= bound)
                    set.add(value)
                else
                    break
                value2 *= y
            }
            if (value1 > bound)
                break
            value1 *= x
        }
        return set.toList()
    }
}
