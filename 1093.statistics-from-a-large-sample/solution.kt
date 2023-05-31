class Solution {
    fun sampleStats(count: IntArray): DoubleArray {
        val n = count.size
        val total = count.sum()
        val mean: Double
        var median = 0.0
        var minnum = 256
        var maxnum = 0
        var mode = 0
        val left = (total + 1) / 2
        val right = (total + 2) / 2
        var cnt = 0
        var maxfreq = 0
        var sum: Long = 0
        for (i in 0 until n) {
            sum += count[i].toLong() * i
            if (count[i] > maxfreq) {
                maxfreq = count[i]
                mode = i
            }
            if (count[i] > 0) {
                if (minnum == 256) {
                    minnum = i
                }
                maxnum = i
            }
            if (cnt < right && cnt + count[i] >= right) {
                median += i.toDouble()
            }
            if (cnt < left && cnt + count[i] >= left) {
                median += i.toDouble()
            }
            cnt += count[i]
        }
        mean = sum.toDouble() / total
        median /= 2.0
        return doubleArrayOf(minnum.toDouble(), maxnum.toDouble(), mean, median, mode.toDouble())
    }
}
