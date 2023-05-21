class Solution {
    fun storeWater(bucket: IntArray, vat: IntArray): Int {
        val pq = PriorityQueue<IndexedValue<Int>> { a, b -> b.value - a.value }
        var cnt = 0
        for (i in bucket.indices) {
            if (bucket[i] == 0 && vat[i] != 0) {
                ++cnt
                ++bucket[i]
            }
            if (vat[i] > 0) {
                pq.offer(IndexedValue(i, (vat[i] - 1) / bucket[i] + 1))
            }
        }
        if (pq.isEmpty())
            return 0
        var res = Int.MAX_VALUE
        while (cnt < res) {
            val arr = pq.poll()
            val v = arr.value
            val i = arr.index
            res = minOf(res, cnt + v)
            if (v == 1)
                break
            val t = (vat[i] + v - 2) / (v - 1)
            cnt += t - bucket[i]
            bucket[i] = t
            pq.offer(IndexedValue(i, (vat[i] - 1) / bucket[i] + 1))
        }
        return res
    }
}
