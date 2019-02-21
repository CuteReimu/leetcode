class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (auto x : nums) {
            a = ~b & (a ^ x);
            b = ~a & (b ^ x);
        }
        return a;
    }
};
