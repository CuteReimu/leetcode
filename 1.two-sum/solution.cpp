class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> cache;
		vector<int> result;
		int len = nums.size();
		for (int i = 0; i < len; i++)
		{
			auto addResult = cache.insert(make_pair(nums[i], i));
			if (!addResult.second && addResult.first->first * 2 == target)
			{
				result.push_back(addResult.first->second);
				result.push_back(i);
				return result;
			}
		}
		auto it1 = cache.begin();
		auto it2 = cache.rbegin();
		while (it1 != it2.base())
		{
			int sum = it1->first + it2->first;
			if (sum == target)
			{
				result.push_back(it1->second);
				result.push_back(it2->second);
				break;
			} else if (sum > target)
				it2++;
			else
				it1++;
		}
		return result;
	}
};
