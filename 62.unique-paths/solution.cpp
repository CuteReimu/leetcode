class Solution {
public:
    int uniquePaths(int m, int n) {
        int min = m < n ? m - 1 : n - 1;
        long result = 1;
        int sum = m + n - 1;
        for (int i = 1; i <= min; i++)
        {
            result *= sum - i;
            result /= i;
        }
        return (int)result;
    }
};
