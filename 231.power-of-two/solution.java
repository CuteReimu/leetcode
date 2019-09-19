class Solution {
    public boolean isPowerOfTwo(int n) {
        if (n == 0) return false;
        while (true) {
            if ((n & 1) == 1) {
                return n == 1;
            }
            n >>= 1;
        }
    }
}
