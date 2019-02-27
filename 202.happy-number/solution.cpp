class Solution {
public:
    bool isHappy(int n) {
        while (n != 1) {
            int m = 0;
            while (n > 0) {
                m += (n % 10) * (n % 10);
                n /= 10;
            }
            if (m == 4) return false;
            n = m;
        }
        return true;
    }
};
