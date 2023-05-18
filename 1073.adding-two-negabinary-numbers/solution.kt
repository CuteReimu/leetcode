class Solution {
    fun addNegabinary(arr1: IntArray, arr2: IntArray): IntArray {
        arr1.reverse()
        arr2.reverse()
        val arr3 = ArrayList<Int>()
        var i = 0
        var j = 0
        var c = 0
        while (i < arr1.size || j < arr2.size || c != 0) {
            var k = c
            c = 0
            if (i < arr1.size) k += arr1[i++]
            if (j < arr2.size) k += arr2[j++]
            while (k >= 2) {
                k -= 2
                c--
            }
            while (k < 0) {
                k += 2
                c++
            }
            arr3.add(k)
        }
        while (arr3.size > 1 && arr3.last() == 0) arr3.removeAt(arr3.size - 1)
        val arr30 = arr3.toIntArray()
        arr30.reverse()
        return arr30
    }
}
