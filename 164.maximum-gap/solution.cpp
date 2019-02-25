class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return 0;
        vector<int> vec1, vec2;
        for (int i = 0; i < 31; i++) {
            int x = 1 << i;
            vec1.clear();
            vec2.clear();
            for (int j = 0; j < len; j++) {
                if ((nums[j] & x) == 0) vec1.push_back(nums[j]);
                else vec2.push_back(nums[j]);
            }
            nums.clear();
            nums.insert(nums.end(), vec1.begin(), vec1.end());
            nums.insert(nums.end(), vec2.begin(), vec2.end());
        }
        int result = 0;
        for (int i = 1; i < len; i++) {
            result = max(result, nums[i] - nums[i - 1]);
        }
        return result;
    }
};
