class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return false;
		if (nums.size() == 1)
			return nums[0] == target;
		int l = 0;
		int r = nums.size() - 1;
		if (nums[l] < nums[r])
			return binary_search(nums.begin(), nums.end(), target);
		r = findMiddle(nums, 0, nums.size() - 1);
		if (r == -1)
			return binary_search(nums.begin(), nums.end(), target);
		return binary_search(nums.begin(), nums.begin() + r, target) || binary_search(nums.begin() + r, nums.end(), target);
	}
private:
	int findMiddle(vector<int>& nums, int from, int to)
	{
		if (from == to - 1)
			return nums[from] <= nums[to] ? -1 : to;
		int r = (from + to) / 2;
		if (nums[from] >= nums[r])
		{
			int t = findMiddle(nums, from, r);
			if (t != -1) return t;
		}
		if (nums[to] <= nums[r])
		{
			int t = findMiddle(nums, r, to);
			if (t != -1) return t;
		}
		return -1;
	}
};
