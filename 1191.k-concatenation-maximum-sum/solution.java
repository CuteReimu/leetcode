class Solution {
    public int kConcatenationMaxSum(int[] arr, int k) {
        if (k == 1) return maxSum(arr);
        if (k == 2) return maxSum(generateDoubleArray(arr));
        int sum2 = sum(arr);
        if (sum2 <= 0) return maxSum(generateDoubleArray(arr));
        long sum = (long) sum2 * (k - 2) + maxSum(generateDoubleArray(arr));
        return (int) (sum % 1000000007);
    }

    public int[] generateDoubleArray(int[] arr) {
        int[] result = new int[arr.length * 2];
        System.arraycopy(arr, 0, result, 0, arr.length);
        System.arraycopy(arr, 0, result, arr.length, arr.length);
        return result;
    }

    private int sum(int[] arr) {
        int sum = 0;
        for (int i : arr)
            sum += i;
        return sum;
    }

    private int maxSum(int[] arr) {
        int sum = 0;
        int maxSum = 0;
        for (int i : arr) {
            sum += i;
            if (sum < 0) {
                sum = 0;
                continue;
            }
            maxSum = sum > maxSum ? sum : maxSum;
        }
        return maxSum;
    }
}
