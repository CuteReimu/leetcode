class Solution {
public:
    string convertToTitle(int n) {
        if (n <= 26) return string(1, 'A' + (n - 1));
        return convertToTitle((n - 1) / 26) + (char)('A' + (n - 1) % 26);
    }
};
