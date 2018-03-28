class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans2;
		if (nums.empty())
			return ans2;
		int *p = &*nums.begin();
		sort(p, p + nums.size());
		int len = nums.size();
		set<vector<int>> ans;
		for (int i = 0; i < len; i++)
		{
			int j = i + 1;
			int k = len - 1;
			while (j < k)
			{
				int result = nums[i] + nums[j] + nums[k];
				if (result == 0)
				{
					int arr[] = {nums[i], nums[j], nums[k]};
					ans.insert(vector<int>(arr, arr + 3));
					j++;
					k--;
				} else if (result > 0)
					k--;
				else
					j++;
			}
		}
		for (set<vector<int>>::iterator it = ans.begin(); it != ans.end(); it++)
		{
			ans2.push_back(std::move(*it));
		}
		return ans2;
	}
};
