import java.util.TreeMap

class Solution {
    fun rearrangeBarcodes(barcodes: IntArray): IntArray {
        val counts = HashMap<Int, Int>()
        for (i in barcodes)
            counts.compute(i) { _, v -> (v ?: 0) + 1 }
        val countsVal = TreeMap<Int, ArrayList<Int>>(Collections.reverseOrder())
        for ((b, c) in counts)
            countsVal.getOrPut(c) { ArrayList() }.add(b)
        var lastVal = 0
        val result = IntArray(barcodes.size)
        for (i in result.indices) {
            val it = countsVal.iterator()
            var entry = it.next()
            val v = entry.value.last()
            var count = entry.key
            (if (lastVal != v) {
                entry.value.removeAt(entry.value.size - 1).also { _ ->
                    if (entry.value.isEmpty())
                        it.remove()
                    if (count > 1)
                        countsVal.getOrPut(count - 1) { ArrayList() }.add(v)
                }
            } else {
                if (entry.value.size >= 2) {
                    entry.value.removeAt(entry.value.size - 2).also { v ->
                        if (count > 1)
                            countsVal.getOrPut(count - 1) { ArrayList() }.add(v)
                    }
                } else {
                    entry = it.next()
                    count = entry.key
                    entry.value.removeAt(entry.value.size - 1).also { v ->
                        if (entry.value.isEmpty())
                            it.remove()
                        if (count > 1)
                            countsVal.getOrPut(count - 1) { ArrayList() }.add(v)
                    }
                }
            }).also { `val` ->
                lastVal = `val`
                result[i] = lastVal
            }
        }
        return result
    }
}
