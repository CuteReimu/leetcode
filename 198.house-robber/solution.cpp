class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        if (len == 1) return nums[0];
        int nono = 0, yesno = nums[0], noyes = nums[1];
        for (int i = 2; i < len; i++) {
            int nono2 = yesno;
            int yesno2 = noyes;
            int noyes2 = max(nono, yesno) + nums[i];
            nono = nono2;
            yesno = yesno2;
            noyes = noyes2;
        }
        return max(yesno, noyes);
    }
};
