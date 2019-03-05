class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int sum = 0;
		int i = 0;
		int j = 0;
		int len = nums.size();
		int minval = INT_MAX;
		while (true) {
			if (sum < s) {
				if (j == len) break;
				sum += nums[j++];
			} else {
				minval = min(minval, j - i);
				sum -= nums[i++];
			}
		}
		return minval == INT_MAX ? 0 : minval;
	}
};
