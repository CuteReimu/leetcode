class Solution {
    fun myPow(x: Double, n: Int): Double {
        if (n == 0) return 1.0
        val m = HashMap<Int, Double>()
        fun pow(n: Int): Double {
            if (n == -1) return 1/x
            if (n == 1) return x
            val vn = m[n]
            if (vn != null) return vn
            val v_1 = m[n-1]
            if (v_1 != null) return v_1 * x
            val v = pow(n/2) * pow(n-n/2)
            m[n] = v
            return v
        }
        return pow(n)
    }
}
