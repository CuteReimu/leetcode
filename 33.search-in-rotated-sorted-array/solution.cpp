class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return -1;
		if (nums.size() == 1)
			return -(nums[0] != target);
		int l = 0;
		int r = nums.size() - 1;
		if (nums[l] < nums[r])
		{
			vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), target);
			return it == nums.end() || *it != target ? -1 : it - nums.begin();
		}
		while (l != r - 1)
		{
			int i = (l + r) / 2;
			if (nums[l] < nums[i]) l = i;
			else r = i;
		}
		vector<int>::iterator it = lower_bound(nums.begin(), nums.begin() + r, target);
		int index = it - nums.begin();
		if (index != r && *it == target)
			return index;
		vector<int>::iterator it2 = lower_bound(nums.begin() + r, nums.end(), target);
		return it2 == nums.end() || *it2 != target ? -1 : it2 - nums.begin();
	}
};
