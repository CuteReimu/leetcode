class Solution {
    fun minHeightShelves(books: Array<IntArray>, shelfWidth: Int): Int {
        val heights = IntArray(books.size + 1)
        for (i in books.indices) {
            var height = 99999999
            var h = 0
            var w = 0
            for (j in i downTo 0) {
                w += books[j][0]
                if (w > shelfWidth) break
                h = books[j][1].coerceAtLeast(h)
                height = (heights[j] + h).coerceAtMost(height)
            }
            heights[i + 1] = height
        }
        return heights.last()
    }
}
