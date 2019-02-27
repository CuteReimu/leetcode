class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if (len == 0) return;
        k %= len;
        if (k == 0) return;
        int a = len, b = k;
        while (true) {
            if ((a %= b) == 0) break;
            swap(a, b);
        }
        for (int i = 0; i < b; i++) {
            for (int j = i; j != i + len; j += k) {
                j %= len;
                swap(nums[j], nums[i]);
            }
        }
    }
};
