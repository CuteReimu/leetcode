class Solution {
    public int countDigitOne(int n) {
        if (n <= 0) return 0;
        if (n < 10) return 1;
        String s = Integer.toString(n);
        int sum = 0;
        String s1 = s.substring(0, 1);
        String s2 = s.substring(1);
        if (s.charAt(0) == '1')
            sum += Integer.parseInt(s2);
        sum += countDigitOne(Integer.parseInt(s2));
        sum += (s.charAt(0) - '0') * count999(s.length() - 1) + 1;
        if (s.charAt(0) > '1')
            sum += exp10(s.length() - 1) - 1;
        return sum;
    }

    public int count999(int i) {
        if (i == 1) return 1;
        if (cache[i] != 0) return cache[i];
        return cache[i] = count999(i - 1) * 10 + exp10(i - 1);
    }

    public int exp10(int i) {
        int result = 1;
        for (; i > 0; i--) {
            result *= 10;
        }
        return result;
    }

    private int[] cache = new int[12];
}
