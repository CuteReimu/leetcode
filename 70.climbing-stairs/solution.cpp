class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        int p = 1, q = 2;
        for (int i = 3; i <= n; i++)
        {
            int x = p + q;
            p = q;
            q = x;
        }
        return q;
    }
};
