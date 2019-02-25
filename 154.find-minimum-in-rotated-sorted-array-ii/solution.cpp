class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0, end = nums.size() - 1;
        while (true) {
            if (end == begin)
                return nums[begin];
            if (end - begin == 1)
                return min(nums[begin], nums[end]);
            int mid = (begin + end) / 2;
            if (nums[begin] == nums[mid] && nums[mid] == nums[end]) {
                begin++;
                end--;
            } else if (nums[begin] > nums[mid]) {
                end = mid;
            } else if (nums[mid] > nums[end]) {
                begin = mid;
            } else {
                return nums[begin];
            }
        }
    }
};
