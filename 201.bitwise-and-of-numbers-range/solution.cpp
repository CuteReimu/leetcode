class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == 0 || m > n) return 0;
        int i = 30;
        for (; n >> i == 0; i--);
        if (m < 1 << i) return 0;
        return 1 << i | rangeBitwiseAnd(m ^ 1 << i, n ^ 1 << i);
    }
};
