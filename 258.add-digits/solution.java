class Solution {
    public int addDigits(int num) {
        if (num == 0) return 0;
        int val = num % 9;
        return val == 0 ? 9 : val;
    }
}
