import java.util.PriorityQueue

class Solution {
    fun rearrangeBarcodes(barcodes: IntArray): IntArray {
        val counts = HashMap<Int, Int>()
        for (i in barcodes)
            counts.compute(i) { _, v -> (v ?: 0) + 1 }
        val countsVal = PriorityQueue<Pair<Int, Int>> { o1, o2 -> o2.second.compareTo(o1.second) }
        for ((b, c) in counts)
            countsVal.add(b to c)
        var lastVal = 0
        return IntArray(barcodes.size) { _ ->
            val it = countsVal.iterator()
            var pair = it.next()
            if (pair.first == lastVal)
                pair = it.next()
            it.remove()
            if (pair.second > 1)
                countsVal.add(pair.first to pair.second - 1)
            lastVal = pair.first
            lastVal
        }
    }
}
