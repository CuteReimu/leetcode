class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int last = 0, len = nums.size();
        int maxVal = INT_MIN;
        for (int i = 0; i < len; i++) {
            if (nums[i] == 0) {
                maxVal = max(maxVal, 0);
                if (i > last) {
                    maxVal = max(maxVal, maxProduct(nums, last, i));
                }
                last = i + 1;
            }
        }
        if (len > last) maxVal = max(maxVal, maxProduct(nums, last, len));
        return maxVal;
    }
private:
    int maxProduct(vector<int>& nums, int begin, int end) {
		if (end - begin == 1) return nums[begin];
        int negativeCount = 0;
        for (int i = begin; i < end; i++) {
            if (nums[i] < 0) negativeCount++;
        }
        if (negativeCount % 2 == 0) {
            int result = 1;
            for (int i = begin; i < end; i++) {
                result *= nums[i];
            }
            return result;
        } else {
            int result1 = INT_MIN, result2 = INT_MIN, found = 0;
            for (int i = begin; i < end; i++) {
                if (found > 0) result2 = result2 == INT_MIN ? nums[i] : result2 * nums[i];
                if (nums[i] < 0) found++;
                if (found < negativeCount) result1 = result1 == INT_MIN ? nums[i] : result1 * nums[i];
            }
            return max(result1, result2);
        }
    }
};
