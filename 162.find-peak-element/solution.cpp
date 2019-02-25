class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;
        int begin = 0, end = nums.size() - 1;
        while (true) {
            int mid = (begin + end) / 2;
            if (nums[mid] > nums[mid - 1]) {
                if (nums[mid] > nums[mid + 1]) {
                    return mid;
                } else {
                    begin = mid;
                }
            } else {
                end = mid;
            }
        }
    }
};
