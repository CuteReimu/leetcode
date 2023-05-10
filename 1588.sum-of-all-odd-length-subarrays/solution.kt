class Solution {
    fun sumOddLengthSubarrays(arr: IntArray): Int {
        var sum = 0
        for (len in 1..arr.size) {
            if (len % 2 == 0) continue
            var i = 0
            var j = len-1
            var s = 0
            for (k in i..j) s += arr[k]
            sum += s
            while (true) {
                if (++j >= arr.size) break
                s = s - arr[i++] + arr[j]
                sum += s
            }
        }
        return sum
    }
}
