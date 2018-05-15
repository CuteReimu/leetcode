class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result;
		vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), target);
		if (it == nums.end() || *it != target)
		{
			result.push_back(-1);
			result.push_back(-1);
		} else
		{
			result.push_back(it - nums.begin());
			vector<int>::iterator it2 = upper_bound(nums.begin(), nums.end(), target);
			result.push_back(it2 - nums.begin() - 1);
		}
		return result;
	}
};
