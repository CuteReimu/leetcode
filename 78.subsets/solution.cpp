class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;
		int len = nums.size();
		result.reserve(pow(2, len));
		result.emplace_back();
		for (int i = 0; i < len; i++)
		{
			int len1 = result.size();
			result.insert(result.end(), result.cbegin(), result.cend());
			for (int j = 0; j < len1; j++)
				result[j].push_back(nums[i]);
		}
		return result;
	}
};
