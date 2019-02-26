class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n >= 5) {
            count += n = n / 5;
        }
        return count;
    }
};
