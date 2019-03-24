class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 || K % 5 == 0) return -1;
        int tmp = 0;
        for (int i = 1; i < 1000000; i++) {
            tmp = tmp * 10 + 1;
            if (tmp % K == 0) return i;
            if (tmp > K) tmp %= K;
        }
        return -1;
    }
};
