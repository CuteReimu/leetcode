class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        int maj = nums[0];
        int count = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] == maj) count++;
            else count--;
            if (count == 0) maj = nums[i + 1];
        }
        return maj;
    }
};
