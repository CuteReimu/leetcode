class Solution {
    public int[] sumZero(int n) {
        int[] result = new int[n];
        for (int i = 0; i < n >> 1 << 1; i++) {
            result[i] = (i & 1) == 0 ? (i / 2 + 1) : -(i / 2 + 1);
        }
        if ((n & 1) != 0) {
            result[n - 1] = 0;
        }
        return result;
    }
}
