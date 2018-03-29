class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		int len = nums.size();
		if (len < 4)
			return result;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < len; i++)
		{
			if (nums[i] * 4 > target)
				break;
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			for (int j = i + 1; j < len; j++)
			{
				if (nums[j] * 3 > target - nums[i])
					break;
				if (j > i + 1 && nums[j] == nums[j - 1])
					continue;
				int k = j + 1;
				int l = len - 1;
				while (k < l)
				{
					int val = nums[i] + nums[j] + nums[k] + nums[l];
					if (val == target)
					{
						result.emplace_back(4);
						vector<int> &v = result[result.size() - 1];
						v[0] = nums[i];
						v[1] = nums[j];
						v[2] = nums[k];
						v[3] = nums[l];
						while (k < len - 1 && nums[k] == nums[k + 1]) k++;
						while (l > j + 1 && nums[l] == nums[l - 1]) l--;
						k++;
						l--;
					} else if (val > target)
						l--;
					else
						k++;
				}
			}
		}
		return result;
	}
};
