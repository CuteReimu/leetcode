class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1;
        long long sum = 0;
        while (true) {
            sum += i;
            if (sum > n) break;
            i++;
        }
        return --i;
    }
};
