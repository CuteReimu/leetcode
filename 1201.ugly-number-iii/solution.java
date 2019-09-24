import java.math.BigInteger;
class Solution {
    public int nthUglyNumber(int n, int a, int b, int c) {
        int min = 0, max = 2000000001;
        while (min < max) {
            int now = (int) (((long) min + (long) max) / 2);
            int nowN = cal(now, a, b, c);
            if (nowN == n) {
                if (cal(now - 1, a, b, c) < nowN) return now;
                nowN++;
            }
            if (nowN > n) {
                max = now - 1;
            } else {
                min = now + 1;
            }
        }
        return min;
    }

    private int cal(int value, int a, int b, int c) {
        return value / a + value / b + value / c
                - (int) (value / leastCommonMultiple(a, b).longValue())
                - (int) (value / leastCommonMultiple(b, c).longValue())
                - (int) (value / leastCommonMultiple(c, a).longValue())
                + (BigInteger.valueOf(value).divide(leastCommonMultiple(a, b, c)).intValue());
    }

    private BigInteger leastCommonMultiple(long a, long b) {
        long[] arr = {a, b};
        Arrays.sort(arr);
        long mod = arr[1] % arr[0];
        while (mod != 0) {
            arr[1] = mod;
            Arrays.sort(arr);
            mod = arr[1] % arr[0];
        }
        return BigInteger.valueOf(a).multiply(BigInteger.valueOf(b)).divide(BigInteger.valueOf(arr[0]));
    }

    private BigInteger leastCommonMultiple(int a, int b, int c) {
        return leastCommonMultiple(leastCommonMultiple(a, b).longValue(), c);
    }
}
